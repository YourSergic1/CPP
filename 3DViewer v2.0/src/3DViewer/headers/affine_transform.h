#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H

#include <GL/gl.h>
#include <math.h>

#include <QVector3D>
#include <array>

namespace s21 {
class AffineTransform {
 public:
  AffineTransform();
  ~AffineTransform();

  void setIdentityMatrix();
  void InitPoint3D();
  void setPoint3D(GLfloat x, GLfloat y, GLfloat z);
  void setMatrixRotation(float angle, int axis);
  void setMatrixScale(float scale);
  void setMatrixTranslation(float distance, int axis);
  void setMatrixInverseTranslation(QVector3D &localPointObj, int inverse);
  void multiplyMatrixPoint3D();
  void calcDataFromMatrix(GLfloat *vertices, int vertexCount);

  // матрица преобразований
  std::array<std::array<float, 4>, 4> matrix4x4;

  // 3d-точка (вершина)
  float Point3Dx;
  float Point3Dy;
  float Point3Dz;
};
}  // namespace s21

#endif  // AFFINE_TRANSFORM_H