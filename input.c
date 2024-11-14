#include "game2048.h"

// void makeMove(char move)
// {
//     if (move == 'a')
//         slideLeft();
//     else if (move == 'd')
//         slideRight();
//     else if (move == 'w')
//         slideUp();
//     else if (move == 's')
//         slideDown();
  
//     addRandomTile();
// }

void handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) exit(0);

        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w: slideUp(); addRandomTile(); break;
                case SDLK_s: slideDown(); addRandomTile(); break;
                case SDLK_a: slideLeft(); addRandomTile(); break;
                case SDLK_d: slideRight(); addRandomTile(); break;
            }
        }
    }
}
