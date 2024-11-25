#ifndef SNAKE_H
#define SNAKE_H

#include <QDialog>
#include <QKeyEvent>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <iostream>

#include "../../brick_game/snake/backend_s.hpp"
#include "exit.h"
#include "ui_snake.h"

namespace Ui {
class Snake;
}

class Snake : public QDialog {
  Q_OBJECT

 public:
  explicit Snake(QWidget *parent = nullptr);
  ~Snake();

 private:
  Ui::Snake *ui;
  s21::game game_main;
  QTimer *timer;

 protected:
  void paintEvent(QPaintEvent *) override;
  void update_paint(void);
  void keyPressEvent(QKeyEvent *e);
};

#endif  // SNAKE_H
