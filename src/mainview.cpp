#include "mainview.h"

#include <QDateTime>

/**
 * @brief MainView::MainView Constructs a new main view.
 *
 * @param parent Parent widget.
 */
MainView::MainView(QWidget *parent) : QOpenGLWidget(parent) {
  qDebug() << "MainView constructor";

  connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
}

/**
 * @brief MainView::~MainView
 *
 * Destructor of MainView
 * This is the last function called, before exit of the program
 * Use this to clean up your variables, buffers etc.
 */
MainView::~MainView() {
  qDebug() << "MainView destructor";

  makeCurrent();

  destroyModelBuffers();
}

// --- OpenGL initialization

/**
 * @brief MainView::initializeGL Called upon OpenGL initialization
 * Attaches a debugger and calls other init functions.
 */
void MainView::initializeGL() {
  qDebug() << ":: Initializing OpenGL";
  initializeOpenGLFunctions();

  connect(&debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)), this,
          SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

  if (debugLogger.initialize()) {
    qDebug() << ":: Logging initialized";
    debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
  }

  QString glVersion{reinterpret_cast<const char *>(glGetString(GL_VERSION))};
  qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

  // Enable depth buffer
  glEnable(GL_DEPTH_TEST);

  // Enable backface culling
  glEnable(GL_CULL_FACE);

  // Default is GL_LESS
  glDepthFunc(GL_LEQUAL);

  // Set the color to be used by glClear. This is, effectively, the background
  // color.
  glClearColor(0.37f, 0.42f, 0.45f, 0.0f);

  createShaderProgram();
  loadMesh(":/models/cat.obj");

  // Initialize transformations
  updateProjectionTransform();
  updateModelTransforms();
}

/**
 * @brief MainView::createShaderProgram Creates a new shader program with a
 * vertex and fragment shader.
 */
void MainView::createShaderProgram() {
  // Create shader program
  shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                        ":/shaders/vertshader.glsl");
  shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                        ":/shaders/fragshader.glsl");
  shaderProgram.link();
}

/**
 * @brief MainView::loadMesh Loads a mesh from a given file. Note that only one
 * mesh can be loaded at a time.
 * @param filename Filename of where the mesh is located.
 */
void MainView::loadMesh(const QString &filename) {
  Model model(filename);
  QVector<QVector3D> meshCoords = model.getCoords();
  QVector<QVector3D> meshColors = model.getRandomColors();

  meshSize = meshCoords.size();

  // Generate VAO
  glGenVertexArrays(1, &meshVAO);
  glBindVertexArray(meshVAO);

  // Generate VBO
  glGenBuffers(1, &meshPositionVBO);
  glGenBuffers(1, &meshColorVBO);

  // Copy the vertex coordinates into the position VBO
  glBindBuffer(GL_ARRAY_BUFFER, meshPositionVBO);
  glBufferData(GL_ARRAY_BUFFER, meshCoords.size() * sizeof(QVector3D),
               meshCoords.data(), GL_STATIC_DRAW);

  // Set vertex coordinates to location 0
  // Note: glVertexAttribPointer implicitly reference the VBO currently bound to GL_ARRAY_BUFFER
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(QVector3D),
                        reinterpret_cast<GLvoid *>(0));
  glEnableVertexAttribArray(0);

  // Copy the colors into the color VBO
  glBindBuffer(GL_ARRAY_BUFFER, meshColorVBO);
  glBufferData(GL_ARRAY_BUFFER, meshColors.size() * sizeof(QVector3D),
               meshColors.data(), GL_STATIC_DRAW);

  // Set color values to location 1
  // Note: glVertexAttribPointer implicitly reference the VBO currently bound to GL_ARRAY_BUFFER
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(QVector3D),
                        reinterpret_cast<GLvoid *>(0));
  glEnableVertexAttribArray(1);

  // Generally good practice to unbind the buffers to prevent anything after
  // this from accidentally modifying it.
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

// --- OpenGL drawing

/**
 * @brief MainView::paintGL Actual function used for drawing to the screen.
 *
 */
void MainView::paintGL() {
  // Clear the screen before rendering
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shaderProgram.bind();

  // Update the uniform values. Note that it is better to only do this when the
  // matrices change, but for the sake of simplicity this was not done.
  shaderProgram.setUniformValue("modelViewTransform", meshTransform);
  shaderProgram.setUniformValue("projectionTransform", projectionTransform);

  glBindVertexArray(meshVAO);
  glDrawArrays(GL_TRIANGLES, 0, meshSize);

  shaderProgram.release();
}

/**
 * @brief MainView::resizeGL Called upon resizing of the screen.
 *
 * @param newWidth The new width of the screen in pixels.
 * @param newHeight The new height of the screen in pixels.
 */
void MainView::resizeGL(int newWidth, int newHeight) {
  Q_UNUSED(newWidth)
  Q_UNUSED(newHeight)
  updateProjectionTransform();
}

/**
 * @brief MainView::updateProjectionTransform Updates the projection transform
 * matrix taking into consideration the current aspect ratio.
 */
void MainView::updateProjectionTransform() {
  float aspectRatio =
      static_cast<float>(width()) / static_cast<float>(height());
  projectionTransform.setToIdentity();
  projectionTransform.perspective(60.0F, aspectRatio, 0.2F, 20.0F);
}

/**
 * @brief MainView::updateModelTransforms Updates the model transform matrix of
 * the mesh to reflect the current rotation and scale values.
 */
void MainView::updateModelTransforms() {
  meshTransform.setToIdentity();
  meshTransform.translate(0.0F, 0.0F, -10.0F);
  meshTransform.rotate(QQuaternion::fromEulerAngles(rotation));
  meshTransform.scale(scale);
  update();
}

/**
 * @brief MainView::destroyModelBuffers Cleans up the memory used by OpenGL.
 */
void MainView::destroyModelBuffers() {
  glDeleteBuffers(1, &meshPositionVBO);
  glDeleteBuffers(1, &meshColorVBO);
  glDeleteVertexArrays(1, &meshVAO);
}

/**
 * @brief MainView::setRotation Changes the rotation of the displayed objects.
 * @param rotateX Number of degrees to rotate around the x axis.
 * @param rotateY Number of degrees to rotate around the y axis.
 * @param rotateZ Number of degrees to rotate around the z axis.
 */
void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
  rotation = {static_cast<float>(rotateX), static_cast<float>(rotateY),
              static_cast<float>(rotateZ)};
  updateModelTransforms();
}

/**
 * @brief MainView::setScale Changes the scale of the displayed objects.
 * @param scale The new scale factor. A scale factor of 1.0 should scale the
 * mesh to its original size.
 */
void MainView::setScale(float newScale) {
  scale = newScale;
  updateModelTransforms();
}

void MainView::setShadingMode(ShadingMode shading) {
  qDebug() << "Changed shading to" << shading;
  Q_UNIMPLEMENTED();
}

/**
 * @brief MainView::onMessageLogged OpenGL logging function, do not change.
 *
 * @param Message The message to be logged.
 */
void MainView::onMessageLogged(QOpenGLDebugMessage Message) {
  qDebug() << " → Log:" << Message;
}
