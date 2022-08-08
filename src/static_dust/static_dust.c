#include "./static_dust.h"

#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

void drawNewRect(SDL_Renderer *renderer, float size, float y, float xOffset, int count) {
  if (size < 1.5) {
    return;
  }
  float x = (float)SCREEN_WIDTH / 2 - size / 2 + xOffset;
  SDL_FRect rect = {
      .h = size,
      .w = size,
      .x = x,
      .y = y,
  };
  float r = 255 - (y * 0.15 + x * 0.15);
  float g = 255;
  float b = 255 - (y * 0.05 + x * 0.05);
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderDrawRectF(renderer, &rect);

  float num = 5 - xOffset * 0.05;
  if (count % 20 > 10) {
    xOffset += num;
  } else {
    xOffset -= num;
  }

  count += rand() % 4;

  drawNewRect(renderer, size * 0.985, y + size, xOffset, count);
}

void drawStaticDust(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  float amount = 50;
  for (int i = 0; i < SCREEN_WIDTH; i += (float)SCREEN_WIDTH / amount) {
    drawNewRect(renderer, START_RECT_SIZE, 0, i - (float)SCREEN_WIDTH / 2, 10);
  }
}
