#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QSettings>

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
  void disableButtons();
  void enableButtons();

 private slots:
  void on_pushButton_BMP_clicked();

  void on_pushButton_JPEG_clicked();

  void on_pushButton_gif_clicked();

  void createGif(QString fileName);

  void on_pushButton_bcgGrey_clicked();

  void on_pushButton_bcgWhite_clicked();

  void on_pushButton_bcgGreen_clicked();

  void on_pushButton_bcgPink_clicked();

  void on_pushButton_bcgBrown_clicked();

  void on_pushButton_bcgYellow_clicked();

  void on_pushButton_bcgPurple_clicked();

  void on_pushButton_bcgBlack_clicked();

  void on_pushButton_bcgBlue_clicked();

  void on_pushButton_bcgOrange_clicked();

  void on_pushButton_edgeGrey_clicked();

  void on_pushButton_edgeWhite_clicked();

  void on_pushButton_edgeGreen_clicked();

  void on_pushButton_edgePink_clicked();

  void on_pushButton_edgeBrown_clicked();

  void on_pushButton_edgeYellow_clicked();

  void on_pushButton_edgePurple_clicked();

  void on_pushButton_edgeBlack_clicked();

  void on_pushButton_edgeBlue_clicked();

  void on_pushButton_edgeOrange_clicked();

  void on_pushButton_vertexGrey_clicked();

  void on_pushButton_vertexWhite_clicked();

  void on_pushButton_vertexGreen_clicked();

  void on_pushButton_vertexPink_clicked();

  void on_pushButton_vertexBrown_clicked();

  void on_pushButton_vertexYellow_clicked();

  void on_pushButton_vertexPurple_clicked();

  void on_pushButton_vertexBlack_clicked();

  void on_pushButton_vertexBlue_clicked();

  void on_pushButton_vertexOrange_clicked();

 private:
  Ui::MainWindow *ui;
  QSettings *settings;
  void writeSettings();
  void readSettings();
};
#endif  // MAINWINDOW_H
