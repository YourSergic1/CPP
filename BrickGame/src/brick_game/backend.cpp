#include "backend.hpp"

#include "../gui/cli/frontend.hpp"

namespace s21 {
int choose_the_game() {
  int a = -9;
  while (a != KEY_LEFT && a != KEY_RIGHT && a != 27) {
    choose_game_print();
    a = getch();
  }
  clear();
  return a;
}
}  // namespace s21
