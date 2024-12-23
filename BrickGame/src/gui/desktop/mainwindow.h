#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "exit.h"
#include "snake.h"
#include "tetris.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_exit_clicked();
  void on_pushButton_tetris_clicked();
  void on_pushButton_snake_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
