#include "game2048.h"

void initGame()
{
    int i;
    int j;

    i = 0;
    while(i < SIZE)
    {
        j = 0;
        while(j < SIZE)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
    addRandomTile();
    addRandomTile();
}

void addRandomTile()
{
    int emptyCells[SIZE*SIZE][2];
    int count = 0;

    int i;
    int j;
    
    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            if (grid[i][j] == 0)
            {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
            j++;
        }
        i++;
    }

    if (count > 0)
    {
        int r = rand() % count;
        int x = emptyCells[r][0];
        int y = emptyCells[r][1];

        grid[x][y] = (rand() % 10 == 0) ? 4 : 2;
    }
}

void displayGrid()
{
    int i;
    int j;

    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            printf("%d\t", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}