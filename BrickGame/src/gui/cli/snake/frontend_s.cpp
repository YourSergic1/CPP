#include "../../../brick_game/snake/backend_s.hpp"
#include "../tetris/frontend_t.h"

extern "C" {
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
}

namespace s21 {
void game::print_field() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mvaddch(i + 1, j + 1, '.');
    }
  }
  print_rectangle(0, ROWS + 1, 0, COLS + 1);
}

void game::print_snake() {
  for (size_t i = 0; i < snake.size(); i++) {
    mvaddch((snake[i].y) + 1, (snake[i].x) + 1, '#');
  }
}

void game::print_apple() {
  for (size_t i = 0; i < snake.size(); i++) {
    mvaddch((apple.y) + 1, (apple.x) + 1, 'o');
  }
}

void game::print_score() {
  mvprintw(4, 15, "Your score:%d", score);
  print_rectangle(3, 5, 13, 32);
}

void game::print_high_score() {
  mvprintw(1, 15, "HIGH SCORE:%d", high_score);
  print_rectangle(0, 2, 13, 32);
}

void game::print_level() {
  print_rectangle(6, 8, 13, 26);
  mvprintw(7, 15, "Level:%d", level);
}

void game::print_start() {
  print_rectangle(0, 12, 0, 40);
  mvprintw(2, 3, "Press TAB to start the game!");
  mvprintw(4, 3, "Press ArrowRight to move right");
  mvprintw(5, 3, "Press ArrowLeft to move left");
  mvprintw(6, 3, "Press ArrowDown to move down");
  mvprintw(7, 3, "Press ArrowUp to move up");
  mvprintw(8, 3, "Press SPASE to move faster");
  mvprintw(9, 3, "Press TAB during the game to pause");
  mvprintw(10, 3, "Press ESC to exit");
  refresh();
}

void game::print_resume() {
  print_rectangle(13, 16, 13, 47);
  mvprintw(14, 16, "          ON PAUSE!");
  mvprintw(15, 16, "Press TAB to resume the game!");
  refresh();
}

void game::print_lost() {
  print_rectangle(12, 16, 13, 32);
  mvprintw(13, 15, "YOU LOST!");
  mvprintw(14, 15, "Your score = %d", score);
  mvprintw(15, 15, "Press ESC to exit");
  refresh();
}

void game::print_win() {
  print_rectangle(12, 16, 13, 24);
  mvprintw(14, 15, "YOU WIN!");
  refresh();
}

void game::print_game() {
  clear();
  print_field();
  print_snake();
  print_apple();
  print_high_score();
  print_score();
  print_level();
  refresh();
}

void game::first_iter() {
  print_game();
  napms(speed);
}

void game::wait_for_start() {
  int a = -9;
  while (a != 9) {
    print_start();
    a = getch();
  }
  pause = false;
}

void game::wait_for_resume() {
  pause = true;
  int a = -9;
  while (a != 9) {
    print_resume();
    a = getch();
  }
  pause = false;
}

void game::wait_for_esc() {
  pause = true;
  int a = -9;
  while (a != 27) {
    print_lost();
    a = getch();
  }
}

void game::wait_for_esc_win() {
  pause = true;
  int a = -9;
  while (a != 27) {
    print_win();
    a = getch();
  }
}
}  // namespace s21