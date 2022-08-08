#include "line_tiles.h"

#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

void drawLineTiles(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  float tileWidth = (float)SCREEN_WIDTH / TILE_AMOUNT;
  float tileHeight = (float)SCREEN_HEIGHT / TILE_AMOUNT;
  for (int i = 0; i < TILE_AMOUNT; i++) {
    for (int j = 0; j < TILE_AMOUNT; j++) {
      float startX, startY, endX, endY;
      if (rand() % 2 == 1) {
        startX = i * tileWidth;
        startY = j * tileHeight;
        endX = startX + tileWidth;
        endY = startY + tileHeight;
      } else {
        startX = i * tileWidth + tileWidth;
        startY = j * tileHeight;
        endX = i * tileWidth;
        endY = j * tileHeight + tileHeight;
      }
      SDL_RenderDrawLineF(renderer, startX, startY, endX, endY);
    }
  }

  SDL_RenderPresent(renderer);
}
