#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QByteArray>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QLabel>
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QStatusBar>
#include <QString>
#include <QTimer>
#include <QVector3D>
#include <iostream>
#include <set>
#include <utility>  // Для std::pair
#include <vector>

////////////// MOUSE
#include <QMouseEvent>
#include <QWheelEvent>
// #include <QQuaternion>

////////////// MOUSE
#include "affine_transform.h"
#include "parser.h"

class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit MyOpenGLWidget(QWidget *parent = nullptr);
  ~MyOpenGLWidget() override;
  void setStatusBar(QStatusBar *statusBar);
  void setEulerLabels(QLabel *lx, QLabel *ly, QLabel *lz);
  void setBackgroundColor(float red, float green, float blue);
  void setEdgeColor(float red, float green, float blue);
  void setVertexColor(float red, float green, float blue);
  double bg_red = 51, bg_green = 51, bg_blue = 51;
  double edge_red = 255, edge_green = 255, edge_blue = 0;
  double vertex_red = 255, vertex_green = 0, vertex_blue = 0;

  // Режимы отрисовки
  int drawEdges = 1;  // выбора отрисовки рёбра/грани
  int drawVertices = 0;   // отрисовка вершин
  bool drawFace = false;  // отрисовка граней
  bool isPerspecProj = true;  // перспективная/ортогональная проекция
  bool isAutoRotating = false;

  float radiusPoint = 8.0f;  // радиус вспомогательных точек
  float lineWidth = 1.0f;  // толщина линий

  void setEnableButtonsFunction(
      std::function<void()> enableButtonsFunc);  //мето для получения указателя
                                                 //на функцию класса MainWindow

  ////////////// MOUSE
  void mousePressEvent(QMouseEvent *event) override;  //нажатие клавишим мыши
  void mouseMoveEvent(QMouseEvent *event) override;  //движение мыши
  void wheelEvent(QWheelEvent *event) override;  //скролл колесика

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

 private:
  bool isLoadObj = false;
  QElapsedTimer lastFrameTime;
  float rotationAngle;
  QString filePath;  // путь к файлу
  QTimer *timer;
  QStatusBar *statusBar;  // для передачи сообщений на statusBar
  QLabel *lx, *ly, *lz;     // Labels Euler angels
  QVector3D localPointObj;  // для обратного переноса
  bool first_iter_done;

  ////////////// MOUSE
  QVector2D m_mousePosition;  //поворот мышью

  // Принудетельное обновление строки статуса
  bool forceUpdateStatusBar = false;
  QString filePathCopy;  // путь к файлу copy

  // данные объектов openGL
  GLfloat *vertices = nullptr;             // вершины
  std::vector<std::vector<int>> faces;     // грани
  std::vector<int> triangles;              // треугольники
  std::vector<std::pair<int, int>> edges;  // рёбра
  int vertexCount;  // кол-во данных о вершинах

  void convertFacesToTriangles();
  void extractEdgesFromFaces();
  void clearData();
  int parser(char *filePath);
  void drawWorldAxes();
  void rotationWithQt();
  void lightInIt();
  void localPointCalc(float distance, int axis);
  void drawObjectAxes();  // тестовый
  void showMessageStatusBar();

  // NEW CPP
  void prepareData(s21::Parser *parser);
  void printAllData(s21::Parser *parser);

  std::function<void()> enableButtonsFunc;  //функция переданная в указателе из
                                            // MainWindow для включения кнопок

 public:
  QVector3D EulerAxis;  // повороты Эйлера
  void eulerAxisControl(float rot, int axis);
  void eulerAxisInit();
  void eulerAxisPrintLabels();

 public slots:
  void toggleAutoRotation();
  void toggleDrawMode();
  void openFileObj(bool openFileDialog);
  void affineRotation(bool direction, int axis);
  void affineTranslation(bool direction, int axis);
  void affineScale(bool direction);
  void switchisPerspecProj();
  void switchDashedLine();
  void switchDrawVerices();
  void switchRadiusPoint(bool dir);
  void switchSizeLine(bool dir);

  void affineRotationMouse(float deltaBase, int axis);
};

#endif  // MYOPENGLWIDGET_H