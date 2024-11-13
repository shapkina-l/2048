#ifndef GAME2048_H
#define GAME2048_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

extern int grid[SIZE][SIZE];

void initGame();
void addRandomTile();
void displayGrid();
void slideLeft();
void slideRight();
void slideUp();
void slideDown();
int checkWin();
int checkLose();
void makeMove(char move);

#endif