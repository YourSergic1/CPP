#include "frontend.hpp"

extern "C" {
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
}

namespace s21 {
void choose_game_print() {
  print_rectangle(0, 8, 0, 33);
  mvprintw(2, 9, "CHOOSE THE GAME!");
  mvprintw(4, 3, "* Pess <- to play the Tetris");
  mvprintw(5, 3, "* Pess -> to play the Snake");
  mvprintw(6, 3, "* Pess ESC to exit");
}
}  // namespace s21