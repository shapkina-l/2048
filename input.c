#include "game2048.h"

void makeMove(char move)
{
    if (move == 'a')
        slideLeft();
    else if (move == 'd')
        slideRight();
    else if (move == 'w')
        slideUp();
    else if (move == 's')
        slideDown();
  
    addRandomTile();
}