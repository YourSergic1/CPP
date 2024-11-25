#include "backend_t.h"

int line[20] = {0};

const int level[10] = {1000, 900, 800, 700, 600, 500, 400, 300, 200, 100};

const int figures[7][4][4][4] = {
    {{{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
     {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  //кубик
     {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
     {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}},
    {{{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},  //палка
     {{1, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}},
     {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
     {{1, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}},
    {{{2, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
     {{2, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},  // S
     {{2, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
     {{2, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}}},
    {{{3, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
     {{3, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}},  // Z
     {{3, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
     {{3, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}},
    {{{4, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}},
     {{4, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},  // L
     {{4, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
     {{4, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}}},
    {{{5, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},
     {{5, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}},  // J
     {{5, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
     {{5, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}},
    {{{6, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}},
     {{6, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}},  // T
     {{6, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
     {{6, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}}}};

void create_field(GameInfo_t *new1) {
  new1->field = (int **)calloc(GAME_ROWS, sizeof(int *));
  for (int i = 0; i < GAME_ROWS; i++) {
    new1->field[i] = (int *)calloc(GAME_COLS, sizeof(int));
  }
  for (int i = 0; i < GAME_ROWS; i++) {
    for (int j = 0; j < GAME_COLS; j++) {
      new1->field[i][j] = 0;
    }
  }
}

void create_figure_new(GameInfo_t *new1) {
  new1->next = (int **)calloc(4, sizeof(int *));
  for (int i = 0; i < 4; i++) {
    new1->next[i] = (int *)calloc(4, sizeof(int));
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      new1->next[i][j] = 0;
    }
  }
}

void create_figure_current(current_figure *figure) {
  figure->type = (int **)calloc(4, sizeof(int *));
  for (int i = 0; i < 4; i++) {
    figure->type[i] = (int *)calloc(4, sizeof(int));
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure->type[i][j] = 0;
    }
  }
}

void init_figure(GameInfo_t *new1) {
  srand(time(NULL));  //обнуление рандомайзера
  int number = rand() % 7;
  switch (number) {
    case 0:  //кубик
      init_one_figure(new1, 0);
      break;
    case 1:  //палка
      init_one_figure(new1, 1);
      break;
    case 2:  // S
      init_one_figure(new1, 2);
      break;
    case 3:  // Z
      init_one_figure(new1, 3);
      break;
    case 4:  // L
      init_one_figure(new1, 4);
      break;
    case 5:  // J
      init_one_figure(new1, 5);
      break;
    case 6:  // T
      init_one_figure(new1, 6);
      break;
  }
}

void init_one_figure(GameInfo_t *new1, int number) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      new1->next[i][j] = figures[number][0][i][j];
    }
  }
}

void init_game(GameInfo_t *game, current_figure *figure) {
  create_field(game);       // Создание игрового поля
  create_figure_new(game);  //создание поля для след фигуры
  create_figure_current(figure);  //создание поля для активной фигуры
  init_figure(game);  //иницциализация след фигуры
  switch_figure_box(game, figure);  // свитч на текущую фигуру
  game->pause = 1;                  //игра пока на паузе
  game->level = 0;
  game->speed = level[game->level];
  game->score = 0;
  FILE *file1 = fopen("brick_game/tetris/high_score.txt", "r");
  if (file1 != NULL) {
    if (!fscanf(file1, "%d", &game->high_score)) game->high_score = 0;
    fclose(file1);
  } else {
    game->high_score = 0;
    perror("Open error");
  }
}

void switch_figure_box(GameInfo_t *new1, current_figure *figure) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0 && j == 0)
        figure->type[i][j] = 0;
      else
        figure->type[i][j] = new1->next[i][j];
    }
  }
  figure->number_of_type = new1->next[0][0];
  figure->y = 0;
  figure->x = 4;
  figure->pos = 0;
  init_figure(new1);
}

int move_right(GameInfo_t *game, current_figure *figure) {
  int stop_flag = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->type[i][j] == 1) {
        if (j + figure->x - 1 == 9 ||
            game->field[i + figure->y - 1][j + figure->x] == 1)
          stop_flag = 1;
      }
    }
  }
  if (stop_flag != 1) {
    figure->x++;
  }
  return stop_flag;
}

int move_left(GameInfo_t *game, current_figure *figure) {
  int stop_flag = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->type[i][j] == 1) {
        if (j + figure->x - 1 == 0 ||
            game->field[i + figure->y - 1][j + figure->x - 2] == 1)
          stop_flag = 1;
      }
    }
  }
  if (stop_flag != 1) {
    figure->x--;
  }
  return stop_flag;
}

int move_down(GameInfo_t *game, current_figure *figure) {
  int stop_flag = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->type[i][j] == 1) {
        if (i + figure->y == 20 ||
            game->field[i + figure->y][j + figure->x - 1] == 1)
          stop_flag = 1;
      }
    }
  }
  if (stop_flag != 1) {
    figure->y++;
  }
  return stop_flag;
}

void check_for_full(GameInfo_t *game) {
  int full_flag = 1;
  for (int i = 19; i >= 0; i--) {
    for (int j = 0; j < 10; j++) {
      if (game->field[i][j] == 1)
        continue;
      else
        full_flag = 0;
    }
    if (full_flag == 1) line[i] = 1;
    full_flag = 1;
  }
}

void clear_line(GameInfo_t *game) {
  int count = 0;
  for (int i = 19; i >= 0; i--) {
    if (line[i] == 1) {
      for (int z = i + count; z >= 0; z--) {
        for (int k = 0; k < 10; k++) {
          if (z == 0)
            game->field[z][k] = 0;
          else
            game->field[z][k] = game->field[z - 1][k];
        }
      }
      count++;
    }
    line[i] = 0;
  }
  if (count == 1) game->score += 100;
  if (count == 2) game->score += 300;
  if (count == 3) game->score += 700;
  if (count >= 4) game->score += 1500;
  game->level = game->score / 600;
  if (game->level > 9) game->level = 9;
  game->speed = level[game->level];
  if (game->score > game->high_score) {
    game->high_score = game->score;
    FILE *file = fopen("brick_game/tetris/high_score.txt", "w");
    if (file != NULL) {
      fprintf(file, "%d", game->high_score);
      fclose(file);
    }
  }
}

void rewrite_field(GameInfo_t *game, current_figure *figure) {
  //выход в случае переполнения
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->type[i][j] == 1) {
        game->field[i + figure->y - 1][j + figure->x - 1] = figure->type[i][j];
      }
    }
  }
  switch_figure_box(game, figure);
  check_for_full(game);
  int sum = 0;
  for (int i = 0; i < 20; i++) {
    sum = sum + line[i];
  }
  if (sum > 0) clear_line(game);
}

void clear_field(GameInfo_t *old) {
  for (int i = 0; i < GAME_ROWS; i++) {
    free(old->field[i]);
  }
  free(old->field);
  old->field = NULL;

  for (int i = 0; i < 4; i++) {
    free(old->next[i]);
  }
  free(old->next);
  old->next = NULL;
}

void clear_figure(current_figure *figure) {
  for (int i = 0; i < 4; i++) {
    free(figure->type[i]);
  }
  free(figure->type);
  figure->type = NULL;
}

int check_in_game(GameInfo_t *game) {
  int in_game = 1;
  for (int j = 0; j < 10; j++) {
    if (game->field[0][j] == 1) in_game = 0;
  }
  if (game->field[1][3] == 1 || game->field[1][4] == 1 ||
      game->field[1][5] == 1 || game->field[1][6] == 1)
    in_game = 0;
  return in_game;
}

void rotate(GameInfo_t *game, current_figure *figure) {
  switch (figure->number_of_type) {
    case 0:
      //ничего не меняем так как квадрат, просто заглушка
      break;
    case 1:
      rotate_I(game, figure);
      break;
    case 2:
      rotate_S(game, figure);
      break;
    case 3:
      rotate_Z(game, figure);
      break;
    case 4:
      rotate_L(game, figure);
      break;
    case 5:
      rotate_J(game, figure);
      break;
    case 6:
      rotate_T(game, figure);
      break;
  }
}

void rotate_I(GameInfo_t *game, current_figure *figure) {
  if (figure->pos == 2) figure->pos = 0;
  if (figure->pos == 3) figure->pos = 1;
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y <= 17 && center_y >= 1 &&
          game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 2] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0 &&
          game->field[center_y + 2][center_x - 2] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 2 && center_x <= 8 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y][center_x - 2] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 2] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x - 2] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rotate_S(GameInfo_t *game, current_figure *figure) {
  if (figure->pos == 2) figure->pos = 0;
  if (figure->pos == 3) figure->pos = 1;
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y >= 1 && game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 1 && game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rotate_Z(GameInfo_t *game, current_figure *figure) {
  if (figure->pos == 2) figure->pos = 0;
  if (figure->pos == 3) figure->pos = 1;
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y >= 1 && game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 1 && game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0 &&
          game->field[center_y][center_x] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rotate_L(GameInfo_t *game, current_figure *figure) {
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y >= 1 && game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 1 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 2:
      if (center_y <= 18 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0)
        rewrite_figure(figure);
      break;
    case 3:
      if (center_x <= 8 && game->field[center_y - 1][center_x - 2] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y][center_x - 2] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rotate_J(GameInfo_t *game, current_figure *figure) {
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y >= 1 && game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 1 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 2:
      if (center_y <= 18 && game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0)
        rewrite_figure(figure);
      break;
    case 3:
      if (center_x <= 8 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0 &&
          game->field[center_y + 2][center_x - 1] == 0 &&
          game->field[center_y + 2][center_x] == 0 &&
          game->field[center_y + 2][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rotate_T(GameInfo_t *game, current_figure *figure) {
  int center_x = figure->x + 1;
  int center_y = figure->y;
  switch (figure->pos) {
    case 0:
      if (center_y >= 1 && game->field[center_y - 1][center_x] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 1:
      if (center_x >= 1 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
    case 2:
      if (center_y <= 18 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y - 1][center_x + 1] == 0 &&
          game->field[center_y + 1][center_x - 1] == 0 &&
          game->field[center_y + 1][center_x] == 0)
        rewrite_figure(figure);
      break;
    case 3:
      if (center_x <= 8 && game->field[center_y - 1][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0 &&
          game->field[center_y][center_x - 1] == 0 &&
          game->field[center_y][center_x + 1] == 0)
        rewrite_figure(figure);
      break;
  }
}

void rewrite_figure(current_figure *figure) {
  figure->pos += 1;
  if (figure->pos == 4) figure->pos = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0 && j == 0)
        figure->type[i][j] = 0;
      else
        figure->type[i][j] = figures[figure->number_of_type][figure->pos][i][j];
    }
  }
}

void mane_game(GameInfo_t *game, current_figure *figure) {
  int flag = 1;
  first_iter(game, figure);
  while (flag) {
    int input = -1;
    input = getch();
    work_with_user_input(input, &flag, game, figure);
    flushinp();
    if (flag) flag = check_in_game(game);
    if (flag) {
      print_game(game, figure);
      if (input != KEY_DOWN)
        napms(game->speed);
      else
        napms(50);
    }
  }
}

void work_with_user_input(int input, int *flag, GameInfo_t *game,
                          current_figure *figure) {
  int floor = 0;
  if (input == 9) {  // tab
    wait_for_resume(game);
  } else if (input == 27) {  // esc
    *flag = 0;
  } else if (input == KEY_LEFT) {
    move_left(game, figure);
    floor = move_down(game, figure);
  } else if (input == KEY_RIGHT) {
    move_right(game, figure);
    floor = move_down(game, figure);
  } else if (input == KEY_DOWN) {
    move_down(game, figure);
  } else if (input == 32) {  // spase
    rotate(game, figure);
    floor = move_down(game, figure);
  } else
    floor = move_down(game, figure);
  if (floor) rewrite_field(game, figure);
}

void tetris_g() {
  current_figure figure;
  GameInfo_t game;
  init_game(&game, &figure);  //подготовка к началу игры
  wait_for_start(&game);      //ожидание начала
  mane_game(&game, &figure);  // Основной цикл игры
  wait_to_esc(&game);
  clear_field(&game);
  clear_figure(&figure);  // Очистка и завершение ncurses
}