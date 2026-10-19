#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>

/**
 * @brief Represents a single vertex with coordinates and xyz values for the normal.
 */
struct Vertex {
  QVector3D coords;
  QVector3D normal;
  QVector2D texCoord;

  Vertex() = default;
  Vertex(QVector3D coords, QVector3D normal, QVector2D texCoord = QVector2D())
      : coords(coords), normal(normal), texCoord(texCoord) {}
};

#endif  // VERTEX_H
