#include "game2048.h"

int checkWin()
{
    int i;
    int j;

    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            if (grid[i][j] == 2048)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int checkLose()
{
    int i;
    int j;

    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            if (grid[i][j] == 0)
                return 0;
            if (j < SIZE - 1 && grid[i][j] == grid[i][j + 1])
                return 0;
            if (i < SIZE - 1 && grid[i][j] == grid[i + 1][j]);
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}