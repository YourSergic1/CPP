#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setFixedSize(350, 200);
  this->setWindowTitle("Выберите игру");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_exit_clicked() {
  EXIT w;
  ui->pushButton_snake->setEnabled(false);
  ui->pushButton_tetris->setEnabled(false);
  ui->pushButton_exit->setEnabled(false);
  w.setModal(true);
  w.exec();
  ui->pushButton_snake->setEnabled(true);
  ui->pushButton_tetris->setEnabled(true);
  ui->pushButton_exit->setEnabled(true);
}

void MainWindow::on_pushButton_tetris_clicked() {
  close();
  Tetris w;
  w.setModal(true);
  w.exec();
}

void MainWindow::on_pushButton_snake_clicked() {
  close();
  Snake w;
  w.setModal(true);
  w.exec();
}
