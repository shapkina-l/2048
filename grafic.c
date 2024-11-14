#include "game2048.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;

int initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    window = SDL_CreateWindow("2048 Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) 
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    if (TTF_Init() == -1) 
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        return 0;
    }
    font = TTF_OpenFont("OpenSans-Light.ttf", 50); 
    if (!font) 
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return 0;
    }
    return 1;
}

void drawTile(int x, int y, int value)
{
    SDL_Rect tile = {x, y, TILE_SIZE - 5, TILE_SIZE - 5};
    int color = value ? 255 - 10 * (value % 20) : 200;
    SDL_SetRenderDrawColor(renderer, color, color, color, 255);
    SDL_RenderFillRect(renderer, &tile);

    if (value != 0) 
    {
        char valueText[8];
        snprintf(valueText, sizeof(valueText), "%d", value); 
        renderTileText(renderer, x + TILE_SIZE / 2, y + TILE_SIZE / 2, valueText, font); 
    }
}

void drawGrid() 
{
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255); 
    SDL_RenderClear(renderer);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int value = grid[i][j];
            drawTile(j * TILE_SIZE, i * TILE_SIZE, value);
        }
    }
    SDL_RenderPresent(renderer); 
}

SDL_Texture* renderText(const char *text, SDL_Color color, TTF_Font *font, SDL_Renderer *renderer) 
{
    SDL_Surface *surface = TTF_RenderText_Blended(font, text, color);
    if (!surface) {
        printf("TTF_RenderText_Blended: %s\n", TTF_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Free the surface after converting to texture
    return texture;
}

void renderTileText(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font) 
{
    SDL_Color textColor = {255, 255, 255}; // White color for text
    SDL_Texture *textTexture = renderText(text, textColor, font, renderer);
    if (textTexture) {
        int textW, textH;
        SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);

        SDL_Rect textRect = {x - textW / 2, y - textH / 2, textW, textH}; // Center text on tile
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture); 
    }
}

void closeSDL() 
{
    TTF_CloseFont(font);
    TTF_Quit(); 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}