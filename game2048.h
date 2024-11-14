#ifndef GAME2048_H
#define GAME2048_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 400
#define TILE_SIZE 100
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
//void makeMove(char move);
int initSDL();
void drawTile(int x, int y, int value);
void drawGrid();
SDL_Texture* renderText(const char *text, SDL_Color color, TTF_Font *font, SDL_Renderer *renderer);
void renderTileText(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font);
void closeSDL();
void handleInput();

#endif