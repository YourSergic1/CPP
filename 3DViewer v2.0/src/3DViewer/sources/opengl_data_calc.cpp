////////////////////////////////////////////////
// Тут вычисляются данные для 3D объектов     //
// Рёбра, треугольники, вызываются методы Си, //
// связанные с трансформациями                //
////////////////////////////////////////////////

#include <QMatrix4x4>
#include <iostream>
#include <set>

#include "../headers/affine_transform.h"
#include "../headers/myopenglwidget.h"
#include "../headers/parser.h"

// очистка данных obj
void MyOpenGLWidget::clearData() {
  vertices = nullptr;
  faces.clear();
  triangles.clear();
  edges.clear();
}

void MyOpenGLWidget::prepareData(s21::Parser *parser) {
  clearData();

  vertices = new GLfloat[parser->dataV.size()];
  // Копирование данных из вектора dataV в массив vertices
  std::copy(parser->dataV.begin(), parser->dataV.end(), vertices);

  for (int i = 0; i < parser->sumF; ++i) {
    std::vector<int> faceVerticesTmp(parser->dataF[i].begin(),
                                     parser->dataF[i].end());
    faces.push_back(faceVerticesTmp);
  }
  convertFacesToTriangles();
  extractEdgesFromFaces();
  vertexCount = parser->sumV;
}
void MyOpenGLWidget::printAllData(s21::Parser *parser) {
  ////////// Вывод faces
  std::cout << "faces: " << std::endl;
  for (const auto &face : faces) {
    for (int val : face) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  ////////// Вывод triangles
  std::cout << "triangles: " << std::endl;
  for (int val : triangles) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  ////////// Вывод edge
  std::cout << "edge: " << std::endl;
  for (const auto &edge : edges) {
    std::cout << "(" << edge.first << ", " << edge.second << ") ";
  }
  std::cout << std::endl;
  std::cout << "vertexCount: " << vertexCount << std::endl;
  std::cout << "в парсере Вершин = " << parser->sumV << std::endl;
  std::cout << "в парсере Поверхностей = " << parser->sumF << std::endl;
}

// Вычисляет треугольники из поверхностей
void MyOpenGLWidget::convertFacesToTriangles() {
  for (const auto &face : faces) {
    if (face.size() == 4) {
      // Разбиваем грань на два треугольника
      triangles.push_back(face[0] - 1);  // Вершина 1 (индекс для OpenGL)
      triangles.push_back(face[1] - 1);  // Вершина 2
      triangles.push_back(face[2] - 1);  // Вершина 3

      triangles.push_back(face[0] - 1);  // Вершина 1
      triangles.push_back(face[2] - 1);  // Вершина 3
      triangles.push_back(face[3] - 1);  // Вершина 4
    } else if (face.size() == 3) {
      triangles.push_back(face[0] - 1);  // Вершина 1
      triangles.push_back(face[1] - 1);  // Вершина 2
      triangles.push_back(face[2] - 1);  // Вершина 3
    }
  }
}

// Вычисляет рёбра из поверхностей, для каркасного режима
void MyOpenGLWidget::extractEdgesFromFaces() {
  std::set<std::pair<int, int>> edgeSet;

  for (const auto &face : faces) {
    for (size_t i = 0; i < face.size(); ++i) {
      int v1 = face[i] - 1;  // Корректируем индекс для OpenGL
      int v2 = face[(i + 1) % face.size()] - 1;  // Следующая вершина

      if (v1 > v2) {
        std::swap(v1, v2);
      }
      edgeSet.insert({v1, v2});  // Добавляем ребро в множество
    }
  }
  // Переносим уникальные рёбра в вектор
  edges.assign(edgeSet.begin(), edgeSet.end());
}

// MOUSE
// Аффиново вращение v2 (углы Эйлера)
// direction - направление поворота
void MyOpenGLWidget::affineRotationMouse(float deltaBase, int axis) {
  float speed = 0.25f;
  float current_x = EulerAxis.x();
  float current_y = EulerAxis.y();
  float current_z = EulerAxis.z();
  float inverse_x = -current_x;
  float inverse_y = -current_y;
  float inverse_z = -current_z;
  float new_x = current_x;
  float new_y = current_y;
  float new_z = current_z;

  // if (!direction) {
  //   delta *= -1.0f;
  // }

  speed *= deltaBase;

  switch (axis) {
    case 1:
      // изменение X
      new_x += speed;
      break;
    case 2:
      // изменение Y
      new_y += speed;
      break;
    case 3:
      // изменение Z
      new_z += speed;
      break;
  }

  s21::AffineTransform transform;
  transform.setMatrixInverseTranslation(localPointObj, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);

  ////// inverse
  transform.setMatrixRotation(inverse_z, 3);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(inverse_y, 2);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(inverse_x, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);

  /////// new axis
  transform.setMatrixRotation(new_x, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(new_y, 2);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(new_z, 3);
  transform.calcDataFromMatrix(vertices, vertexCount);

  transform.setMatrixInverseTranslation(localPointObj, 0);
  transform.calcDataFromMatrix(vertices, vertexCount);

  EulerAxis.setX(new_x);
  EulerAxis.setY(new_y);
  EulerAxis.setZ(new_z);
  eulerAxisPrintLabels();
  update();
}

// Аффиново вращение v2 (углы Эйлера)
// direction - направление поворота
void MyOpenGLWidget::affineRotation(bool direction, int axis) {
  float delta = 5.0f;
  float current_x = EulerAxis.x();
  float current_y = EulerAxis.y();
  float current_z = EulerAxis.z();
  float inverse_x = -current_x;
  float inverse_y = -current_y;
  float inverse_z = -current_z;
  float new_x = current_x;
  float new_y = current_y;
  float new_z = current_z;

  if (!direction) {
    delta *= -1.0f;
  }

  switch (axis) {
    case 1:
      // изменение X
      new_x += delta;
      break;
    case 2:
      // изменение Y
      new_y += delta;
      break;
    case 3:
      // изменение Z
      new_z += delta;
      break;
  }

  s21::AffineTransform transform;
  transform.setMatrixInverseTranslation(localPointObj, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);

  ////// inverse
  transform.setMatrixRotation(inverse_z, 3);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(inverse_y, 2);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(inverse_x, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);

  /////// new axis
  transform.setMatrixRotation(new_x, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(new_y, 2);
  transform.calcDataFromMatrix(vertices, vertexCount);
  transform.setMatrixRotation(new_z, 3);
  transform.calcDataFromMatrix(vertices, vertexCount);

  transform.setMatrixInverseTranslation(localPointObj, 0);
  transform.calcDataFromMatrix(vertices, vertexCount);

  EulerAxis.setX(new_x);
  EulerAxis.setY(new_y);
  EulerAxis.setZ(new_z);
  eulerAxisPrintLabels();
  update();
}

// Аффиново масштабирование
void MyOpenGLWidget::affineScale(bool direction) {
  float scale = 1.1f;
  if (!direction) {
    scale = 0.9f;
  }
  s21::AffineTransform transform;
  transform.setMatrixInverseTranslation(localPointObj, 1);
  transform.calcDataFromMatrix(vertices, vertexCount);

  transform.setMatrixScale(scale);
  transform.calcDataFromMatrix(vertices, vertexCount);

  transform.setMatrixInverseTranslation(localPointObj, 0);
  transform.calcDataFromMatrix(vertices, vertexCount);

  update();
}

// Аффиново перемещение
void MyOpenGLWidget::affineTranslation(bool direction, int axis) {
  float distance = 0.1f;
  if (!direction) {
    distance *= -1.0f;
  }
  s21::AffineTransform transform;
  transform.setMatrixTranslation(distance, axis);
  transform.calcDataFromMatrix(vertices, vertexCount);
  localPointCalc(distance, axis);

  update();
}

// управляет углами Эйлера
void MyOpenGLWidget::eulerAxisControl(float rot, int axis) {
  GLfloat tmp;
  if (axis == 1) {
    tmp = EulerAxis.x();
    tmp += rot;
    EulerAxis.setX(tmp);
  }
  if (axis == 2) {
    tmp = EulerAxis.y();
    tmp += rot;
    EulerAxis.setY(tmp);
  }
  if (axis == 3) {
    tmp = EulerAxis.z();
    tmp += rot;
    EulerAxis.setZ(tmp);
  }
}

// обнуляет углы Ейлера
void MyOpenGLWidget::eulerAxisInit() {
  EulerAxis.setX(0.0f);
  EulerAxis.setY(0.0f);
  EulerAxis.setZ(0.0f);
}