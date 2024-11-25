#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <ncurses.h>

#include <cstdio>
#include <iostream>
#include <vector>

namespace s21 {

typedef struct {
  int x;
  int y;
} position;

typedef enum { Left, Up, Right, Down } direction_type;

const int ROWS = 20;
const int COLS = 10;
const int levels[10] = {1000, 900, 800, 700, 600, 500, 400, 300, 200, 100};

class game {
 public:
  game();   // Конструктор
  ~game();  // Деструктор

  bool lost;

  void main_game();
  void save_settings();
  void wait_for_start();
  void wait_for_resume();
  void wait_for_esc();
  void wait_for_esc_win();

  bool in_game;
  int score;
  int score_for_speed;
  int **field;
  int high_score;
  int level;
  int speed;
  int direction;
  bool pause;
  int action;
  position apple;
  position last;
  std::vector<position> snake;

  void print_field();
  void print_game();
  void print_snake();
  void print_apple();
  void print_score();
  void print_high_score();
  void print_level();
  void print_start();
  void print_resume();
  void print_lost();
  void print_win();

  void first_iter();
  void work_with_user_input();
  void check_in_game();
  void move();
  void apple_init();
};

void snake_g();
}  // namespace s21

#endif  // BACKEND_HPP