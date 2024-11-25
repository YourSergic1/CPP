#ifndef FRONTEND_TETRIS_H
#define FRONTEND_TETRIS_H

#include "../../../brick_game/tetris/backend_t.h"
#include "../../../brick_game/tetris/defines_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void print_field(GameInfo_t *status);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_figure(current_figure *figure);
void print_next_figure(GameInfo_t *new1);
void print_game(GameInfo_t *game, current_figure *figure);
void print_info_start();
void print_info_resume();
void print_info_lost(GameInfo_t *game);

void first_iter(GameInfo_t *game, current_figure *figure);
void wait_for_start(GameInfo_t *game);
void wait_for_resume(GameInfo_t *game);
void wait_to_esc(GameInfo_t *game);

#ifdef __cplusplus
}
#endif
#endif