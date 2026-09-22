#include "mainwindow.h"

#include "shadingmode.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow Constructs a new main window.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow Destructor.
 */
MainWindow::~MainWindow() { delete ui; }

// --- Functions that listen for widget events
// Forwards to MainView

/**
 * @brief MainWindow::on_ResetRotationButton_clicked Resets the rotation.
 * @param checked Unused.
 */
void MainWindow::on_ResetRotationButton_clicked(bool checked) {
  Q_UNUSED(checked)
  ui->RotationDialX->setValue(0);
  ui->RotationDialY->setValue(0);
  ui->RotationDialZ->setValue(0);
  ui->mainView->setRotation(0, 0, 0);
}

/**
 * @brief MainWindow::on_RotationDialX_sliderMoved Updates the number of degrees
 * of rotation in the x direction.
 * @param value Unused.
 */
void MainWindow::on_RotationDialX_valueChanged(int value) {
  ui->mainView->setRotation(value, ui->RotationDialY->value(),
                            ui->RotationDialZ->value());
}

/**
 * @brief MainWindow::on_RotationDialY_sliderMoved Updates the number of degrees
 * of rotation in the y direction.
 * @param value Unused.
 */
void MainWindow::on_RotationDialY_valueChanged(int value) {
  ui->mainView->setRotation(ui->RotationDialX->value(), value,
                            ui->RotationDialZ->value());
}

/**
 * @brief MainWindow::on_RotationDialZ_sliderMoved Updates the number of degrees
 * of rotation in the z direction.
 * @param value Unused.
 */
void MainWindow::on_RotationDialZ_valueChanged(int value) {
  ui->mainView->setRotation(ui->RotationDialX->value(),
                            ui->RotationDialY->value(), value);
}

/**
 * @brief MainWindow::on_ResetScaleButton_clicked Resets the scale factor.
 * @param checked Unused.
 */
void MainWindow::on_ResetScaleButton_clicked(bool checked) {
  Q_UNUSED(checked)
  ui->ScaleSlider->setValue(100);
  ui->mainView->setScale(1.0);
}

/**
 * @brief MainWindow::on_ScaleSlider_sliderMoved Updates the scale value.
 * @param value The new scale value.
 */
void MainWindow::on_ScaleSlider_valueChanged(int value) {
  ui->mainView->setScale(value / 100.0);
}

/**
 * @brief MainWindow::on_PhongButton_toggled Changes the shading mode to Phong
 * shading.
 * @param checked Unused.
 */
void MainWindow::on_PhongButton_toggled(bool checked) {
  if (checked) {
    ui->mainView->setShadingMode(ShadingMode::PHONG);
    ui->mainView->update();
  }
}

/**
 * @brief MainWindow::on_NormalButton_toggled Changes the shading mode to Normal
 * shading.
 * @param checked Unused.
 */
void MainWindow::on_NormalButton_toggled(bool checked) {
  if (checked) {
    ui->mainView->setShadingMode(ShadingMode::NORMAL);
    ui->mainView->update();
  }
}

/**
 * @brief MainWindow::on_GouraudButton_toggled Changes the shading mode to
 * Gouraud shading.
 * @param checked Unused.
 */
void MainWindow::on_GouraudButton_toggled(bool checked) {
  if (checked) {
    ui->mainView->setShadingMode(ShadingMode::GOURAUD);
    ui->mainView->update();
  }
}

/**
 * @brief MainWindow::renderToFile Used to render the frame buffer to the file.
 * DO NOT REMOVE OR MODIFY!
 */
void MainWindow::renderToFile() {
  QImage image = ui->mainView->grabFramebuffer();
  image.save("framebuffer_contents.png", "PNG",
             100);  // Save using the best quality
}
