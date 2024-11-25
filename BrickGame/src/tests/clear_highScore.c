#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("brick_game/tetris/high_score.txt", "w");
    fprintf(file, "%d", 0);
    fclose(file);
    FILE *file1 = fopen("brick_game/snake/high_score.txt", "w");
    fprintf(file1, "%d", 0);
    fclose(file1);
    return 0;
}