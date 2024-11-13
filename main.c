#include "game2048.h"

int grid[SIZE][SIZE];

int main()
{
    srand(time(0));
    char move;

    initGame();

    while (1)
    {
        displayGrid();
        
        if (checkWin()) 
        {
            printf("You win!\n");
            break;
        }

        if (checkLose()) 
        {
            printf("Game over!\n"); //fix
            break;
        }

        printf("Enter move (w = up, s = down, a = left, d = right): ");
        move = getchar(); //fix
        getchar(); //fix
        if (move == 'a' || move == 'w' || move == 'd' || move == 's')
            makeMove(move);
        else
            printf("Invalid move!\n");
    }
    return 0;
}