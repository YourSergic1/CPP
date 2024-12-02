#include "../headers/mainwindow.h"

#include "../../bin/ui_mainwindow.h"
#include "../headers/myopenglwidget.h"

extern "C" {
#include "../headers/gif.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Передаем указатель на QStatusBar в MyOpenGLWidget
  // потом можно обратиться к statusbar из openGLWidget
  ui->openGLWidget->setStatusBar(ui->statusbar);
  ui->openGLWidget->setEulerLabels(ui->label_euler_x, ui->label_euler_y,
                                   ui->label_euler_z);

  ui->openGLWidget->setEnableButtonsFunction([this]() { enableButtons(); });

  ui->openGLWidget->eulerAxisPrintLabels();

  connect(ui->pushButton_AutoRot, SIGNAL(clicked()), ui->openGLWidget,
          SLOT(toggleAutoRotation()));
  connect(ui->pushButton_modeDraw, SIGNAL(clicked()), ui->openGLWidget,
          SLOT(toggleDrawMode()));
  connect(ui->pushButton_switchisProj, SIGNAL(clicked()), ui->openGLWidget,
          SLOT(switchisPerspecProj()));
  connect(ui->pushButton_dashedLine, SIGNAL(clicked()), ui->openGLWidget,
          SLOT(switchDashedLine()));
  connect(ui->pushButton_drawVerices, SIGNAL(clicked()), ui->openGLWidget,
          SLOT(switchDrawVerices()));

  ////// Лямбда-функции (для передачи аргумента)
  connect(ui->pushButton_rot_X_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(false, 1); });
  connect(ui->pushButton_rot_X_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(true, 1); });
  connect(ui->pushButton_rot_Y_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(false, 2); });
  connect(ui->pushButton_rot_Y_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(true, 2); });
  connect(ui->pushButton_rot_Z_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(false, 3); });
  connect(ui->pushButton_rot_Z_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineRotation(true, 3); });

  connect(ui->pushButton_trans_X_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(true, 1); });
  connect(ui->pushButton_trans_X_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(false, 1); });
  connect(ui->pushButton_trans_Y_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(true, 2); });
  connect(ui->pushButton_trans_Y_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(false, 2); });
  connect(ui->pushButton_trans_Z_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(true, 3); });
  connect(ui->pushButton_trans_Z_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineTranslation(false, 3); });
  connect(ui->pushButton_scale_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineScale(true); });
  connect(ui->pushButton_scale_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->affineScale(false); });
  connect(ui->pushButton_VSize_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->switchRadiusPoint(true); });
  connect(ui->pushButton_VSize_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->switchRadiusPoint(false); });
  connect(ui->pushButton_lineSize_p, &QPushButton::clicked,
          [this]() { ui->openGLWidget->switchSizeLine(true); });
  connect(ui->pushButton_lineSize_m, &QPushButton::clicked,
          [this]() { ui->openGLWidget->switchSizeLine(false); });

  ui->statusbar->showMessage("Сообщение");

  // Меню Файл
  connect(ui->action_openFile, &QAction::triggered,
          [this]() { ui->openGLWidget->openFileObj(true); });
  connect(ui->action_saveSettings, &QAction::triggered,
          [this]() { this->writeSettings(); });
  connect(ui->action_close, &QAction::triggered,
          []() { QApplication::quit(); });

  // Установка цвета текста и фона для кнопок
  ui->pushButton_rot_X_p->setStyleSheet("color: red");
  ui->pushButton_rot_X_m->setStyleSheet("color: red");
  ui->pushButton_rot_Y_p->setStyleSheet("color: green");
  ui->pushButton_rot_Y_m->setStyleSheet("color: green");
  ui->pushButton_rot_Z_p->setStyleSheet("color: blue");
  ui->pushButton_rot_Z_m->setStyleSheet("color: blue");

  ui->pushButton_trans_X_p->setStyleSheet("color: red");
  ui->pushButton_trans_X_m->setStyleSheet("color: red");
  ui->pushButton_trans_Y_p->setStyleSheet("color: green");
  ui->pushButton_trans_Y_m->setStyleSheet("color: green");
  ui->pushButton_trans_Z_p->setStyleSheet("color: blue");
  ui->pushButton_trans_Z_m->setStyleSheet("color: blue");

  ui->pushButton_edgeGrey->setStyleSheet(
      "background-color:rgb(51,51,51);color: rgb(51,51,51)");
  ui->pushButton_edgeWhite->setStyleSheet(
      "background-color:rgb(255,255,255);color: rgb(255,255,255)");
  ui->pushButton_edgeBlack->setStyleSheet(
      "background-color:rgb(0,0,0);color: rgb(0,0,0)");
  ui->pushButton_edgeOrange->setStyleSheet(
      "background-color:rgb(245, 144, 93);color: rgb(245, 144, 93)");
  ui->pushButton_edgePurple->setStyleSheet(
      "background-color:rgb(216, 143, 242);color: rgb(216, 143, 242)");
  ui->pushButton_edgePink->setStyleSheet(
      "background-color:rgb(230, 115, 174);color: rgb(230, 115, 174)");
  ui->pushButton_edgeYellow->setStyleSheet(
      "background-color:rgb(230, 222, 115);color: rgb(230, 222, 115)");
  ui->pushButton_edgeBlue->setStyleSheet(
      "background-color:rgb(133, 202, 230);color: rgb(133, 202, 230)");
  ui->pushButton_edgeGreen->setStyleSheet(
      "background-color:rgb(133, 230, 170);color: rgb(133, 230, 170)");
  ui->pushButton_edgeBrown->setStyleSheet(
      "background-color:rgb(122, 55, 4);color: rgb(122, 55, 4)");

  ui->pushButton_vertexGrey->setStyleSheet(
      "background-color:rgb(51,51,51);color: rgb(51,51,51)");
  ui->pushButton_vertexWhite->setStyleSheet(
      "background-color:rgb(255,255,255);color: rgb(255,255,255)");
  ui->pushButton_vertexBlack->setStyleSheet(
      "background-color:rgb(0,0,0);color: rgb(0,0,0)");
  ui->pushButton_vertexOrange->setStyleSheet(
      "background-color:rgb(245, 144, 93);color: rgb(245, 144, 93)");
  ui->pushButton_vertexPurple->setStyleSheet(
      "background-color:rgb(216, 143, 242);color: rgb(216, 143, 242)");
  ui->pushButton_vertexPink->setStyleSheet(
      "background-color:rgb(230, 115, 174);color: rgb(230, 115, 174)");
  ui->pushButton_vertexYellow->setStyleSheet(
      "background-color:rgb(230, 222, 115);color: rgb(230, 222, 115)");
  ui->pushButton_vertexBlue->setStyleSheet(
      "background-color:rgb(133, 202, 230);color: rgb(133, 202, 230)");
  ui->pushButton_vertexGreen->setStyleSheet(
      "background-color:rgb(133, 230, 170);color: rgb(133, 230, 170)");
  ui->pushButton_vertexBrown->setStyleSheet(
      "background-color:rgb(122, 55, 4);color: rgb(122, 55, 4)");

  ui->pushButton_bcgGrey->setStyleSheet(
      "background-color:rgb(51,51,51);color: rgb(51,51,51)");
  ui->pushButton_bcgWhite->setStyleSheet(
      "background-color:rgb(255,255,255);color: rgb(255,255,255)");
  ui->pushButton_bcgBlack->setStyleSheet(
      "background-color:rgb(0,0,0);color: rgb(0,0,0)");
  ui->pushButton_bcgOrange->setStyleSheet(
      "background-color:rgb(245, 144, 93);color: rgb(245, 144, 93)");
  ui->pushButton_bcgPurple->setStyleSheet(
      "background-color:rgb(216, 143, 242);color: rgb(216, 143, 242)");
  ui->pushButton_bcgPink->setStyleSheet(
      "background-color:rgb(230, 115, 174);color: rgb(230, 115, 174)");
  ui->pushButton_bcgYellow->setStyleSheet(
      "background-color:rgb(230, 222, 115);color: rgb(230, 222, 115)");
  ui->pushButton_bcgBlue->setStyleSheet(
      "background-color:rgb(133, 202, 230);color: rgb(133, 202, 230)");
  ui->pushButton_bcgGreen->setStyleSheet(
      "background-color:rgb(133, 230, 170);color: rgb(133, 230, 170)");
  ui->pushButton_bcgBrown->setStyleSheet(
      "background-color:rgb(122, 55, 4);color: rgb(122, 55, 4)");

  disableButtons();

  // Устанавливаем путь для сохранения файла настроек
  QString appDirPath = QCoreApplication::applicationDirPath();
  QString settingsPath = appDirPath + "/settings";
  // Укажите полный путь к файлу настроек
  QString settingsFile = settingsPath + "/3D_Viewer.ini";
  // Создайте объект QSettings с указанным путем
  settings = new QSettings(settingsFile, QSettings::IniFormat);
  readSettings();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_BMP_clicked() {
  QDateTime current_date = QDateTime::currentDateTime();  // узнаем текущее
                                                          // время
  QString formattedTime = current_date.toString(
      "yyyy-MM-dd hh.mm.ss");  // переводим формат даты в строку
  QString name_pattern =
      "screenshots/Screen Shot " + formattedTime + ".bmp";  // создаем имя файла
  QImage img =
      ui->openGLWidget->grabFramebuffer();  // берем изображение с виджета
  img.save(name_pattern, "BMP");  // сохраняем картинку в папку
  QMessageBox::information(
      0, "BMP", "Screenshot saved successfully");  // информативное сообщение
}

void MainWindow::on_pushButton_JPEG_clicked() {
  QDateTime current_date = QDateTime::currentDateTime();  // узнаем текущее
                                                          // время
  QString formattedTime = current_date.toString(
      "yyyy-MM-dd hh.mm.ss");  // переводим формат даты в строку
  QString name_pattern = "screenshots/Screen Shot " + formattedTime +
                         ".jpeg";  // создаем имя файла
  QImage img =
      ui->openGLWidget->grabFramebuffer();  // берем изображение с виджета
  img.save(name_pattern, "JPEG");  // сохраняем картинку в папку
  QMessageBox::information(
      0, "JPEG", "Screenshot saved successfully");  // информативное сообщение
}

void MainWindow::createGif(QString fileName) {
  ui->pushButton_gif->setEnabled(false);  // отключаем возможность повторного
                                          // нажатия кнопки во время записи
  QImage img(ui->openGLWidget->grabFramebuffer()),
      img640_480;  // первый получает изображение с виджета, второй для
                   // рисования
  QPainter painter(&img);  // создоем объект для рисования на img
  QTime Time;     // таймер для зарисовки кадров
  GifWriter gif;  // объект для записи gif файла
  QByteArray array_of_filename =
      fileName.toLocal8Bit();  // преобразуем имя файла, что бы получить
                               // указатель на первый байт файла, что бы туда
                               // записать первый кадр
  const char *begin = array_of_filename.data();
  GifBegin(&gif, begin, 640, 480, 10);  // инициализация записи файла в gif,
                                        // первый кадр в begin,640*480,10fps

  for (int i = 1; i <= 50; ++i) {
    if (i % 10 == 0)
      ui->pushButton_gif->setText(QString::number(i / 10) +
                                  "s");  // меняем таймер на кнопке gif
    ui->openGLWidget->render(
        &painter);  // рендер текцщего изображения на картинку
    img640_480 =
        img.scaled(QSize(640, 480));  // изменение масштаба в нужный размер
    GifWriteFrame(&gif, img640_480.bits(), 640, 480,
                  10);  // запись текущего кадра в gif
    Time = QTime::currentTime().addMSecs(
        100);  // создаем аздержку в 100 мсек для ожидания следующей позиции
               // фигуры
    while (QTime::currentTime() < Time)
      QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
  }
  ui->pushButton_gif->setEnabled(true);  // делаем кнопку активной
  ui->pushButton_gif->setText("GIF");  // меняем надпись на кнопке обратно на
                                       // GIF
  GifEnd(&gif);  // завершаем запись gif
  QMessageBox::information(
      0, "GIF", "GIF saved successfully.");  // информативное сообщение
}

void MainWindow::on_pushButton_gif_clicked() {
  QDateTime current_date = QDateTime::currentDateTime();
  QString formattedTime = current_date.toString("yyyy-MM-dd hh.mm.ss");
  QString name_pattern = "screenshots/Screen Cast " + formattedTime + ".gif";
  createGif(name_pattern);
}

void MainWindow::on_pushButton_bcgGrey_clicked() {
  ui->openGLWidget->setBackgroundColor(51, 51, 51);
}

void MainWindow::on_pushButton_bcgWhite_clicked() {
  ui->openGLWidget->setBackgroundColor(255, 255, 255);
}

void MainWindow::on_pushButton_bcgGreen_clicked() {
  ui->openGLWidget->setBackgroundColor(133, 230, 170);
}

void MainWindow::on_pushButton_bcgPink_clicked() {
  ui->openGLWidget->setBackgroundColor(230, 115, 174);
}

void MainWindow::on_pushButton_bcgBrown_clicked() {
  ui->openGLWidget->setBackgroundColor(122, 55, 4);
}

void MainWindow::on_pushButton_bcgYellow_clicked() {
  ui->openGLWidget->setBackgroundColor(230, 222, 115);
}

void MainWindow::on_pushButton_bcgPurple_clicked() {
  ui->openGLWidget->setBackgroundColor(216, 143, 242);
}

void MainWindow::on_pushButton_bcgBlack_clicked() {
  ui->openGLWidget->setBackgroundColor(0, 0, 0);
}

void MainWindow::on_pushButton_bcgBlue_clicked() {
  ui->openGLWidget->setBackgroundColor(133, 202, 230);
}

void MainWindow::on_pushButton_bcgOrange_clicked() {
  ui->openGLWidget->setBackgroundColor(245, 144, 93);
}

void MainWindow::writeSettings() {
  settings->setValue("bg_red", ui->openGLWidget->bg_red);
  settings->setValue("bg_green", ui->openGLWidget->bg_green);
  settings->setValue("bg_blue", ui->openGLWidget->bg_blue);
  settings->setValue("edge_red", ui->openGLWidget->edge_red);
  settings->setValue("edge_green", ui->openGLWidget->edge_green);
  settings->setValue("edge_blue", ui->openGLWidget->edge_blue);
  settings->setValue("vertex_red", ui->openGLWidget->vertex_red);
  settings->setValue("vertex_green", ui->openGLWidget->vertex_green);
  settings->setValue("vertex_blue", ui->openGLWidget->vertex_blue);
  settings->setValue("isPerspecProj", ui->openGLWidget->isPerspecProj);
  settings->setValue("drawEdges", ui->openGLWidget->drawEdges);
  settings->setValue("drawVertices", ui->openGLWidget->drawVertices);
  settings->setValue("drawFace", ui->openGLWidget->drawFace);
  settings->setValue("radiusPoint", ui->openGLWidget->radiusPoint);
  settings->setValue("lineWidth", ui->openGLWidget->lineWidth);
}

void MainWindow::readSettings() {
  QStringList allKeys = settings->allKeys();
  if (!allKeys.isEmpty()) {
    ui->openGLWidget->bg_blue = settings->value("bg_blue").toFloat();
    ui->openGLWidget->bg_red = settings->value("bg_red").toFloat();
    ui->openGLWidget->bg_green = settings->value("bg_green").toFloat();
    ui->openGLWidget->edge_blue = settings->value("edge_blue").toFloat();
    ui->openGLWidget->edge_red = settings->value("edge_red").toFloat();
    ui->openGLWidget->edge_green = settings->value("edge_green").toFloat();
    ui->openGLWidget->vertex_blue = settings->value("vertex_blue").toFloat();
    ui->openGLWidget->vertex_red = settings->value("vertex_red").toFloat();
    ui->openGLWidget->vertex_green = settings->value("vertex_green").toFloat();
    ui->openGLWidget->isPerspecProj = settings->value("isPerspecProj").toBool();
    ui->openGLWidget->drawEdges = settings->value("drawEdges").toInt();
    ui->openGLWidget->drawVertices = settings->value("drawVertices").toInt();
    ui->openGLWidget->drawFace = settings->value("drawFace").toBool();
    ui->openGLWidget->radiusPoint = settings->value("radiusPoint").toFloat();
    ui->openGLWidget->lineWidth = settings->value("lineWidth").toFloat();
  }
}

void MainWindow::on_pushButton_edgeGrey_clicked() {
  ui->openGLWidget->setEdgeColor(51, 51, 51);
}

void MainWindow::on_pushButton_edgeWhite_clicked() {
  ui->openGLWidget->setEdgeColor(255, 255, 255);
}

void MainWindow::on_pushButton_edgeGreen_clicked() {
  ui->openGLWidget->setEdgeColor(133, 230, 170);
}

void MainWindow::on_pushButton_edgePink_clicked() {
  ui->openGLWidget->setEdgeColor(230, 115, 174);
}

void MainWindow::on_pushButton_edgeBrown_clicked() {
  ui->openGLWidget->setEdgeColor(122, 55, 4);
}

void MainWindow::on_pushButton_edgeYellow_clicked() {
  ui->openGLWidget->setEdgeColor(230, 222, 115);
}

void MainWindow::on_pushButton_edgePurple_clicked() {
  ui->openGLWidget->setEdgeColor(216, 143, 242);
}

void MainWindow::on_pushButton_edgeBlack_clicked() {
  ui->openGLWidget->setEdgeColor(0, 0, 0);
}

void MainWindow::on_pushButton_edgeBlue_clicked() {
  ui->openGLWidget->setEdgeColor(133, 202, 230);
}

void MainWindow::on_pushButton_edgeOrange_clicked() {
  ui->openGLWidget->setEdgeColor(245, 144, 93);
}

void MainWindow::on_pushButton_vertexGrey_clicked() {
  ui->openGLWidget->setVertexColor(51, 51, 51);
}

void MainWindow::on_pushButton_vertexWhite_clicked() {
  ui->openGLWidget->setVertexColor(255, 255, 255);
}

void MainWindow::on_pushButton_vertexGreen_clicked() {
  ui->openGLWidget->setVertexColor(133, 230, 170);
}

void MainWindow::on_pushButton_vertexPink_clicked() {
  ui->openGLWidget->setVertexColor(230, 115, 174);
}

void MainWindow::on_pushButton_vertexBrown_clicked() {
  ui->openGLWidget->setVertexColor(122, 55, 4);
}

void MainWindow::on_pushButton_vertexYellow_clicked() {
  ui->openGLWidget->setVertexColor(230, 222, 115);
}

void MainWindow::on_pushButton_vertexPurple_clicked() {
  ui->openGLWidget->setVertexColor(216, 143, 242);
}

void MainWindow::on_pushButton_vertexBlack_clicked() {
  ui->openGLWidget->setVertexColor(0, 0, 0);
}

void MainWindow::on_pushButton_vertexBlue_clicked() {
  ui->openGLWidget->setVertexColor(133, 202, 230);
}

void MainWindow::on_pushButton_vertexOrange_clicked() {
  ui->openGLWidget->setVertexColor(245, 144, 93);
}

void MainWindow::disableButtons() {
  // Находим все дочерние виджеты типа QPushButton
  QList<QPushButton *> buttons = findChildren<QPushButton *>();

  // Отключаем все найденные кнопки
  for (QPushButton *button : buttons) {
    button->setEnabled(false);
  }
}

void MainWindow::enableButtons() {
  // Находим все дочерние виджеты типа QPushButton
  QList<QPushButton *> buttons = findChildren<QPushButton *>();

  // Отключаем все найденные кнопки
  for (QPushButton *button : buttons) {
    button->setEnabled(true);
  }
}