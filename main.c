#include "game2048.h"

int grid[SIZE][SIZE];

int main()
{
    srand(time(0));
    if (!initSDL()) return -1;
    char* move;

    initGame();

    int quit = 0;
    while (!quit) {
        handleInput(grid);
        drawGrid(grid);
        SDL_Delay(100);
        quit = checkLose();       
    }
    closeSDL();
    return 0;
}