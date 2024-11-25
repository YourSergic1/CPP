#include "snake.h"

Snake::Snake(QWidget *parent)
    : QDialog(parent), ui(new Ui::Snake), timer(new QTimer(this)) {
  ui->setupUi(this);
  this->setFixedSize(470, 605);
  this->setWindowTitle("Змейка");
  setFocusPolicy(Qt::StrongFocus);
  connect(timer, &QTimer::timeout, this, &Snake::update_paint);
  timer->stop();
}

Snake::~Snake() {
  delete ui;
  delete timer;
}

void Snake::paintEvent(QPaintEvent *) {
  QPainter p;
  p.begin(this);
  p.drawRect(0, 0, 300, 600);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      p.setBrush(Qt::white);
      p.drawRect(30 * j, 30 * i, 30, 30);
    }
  }
  if (game_main.in_game) {
    for (size_t i = 0; i < game_main.snake.size(); i++) {
      p.setBrush(Qt::green);
      if (i > 0) p.setBrush(Qt::black);
      p.drawRect(30 * game_main.snake[i].x, 30 * game_main.snake[i].y, 30, 30);
    }
  }

  p.setBrush(Qt::red);
  p.drawRect(30 * game_main.apple.x, 30 * game_main.apple.y, 30, 30);

  QFont font;
  font.setPointSize(16);
  p.setFont(font);
  std::string s = "Score: " + std::to_string(game_main.score);
  p.drawText(305, 35, s.data());
  std::string l = "Level: " + std::to_string(game_main.level);
  p.drawText(305, 60, l.data());
  std::string hs = "Max points: " + std::to_string(game_main.high_score);
  p.drawText(305, 85, hs.data());
  std::string sp = "Speed: " + std::to_string(game_main.speed);
  p.drawText(305, 110, sp.data());

  QPen pen(Qt::red);
  p.setPen(pen);
  if (game_main.pause) {
    p.drawText(305, 355, "Pause");
    p.drawText(305, 380, "Continue: 'TAB'");
  }

  if (!game_main.in_game && game_main.lost == true) {
    p.drawText(305, 355, "YOU LOST");
    p.drawText(305, 380, "EXIT: 'ESC'");
  }

  QPen pen3(Qt::green);
  p.setPen(pen3);
  if (!game_main.in_game && game_main.lost == false) {
    p.drawText(305, 355, "YOU WIN");
    p.drawText(305, 380, "EXIT: 'ESC'");
  }

  QPen pen2(Qt::blue);
  p.setPen(pen2);
  std::string controls =
      "LEFT: <-\nRIGHT: ->\nDOWN: \\/\nUP: /\\\nFASTER: 'SPACE'\nPAUSE: "
      "'TAB'\nQUIT: 'ESC'\nSTART: TAB";
  QRect controlRect(305, 155, 160, 150);
  p.drawText(controlRect, Qt::AlignLeft | Qt::TextWordWrap, controls.c_str());
  p.end();
}

void Snake::keyPressEvent(QKeyEvent *e) {
  if (game_main.in_game) {
    if (e->key() == Qt::Key_Tab) {
      if (game_main.pause) {
        timer->start(game_main.speed);
        game_main.pause = !game_main.pause;
      } else {
        timer->stop();
        game_main.pause = !game_main.pause;
      }
    }
  }
  if (!game_main.pause) {
    if (e->key() == Qt::Key_Space) {
      game_main.move();
      timer->stop();
      timer->start(game_main.speed);
      game_main.check_in_game();
      repaint();
    } else if (e->key() == Qt::Key_Up) {
      game_main.direction = s21::Up;
      game_main.check_in_game();
      repaint();
    } else if (e->key() == Qt::Key_Left) {
      game_main.direction = s21::Left;
      game_main.check_in_game();
      repaint();
    } else if (e->key() == Qt::Key_Right) {
      game_main.direction = s21::Right;
      game_main.check_in_game();
      repaint();
    } else if (e->key() == Qt::Key_Down) {
      game_main.direction = s21::Down;
      game_main.check_in_game();
      repaint();
    } else if (e->key() == Qt::Key_Escape) {
      timer->stop();
      EXIT w;
      w.setModal(true);
      w.exec();
      timer->start(game_main.speed);
    }
  }
}

void Snake::update_paint(void) {
  if (game_main.in_game) {
    game_main.move();
    timer->stop();
    timer->start(game_main.speed);
    game_main.check_in_game();
  }
  if (!game_main.in_game) {
    timer->stop();
  }
  repaint();
}
