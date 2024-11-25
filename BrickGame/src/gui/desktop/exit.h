#ifndef EXIT_H
#define EXIT_H

#include <QDialog>

namespace Ui {
class EXIT;
}

class EXIT : public QDialog {
  Q_OBJECT

 public:
  explicit EXIT(QWidget *parent = nullptr);
  ~EXIT();

 private slots:
  void on_pushButton_NO_clicked();

  void on_pushButton_YES_clicked();

 private:
  Ui::EXIT *ui;
};

#endif  // EXIT_H
