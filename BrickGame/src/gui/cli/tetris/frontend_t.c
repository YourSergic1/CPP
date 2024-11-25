#include "frontend_t.h"

void print_field(GameInfo_t *status) {
  for (int i = 0; i < GAME_ROWS; i++) {
    for (int j = 0; j < GAME_COLS; j++) {
      if (status->field[i][j] == 0) mvaddch(i + 1, j + 1, '.');
      if (status->field[i][j] == 1) mvaddch(i + 1, j + 1, '@');
    }
  }
}

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  mvaddch(top_y, left_x, ACS_ULCORNER);
  mvaddch(top_y, right_x, ACS_URCORNER);
  mvaddch(bottom_y, left_x, ACS_LLCORNER);
  mvaddch(bottom_y, right_x, ACS_LRCORNER);
  for (int i = left_x + 1; i < right_x; i++) mvaddch(top_y, i, ACS_HLINE);
  for (int i = top_y + 1; i < bottom_y; i++) {
    mvaddch(i, left_x, ACS_VLINE);
    mvaddch(i, right_x, ACS_VLINE);
  }
  for (int i = left_x + 1; i < right_x; i++) mvaddch(bottom_y, i, ACS_HLINE);
}

void print_figure(current_figure *figure) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->type[i][j] == 1) mvaddch(i + figure->y, j + figure->x, '@');
    }
  }
}

void print_next_figure(GameInfo_t *new1) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0 && j == 0)
        mvaddch(i + 7, j + 14, '.');
      else {
        if (new1->next[i][j] == 1)
          mvaddch(i + 7, j + 14, '@');
        else
          mvaddch(i + 7, j + 14, '.');
      }
    }
  }
}

void print_game(GameInfo_t *game, current_figure *figure) {
  clear();            // Очистка экрана
  print_field(game);  // Вывод игрового поля
  print_rectangle(0, GAME_ROWS + 1, 0,
                  GAME_COLS + 1);  // Вывод границ поля
  print_figure(figure);
  print_rectangle(0, 2, 13, 32);
  mvprintw(1, 15, "HIGH SCORE:%d", game->high_score);
  print_rectangle(3, 5, 13, 32);
  mvprintw(4, 15, "Your score:%d", game->score);
  print_rectangle(6, 11, 13, 18);
  print_next_figure(game);
  print_rectangle(6, 8, 19, 32);
  mvprintw(7, 20, "Level:%d", game->level);
  refresh();
}

void print_info_start() {
  print_rectangle(0, 11, 0, 40);
  mvprintw(2, 3, "Press TAB to start the game!");
  mvprintw(4, 3, "Press ArrowRight to move right");
  mvprintw(5, 3, "Press ArrowLeft to move left");
  mvprintw(6, 3, "Press ArrowDown to move Down faster");
  mvprintw(7, 3, "Press ArrowUp to rotate the figure");
  mvprintw(8, 3, "Press TAB during the game to pause");
  mvprintw(9, 3, "Press ESC to exit");
  refresh();
}

void print_info_resume() {
  print_rectangle(14, 17, 13, 47);
  mvprintw(15, 16, "          ON PAUSE!");
  mvprintw(16, 16, "Press TAB to resume the game!");
  refresh();
}

void print_info_lost(GameInfo_t *game) {
  print_rectangle(12, 16, 13, 32);
  mvprintw(13, 15, "YOU LOST!");
  mvprintw(14, 15, "Your score = %d", game->score);
  mvprintw(15, 15, "Press ESC to exit");
  refresh();
}

void first_iter(GameInfo_t *game, current_figure *figure) {
  print_game(game, figure);
  napms(game->speed);
}

void wait_for_start(GameInfo_t *game) {  //добавить esc
  int a = -9;
  while (a != 9) {
    print_info_start();
    a = getch();
  }
  game->pause = 0;
}

void wait_for_resume(GameInfo_t *game) {  //добавить esc
  game->pause = 1;
  int a = -9;
  while (a != 9) {
    print_info_resume();
    a = getch();
  }
  game->pause = 0;
}

void wait_to_esc(GameInfo_t *game) {
  int a = 0;
  while (a != 27) {
    a = getch();
    print_info_lost(game);
  }
}