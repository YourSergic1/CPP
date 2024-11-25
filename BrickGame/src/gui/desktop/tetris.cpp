#include "tetris.h"

Tetris::Tetris(QWidget *parent)
    : QDialog(parent), ui(new Ui::Tetris), timer(new QTimer(this)) {
  ui->setupUi(this);
  in_game = true;
  this->setFixedSize(470, 605);
  this->setWindowTitle("Тетрис");
  setFocusPolicy(Qt::StrongFocus);
  init_game(&game, &figure);  //подготовка к началу игры
  connect(timer, &QTimer::timeout, this, &Tetris::update_paint);
  timer->stop();
}

Tetris::~Tetris() {
  delete timer;
  clear_field(&game);
  clear_figure(&figure);
  delete ui;
}

void Tetris::paintEvent(QPaintEvent *) {
  QPainter p;
  p.begin(this);
  p.drawRect(0, 0, 300, 600);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (game.field[i][j] == 1)
        p.setBrush(Qt::black);
      else
        p.setBrush(Qt::white);
      p.drawRect(30 * j, 30 * i, 30, 30);
    }
  }
  if (in_game) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (figure.type[i][j]) {
          p.setBrush(Qt::black);
          p.drawRect(30 * (j + figure.x) - 30, 30 * (i + figure.y) - 30, 30,
                     30);
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0 && j == 0)
        p.setBrush(Qt::white);
      else {
        if (game.next[i][j]) {
          p.setBrush(Qt::black);
        } else {
          p.setBrush(Qt::white);
        }
      }
      p.drawRect(30 * j + 310, 30 * i + 30, 30, 30);
    }
  }

  QFont font;
  font.setPointSize(16);
  p.setFont(font);
  p.drawText(305, 25, "Next step:");
  std::string s = "Score: " + std::to_string(game.score);
  p.drawText(305, 205, s.data());
  std::string l = "Level: " + std::to_string(game.level);
  p.drawText(305, 230, l.data());
  std::string hs = "Max points: " + std::to_string(game.high_score);
  p.drawText(305, 255, hs.data());
  std::string sp = "Speed: " + std::to_string(game.speed);
  p.drawText(305, 280, sp.data());
  QPen pen(Qt::red);

  p.setPen(pen);
  if (game.pause && in_game) {
    p.drawText(305, 525, "Pause");
    p.drawText(305, 550, "Continue: 'TAB'");
  }

  if (!in_game) {
    p.drawText(305, 525, "YOU LOST");
    p.drawText(305, 550, "EXIT: 'ESC'");
  }

  QPen pen2(Qt::blue);
  p.setPen(pen2);
  std::string controls =
      "LEFT: <-\nRIGHT: ->\nDOWN: \\/\nROTATE: 'SPACE'\nPAUSE: 'TAB'\nQUIT: "
      "'ESC'\nSTART: TAB";
  QRect controlRect(305, 325, 160, 150);
  p.drawText(controlRect, Qt::AlignLeft | Qt::TextWordWrap, controls.c_str());
  p.end();
}

void Tetris::keyPressEvent(QKeyEvent *e) {
  if (in_game) {
    if (e->key() == Qt::Key_Tab) {
      if (game.pause) {
        timer->start(game.speed);
        game.pause = !game.pause;
      } else {
        timer->stop();
        game.pause = !game.pause;
      }
    }
  }
  if (!game.pause) {
    if (e->key() == Qt::Key_Space) {
      rotate(&game, &figure);
      repaint();
    } else if (e->key() == Qt::Key_Left) {
      move_left(&game, &figure);
      repaint();
    } else if (e->key() == Qt::Key_Right) {
      move_right(&game, &figure);
      repaint();
    } else if (e->key() == Qt::Key_Down) {
      move_down(&game, &figure);
      repaint();
    } else if (e->key() == Qt::Key_Escape) {
      timer->stop();
      game.pause = 1;
      EXIT w;
      w.setModal(true);
      w.exec();
      game.pause = 0;
      timer->start(game.speed);
    }
  }
}

void Tetris::update_paint(void) {
  in_game = check_in_game(&game);
  if (in_game) {
    int floor = move_down(&game, &figure);
    repaint();
    if (floor) {
      rewrite_field(&game, &figure);
      timer->setInterval(game.speed);
    }
    in_game = check_in_game(&game);
    repaint();
  }
  repaint();
}
