#include "../headers/affine_transform.h"

namespace s21 {
// Конструктор по умолчанию
AffineTransform::AffineTransform() {
  setIdentityMatrix();
  InitPoint3D();
}

AffineTransform::~AffineTransform() {
  // Деструктор по умолчанию
}

// Инициализация вершины в нули
void AffineTransform::InitPoint3D() {
  Point3Dx = 0.0f;
  Point3Dy = 0.0f;
  Point3Dz = 0.0f;
}

// задаёт координаты вершины
void AffineTransform::setPoint3D(GLfloat x, GLfloat y, GLfloat z) {
  Point3Dx = x;
  Point3Dy = y;
  Point3Dz = z;
}

// установка матрицы в единичную
void AffineTransform::setIdentityMatrix() {
  matrix4x4 = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
}

// Матрица обратного переноса
// Перед и после вращения, смещает опорную точку объекта в центр мира.
// localPointObj - опорная точка
// inverse - направление обратного перехода
void AffineTransform::setMatrixInverseTranslation(QVector3D &localPointObj,
                                                  int inverse) {
  setIdentityMatrix();
  float xTmp = localPointObj.x();
  float yTmp = localPointObj.y();
  float zTmp = localPointObj.z();

  if (inverse) {
    xTmp *= -1;
    yTmp *= -1;
    zTmp *= -1;
  }

  matrix4x4[0][3] = xTmp;
  matrix4x4[1][3] = yTmp;
  matrix4x4[2][3] = zTmp;
}

// умножает матрицу на 3D-точку (вершину)
void AffineTransform::multiplyMatrixPoint3D() {
  float x_tmp = matrix4x4[0][0] * Point3Dx + matrix4x4[0][1] * Point3Dy +
                matrix4x4[0][2] * Point3Dz + matrix4x4[0][3];
  float y_tmp = matrix4x4[1][0] * Point3Dx + matrix4x4[1][1] * Point3Dy +
                matrix4x4[1][2] * Point3Dz + matrix4x4[1][3];
  float z_tmp = matrix4x4[2][0] * Point3Dx + matrix4x4[2][1] * Point3Dy +
                matrix4x4[2][2] * Point3Dz + matrix4x4[2][3];

  Point3Dx = x_tmp;
  Point3Dy = y_tmp;
  Point3Dz = z_tmp;
}

// Вычисление данных по матрице
// Беру оп три числа из массива точек 3D объекта и формирую Point3D
// Потом умножаю Point3D на матрицу преобразования
// Потом извлекаю данные из Point3D и возвращаю их в массив вершин
void AffineTransform::calcDataFromMatrix(GLfloat *vertices, int vertexCount) {
  for (int i = 0; i < vertexCount; i++) {
    int iv = i * 3;  // по 3 числа на вершину
    GLfloat x = vertices[iv];
    GLfloat y = vertices[iv + 1];
    GLfloat z = vertices[iv + 2];
    setPoint3D(x, y, z);
    multiplyMatrixPoint3D();
    vertices[iv] = Point3Dx;
    vertices[iv + 1] = Point3Dy;
    vertices[iv + 2] = Point3Dz;
  }
}

// задаёт матрицу масштаба
void AffineTransform::setMatrixScale(float scale) {
  setIdentityMatrix();
  matrix4x4[0][0] = scale;
  matrix4x4[1][1] = scale;
  matrix4x4[2][2] = scale;
}

// Преобразует матрицу в матрицу перемещения
// Подставляет смещение в последнюю колонку матрицы
void AffineTransform::setMatrixTranslation(float distance, int axis) {
  setIdentityMatrix();

  // Аффиново преобразование
  switch (axis) {
    case 1:
      // перемещенеи по X
      matrix4x4[0][3] = distance;
      break;
    case 2:
      // перемещенеи по Y
      matrix4x4[1][3] = distance;
      break;
    case 3:
      // перемещенеи по Z
      matrix4x4[2][3] = distance;
      break;
  }
}

// задаёт матрицу поворота
// axis - ось вращения, x y z
// angle - угол поворота в градусах
// Подставляет в нужные места матрицы нужные значения cos и sin
void AffineTransform::setMatrixRotation(float angle, int axis) {
  angle = angle * (3.14159265358979323846 / 180.f);  // в радианы

  float c = cosf(angle);
  float s = sinf(angle);

  this->setIdentityMatrix();

  // Аффиново преобразование
  switch (axis) {
    case 1:
      // поворот по X
      matrix4x4[1][1] = c;
      matrix4x4[1][2] = -s;
      matrix4x4[2][1] = s;
      matrix4x4[2][2] = c;
      break;
    case 2:
      // поворот по Y
      matrix4x4[0][0] = c;
      matrix4x4[0][2] = s;
      matrix4x4[2][0] = -s;
      matrix4x4[2][2] = c;
      break;
    case 3:
      // поворот по Z
      matrix4x4[0][0] = c;
      matrix4x4[0][1] = -s;
      matrix4x4[1][0] = s;
      matrix4x4[1][1] = c;
      break;
  }
}
}  // namespace s21