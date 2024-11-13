#include "game2048.h"

void slideLeft()
{
    int i;
    int j;

    i = 0;
    while(i < SIZE)
    {
        int lastMerged = -1;
        j = 0;
        while(j < SIZE)
        {
            if (grid[i][j] == 0)
            {
                j++;
                continue;
            }
            int k = j;
            while (k > 0 && grid[i][k - 1] == 0)
            {
                grid[i][k - 1] = grid[i][k];
                grid[i][k] = 0;
                k--;
            }
            if (k > 0 && grid[i][k] == grid[i][k - 1] && lastMerged != k - 1)
            {
                grid[i][k - 1] *= 2;
                grid[i][k] = 0;
                lastMerged = k - 1;
            }
            j++;
        }
        i++;
    }
}

void slideRight()
{
    int i;
    int j;

    i = 0;
    while(i < SIZE)
    {
        int lastMerged = -1;
        j = SIZE - 1;
        while(j >= 0)
        {
            if (grid[i][j] == 0)
            {
                j--;
                continue;
            }
            int k = j;
            while (k < (SIZE - 1) && grid[i][k + 1] == 0)
            {
                grid[i][k + 1] = grid[i][k];
                grid[i][k] = 0;
                k++;
            }
            if (k < (SIZE - 1) && grid[i][k] == grid[i][k + 1] && lastMerged != k + 1)
            {
                grid[i][k + 1] *= 2;
                grid[i][k] = 0;
                lastMerged = k + 1;
            }
            j--;
        }
        i++;
    }
}

void slideUp()
{
    int i;
    int j;

    j = 0;
    while(j < SIZE)
    {
        int lastMerged = -1;
        i = 0;
        while(i < SIZE)
        {
            if (grid[i][j] == 0)
            {
                i++;
                continue;
            }
            int k = i;
            while (k > 0 && grid[k - 1][j] == 0)
            {
                grid[k - 1][j] = grid[k][j];
                grid[k][j] = 0;
                k--;
            }
            if (k > 0 && grid[k][j] == grid[k - 1][j] && lastMerged != k - 1)
            {
                grid[k - 1][j] *= 2;
                grid[k][j] = 0;
                lastMerged = k - 1;
            }
            i++;
        }
        j++;
    }
}

void slideDown()
{
    int i;
    int j;

    j = 0;
    while(j < SIZE)
    {
        int lastMerged = -1;
        i = SIZE - 1;
        while(i >= 0)
        {
            if (grid[i][j] == 0)
            {
                i--;
                continue;
            }
            int k = i;
            while (k < (SIZE - 1) && grid[k + 1][j] == 0)
            {
                grid[k + 1][j] = grid[k][j];
                grid[k][j] = 0;
                k++;
            }
            if (k < (SIZE - 1) && grid[k][j] == grid[k + 1][j] && lastMerged != k + 1)
            {
                grid[k + 1][j] *= 2;
                grid[k][j] = 0;
                lastMerged = k + 1;
            }
            i--;
        }
        j++;
    }
}