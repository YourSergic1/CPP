#ifndef TETRIS_H
#define TETRIS_H

#include <QDialog>
#include <QKeyEvent>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <iostream>

#include "../../brick_game/tetris/backend_t.h"
#include "../../brick_game/tetris/defines_t.h"
#include "exit.h"
#include "ui_tetris.h"

namespace Ui {
class Tetris;
}

class Tetris : public QDialog {
  Q_OBJECT

 public:
  explicit Tetris(QWidget *parent = nullptr);
  ~Tetris();

 private:
  Ui::Tetris *ui;
  current_figure figure;
  GameInfo_t game;
  QTimer *timer;
  bool in_game;

 protected:
  void paintEvent(QPaintEvent *) override;
  void update_paint(void);
  void keyPressEvent(QKeyEvent *e);
};

#endif  // TETRIS_H
