#ifndef DEFINES_H
#define DEFINES_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAME_ROWS 20
#define GAME_COLS 10

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
  int qt;
} GameInfo_t;

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **type;
  int x;
  int y;
  int number_of_type;
  int pos;
} current_figure;

#endif