#include "backend_s.hpp"

namespace s21 {

game::game() {
  field = new int *[ROWS];
  for (int i = 0; i < ROWS; ++i) {
    field[i] = new int[COLS];
  }
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      field[i][j] = 0;
    }
  }
  FILE *file1 = fopen("brick_game/snake/high_score.txt", "r");
  if (file1 != NULL) {
    if (!fscanf(file1, "%d", &high_score)) high_score = 0;
    fclose(file1);
  } else {
    high_score = 0;
    perror("Open error");
  }
  score = 0;
  level = 0;
  action = -1;
  direction = Left;
  pause = true;
  in_game = true;
  lost = true;
  speed = levels[level];
  score_for_speed = 0;
  snake.push_back({3, 10});
  snake.push_back({4, 10});
  snake.push_back({5, 10});
  snake.push_back({6, 10});
  apple_init();
  last = {7, 10};
}

game::~game() {
  for (int i = 0; i < ROWS; ++i) {
    delete[] field[i];
  }
  delete[] field;
}

void game::check_in_game() {
  if (snake[0].x < 0 || snake[0].x > 9 || snake[0].y < 0 || snake[0].y > 19)
    in_game = false;
  for (size_t i = 1; i < snake.size(); i++) {
    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
      in_game = false;
      break;
    }
  }
}

void game::apple_init() {
  bool flag = true;
  while (flag) {
    srand(time(NULL));  //обнуление рандомайзера
    apple.x = rand() % 10;
    srand(time(NULL));  //обнуление рандомайзера
    apple.y = rand() % 20;
    flag = false;
    for (size_t i = 0; i < snake.size(); i++) {
      if (snake[i].x == apple.x && snake[i].y == apple.y) {
        flag = true;
      }
    }
  }
}

void game::move() {
  position box1;
  for (size_t i = 0; i < snake.size(); i++) {
    if (i == 0) {
      box1 = snake[i];
      if (direction == Up) snake[0].y--;
      if (direction == Down) snake[0].y++;
      if (direction == Left) snake[0].x--;
      if (direction == Right) snake[0].x++;
    } else if (i == snake.size() - 1) {
      position box2 = snake[i];
      snake[i] = box1;
      last = box2;
    } else {
      position box2 = snake[i];
      snake[i] = box1;
      box1 = box2;
    }
  }
  if (snake[0].x == apple.x && snake[0].y == apple.y) {
    snake.push_back({last.x, last.y});
    score++;
    if (score > high_score) {
      high_score = score;
    }
    score_for_speed++;
    if (score_for_speed == 5 && level < 10) {
      score_for_speed = 0;
      level++;
      speed = levels[level];
    }
    if (score >= 200) {
      in_game = 0;
      lost = false;
    }
    apple_init();
  }
}

void game::work_with_user_input() {
  if (action == 9) {  // tab
    wait_for_resume();
  } else if (action == 27) {  // esc
    in_game = false;
  } else if (action == 32) {  // spase
    move();
  } else if (action == KEY_UP) {
    if (direction == Left || direction == Right) direction = Up;
    move();
  } else if (action == KEY_LEFT) {
    if (direction == Up || direction == Down) direction = Left;
    move();
  } else if (action == KEY_RIGHT) {
    if (direction == Up || direction == Down) direction = Right;
    move();
  } else if (action == KEY_DOWN) {
    if (direction == Left || direction == Right) direction = Down;
    move();
  } else
    move();
}

void game::main_game() {
  first_iter();
  while (in_game) {
    action = -1;
    action = getch();
    work_with_user_input();
    flushinp();
    if (in_game) check_in_game();
    if (in_game) {
      print_game();
      if (action != 32)
        napms(speed);
      else
        napms(400);
    }
  }
}

void game::save_settings() {
  FILE *file = fopen("brick_game/snake/high_score.txt", "w");
  if (file != NULL) {
    fprintf(file, "%d", high_score);
    fclose(file);
  }
}

void snake_g() {
  game game1;
  game1.wait_for_start();
  game1.main_game();
  if (game1.lost == true)
    game1.wait_for_esc();
  else
    game1.wait_for_esc_win();
  game1.save_settings();
}

}  // namespace s21
