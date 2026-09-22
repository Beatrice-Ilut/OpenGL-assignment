#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>

/**
 * @brief Represents a single vertex with coordinates and an rgb color.
 */
struct Vertex {
  QVector3D coords;
  QVector3D color;

  Vertex() = default;
  Vertex(QVector3D coords, QVector3D color) : coords(coords), color(color) {}
};

#endif  // VERTEX_H
