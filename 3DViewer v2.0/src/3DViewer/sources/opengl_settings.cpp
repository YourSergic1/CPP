///////////////////////////////////////////
// Настройки отображения OpenGL          //
///////////////////////////////////////////

#include "../headers/myopenglwidget.h"

// Выбор между проекциями
void MyOpenGLWidget::switchisPerspecProj() {
  isPerspecProj = !isPerspecProj;
  update();
}

// Штриховая линия
void MyOpenGLWidget::switchDashedLine() {
  if (drawEdges == 0)
    drawEdges = 1;
  else if (drawEdges == 1)
    drawEdges = 2;
  else if (drawEdges == 2)
    drawEdges = 0;
  update();
}

// Рисовать точки
void MyOpenGLWidget::switchDrawVerices() {
  if (drawVertices == 0)
    drawVertices = 1;
  else if (drawVertices == 1)
    drawVertices = 2;
  else if (drawVertices == 2)
    drawVertices = 0;
  update();
}

// Размер точек
void MyOpenGLWidget::switchRadiusPoint(bool dir) {
  if (dir) {
    radiusPoint += 1.0f;
  } else {
    radiusPoint -= 1.0f;
  }
  update();
}

void MyOpenGLWidget::switchSizeLine(bool dir) {
  if (dir) {
    lineWidth += 1.0f;
  } else {
    lineWidth -= 1.0f;
  }
  update();
}
