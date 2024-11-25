#include "brick_game/backend.hpp"
#include "brick_game/snake/backend_s.hpp"
#include "brick_game/tetris/backend_t.h"
#include "gui/cli/frontend.hpp"
#include "gui/cli/tetris/frontend_t.h"

extern "C" {
void tetris();
}

int main() {
  initscr();    //инициализация ncurses
  cbreak();     //убирает ожидания enter
  noecho();     //не отображает вводимые символы
  curs_set(0);  //убираем курсор
  keypad(stdscr, TRUE);  //подключение клавиатуры
  timeout(0);            // Отключение ожидания ввода
  int key = (s21::choose_the_game());
  if (key == KEY_LEFT) {
    tetris_g();
  } else if (key == KEY_RIGHT) {
    s21::snake_g();
  }
  endwin();
  return 0;
}