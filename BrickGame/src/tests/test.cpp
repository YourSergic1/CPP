#include <gtest/gtest.h>

#include "../brick_game/backend.hpp"
#include "../brick_game/snake/backend_s.hpp"
#include "../brick_game/tetris/backend_t.h"
#include "../gui/cli/tetris/frontend_t.h"

TEST(TETRIS, CreateField_CreateFigureNew_ClearField) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  int result[20][10] = {0};
  int result_figure[4][4] = {0};
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ASSERT_EQ(game.field[i][j], result[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(game.next[i][j], result_figure[i][j]);
    }
  }
  clear_field(&game);
}

TEST(TETRIS, CreateFigureCurent_ClearFigure) {
  current_figure figure;
  create_figure_current(&figure);
  int result_figure[4][4] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result_figure[i][j]);
    }
  }
  clear_figure(&figure);
}

TEST(TETRIS, InitOnrFigure) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  init_one_figure(&game, 0);
  int result_figure[4][4][4] = {
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  //кубик
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(game.next[i][j], result_figure[0][i][j]);
    }
  }
  clear_field(&game);
}

TEST(TETRIS, InitFigure) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  init_figure(&game);
  int number_of_figure = game.next[0][0];
  int result_figure[7][4][4] = {
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{2, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{3, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
      {{4, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}},
      {{5, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},
      {{6, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(game.next[i][j], result_figure[number_of_figure][i][j]);
    }
  }
  clear_field(&game);
}

TEST(TETRIS, InitGame) {
  GameInfo_t game;
  current_figure figure;
  init_game(&game, &figure);
  ASSERT_EQ(game.pause, 1);
  ASSERT_EQ(game.level, 0);
  ASSERT_EQ(game.speed, 1000);
  ASSERT_EQ(game.high_score, 0);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, SwithFigureBox) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      game.next[i][j] = 1;
    }
  }
  switch_figure_box(&game, &figure);
  int result[4][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(result[i][j], figure.type[i][j]);
    }
  }
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveRight1) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  move_right(&game, &figure);
  ASSERT_EQ(figure.x, 5);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveLeft1) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  move_left(&game, &figure);
  ASSERT_EQ(figure.x, 3);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveRight2) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int res;
  for (int i = 0; i < 10; i++) {
    res = move_right(&game, &figure);
  }
  ASSERT_EQ(res, 1);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveLeft2) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int res;
  for (int i = 0; i < 10; i++) {
    res = move_left(&game, &figure);
  }
  ASSERT_EQ(res, 1);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveDown1) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 0);
  switch_figure_box(&game, &figure);
  int res;
  for (int i = 0; i < 20; i++) {
    res = move_down(&game, &figure);
  }
  ASSERT_EQ(res, 1);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, MoveDown2) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 0);
  switch_figure_box(&game, &figure);
  move_down(&game, &figure);
  ASSERT_EQ(figure.y, 1);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, ClearLine) {
  GameInfo_t game;
  create_field(&game);
  game.score = 0;
  game.high_score = 0;
  create_figure_new(&game);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      game.field[i][j] = 1;
    }
  }
  check_for_full(&game);
  clear_line(&game);
  ASSERT_EQ(game.score, 1500);
  clear_field(&game);
}

TEST(TETRIS, Rewrite) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_current(&figure);
  create_figure_new(&game);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure.type[i][j] = 1;
    }
  }
  figure.x = 1;
  figure.y = 1;
  rewrite_field(&game, &figure);
  int result[20][10] = {
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ASSERT_EQ(game.field[i][j], result[i][j]);
    }
  }

  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, InGame1) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  int result = 1;
  ASSERT_EQ(result, check_in_game(&game));
  clear_field(&game);
}

TEST(TETRIS, InGame2) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  int result = 1;
  ASSERT_EQ(result, check_in_game(&game));
  clear_field(&game);
}

TEST(TETRIS, TEST_rotate_O) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 0);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_I) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 1);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_S) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 2);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_Z) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 3);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_L) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 4);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_J) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 5);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_rotate_T) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 6);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_user_input_left) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int input = KEY_LEFT;
  int flag = 0;
  work_with_user_input(input, &flag, &game, &figure);
  ASSERT_EQ(3, figure.x);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_user_input_right) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int input = KEY_RIGHT;
  int flag = 0;
  work_with_user_input(input, &flag, &game, &figure);
  ASSERT_EQ(5, figure.x);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(TETRIS, TEST_user_input_down) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int input = KEY_DOWN;
  int flag = 0;
  work_with_user_input(input, &flag, &game, &figure);
  ASSERT_EQ(1, figure.y);
  clear_field(&game);
  clear_figure(&figure);
}

TEST(SNAKE, Constructor_Destructor) {
  s21::game new_game;
  ASSERT_EQ(new_game.score, 0);
  ASSERT_EQ(new_game.level, 0);
  ASSERT_EQ(new_game.action, -1);
  ASSERT_EQ(new_game.direction, 0);
  ASSERT_EQ(new_game.pause, true);
  ASSERT_EQ(new_game.in_game, true);
  ASSERT_EQ(new_game.lost, true);
  ASSERT_EQ(new_game.speed, 1000);
  ASSERT_EQ(new_game.score_for_speed, 0);
  ASSERT_EQ(new_game.snake[0].x, 3);
  ASSERT_EQ(new_game.snake[0].y, 10);
  ASSERT_EQ(new_game.snake[1].x, 4);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 5);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 6);
  ASSERT_EQ(new_game.snake[3].y, 10);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ASSERT_EQ(new_game.field[i][j], 0);
    }
  }
}

TEST(SNAKE, CheckInGame1) {
  s21::game new_game;
  new_game.check_in_game();
  ASSERT_EQ(new_game.in_game, true);
}

TEST(SNAKE, CheckInGame2) {
  s21::game new_game;
  for (int i = 0; i < 5; i++) {
    new_game.move();
  }
  new_game.check_in_game();
  ASSERT_EQ(new_game.in_game, false);
}

TEST(SNAKE, CheckInGame3) {
  s21::game new_game;
  new_game.snake.push_back({7, 10});
  new_game.action = KEY_UP;
  new_game.work_with_user_input();
  new_game.action = KEY_RIGHT;
  new_game.work_with_user_input();
  new_game.action = KEY_DOWN;
  new_game.work_with_user_input();
  new_game.check_in_game();
  ASSERT_EQ(new_game.in_game, false);
}

TEST(SNAKE, Move1) {
  s21::game new_game;
  new_game.score = 4;
  new_game.score_for_speed = 4;
  new_game.apple = {2, 10};
  new_game.move();
  ASSERT_EQ(new_game.snake[0].x, 2);
  ASSERT_EQ(new_game.snake[0].y, 10);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 4);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 5);
  ASSERT_EQ(new_game.snake[3].y, 10);
  ASSERT_EQ(new_game.score, 5);
  ASSERT_EQ(new_game.score_for_speed, 0);
  ASSERT_EQ(new_game.high_score, 5);
  ASSERT_EQ(new_game.level, 1);
  ASSERT_EQ(new_game.speed, 900);
}

TEST(SNAKE, WorkWithUserInput1) {
  s21::game new_game;
  new_game.action = 27;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.in_game, false);
}

TEST(SNAKE, WorkWithUserInput2) {
  s21::game new_game;
  new_game.action = 32;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 2);
  ASSERT_EQ(new_game.snake[0].y, 10);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 4);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 5);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, WorkWithUserInput3) {
  s21::game new_game;
  new_game.action = KEY_UP;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 3);
  ASSERT_EQ(new_game.snake[0].y, 9);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 4);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 5);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, WorkWithUserInput4) {
  s21::game new_game;
  new_game.action = KEY_DOWN;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 3);
  ASSERT_EQ(new_game.snake[0].y, 11);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 4);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 5);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, WorkWithUserInput5) {
  s21::game new_game;
  new_game.action = KEY_DOWN;
  new_game.work_with_user_input();
  new_game.action = KEY_LEFT;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 2);
  ASSERT_EQ(new_game.snake[0].y, 11);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 11);
  ASSERT_EQ(new_game.snake[2].x, 3);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 4);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, WorkWithUserInput6) {
  s21::game new_game;
  new_game.action = KEY_DOWN;
  new_game.work_with_user_input();
  new_game.action = KEY_RIGHT;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 4);
  ASSERT_EQ(new_game.snake[0].y, 11);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 11);
  ASSERT_EQ(new_game.snake[2].x, 3);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 4);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, WorkWithUserInput7) {
  s21::game new_game;
  new_game.work_with_user_input();
  ASSERT_EQ(new_game.snake[0].x, 2);
  ASSERT_EQ(new_game.snake[0].y, 10);
  ASSERT_EQ(new_game.snake[1].x, 3);
  ASSERT_EQ(new_game.snake[1].y, 10);
  ASSERT_EQ(new_game.snake[2].x, 4);
  ASSERT_EQ(new_game.snake[2].y, 10);
  ASSERT_EQ(new_game.snake[3].x, 5);
  ASSERT_EQ(new_game.snake[3].y, 10);
}

TEST(SNAKE, SaveSettings) {
  s21::game new_game;
  new_game.high_score = 10;
  new_game.save_settings();
  int result = 0;
  FILE *file2 = fopen("brick_game/snake/high_score.txt", "r");
  fscanf(file2, "%d", &result);
  fclose(file2);
  ASSERT_EQ(new_game.high_score, result);
}

TEST(SNAKE, Move2) {
  s21::game new_game;
  new_game.score = 199;
  new_game.apple = {2, 10};
  new_game.move();
  ASSERT_EQ(new_game.in_game, 0);
  ASSERT_EQ(new_game.lost, false);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}