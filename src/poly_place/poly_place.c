#include "./poly_place.h"

#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

float getY(float x, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) {
  float term1 = p1y * (((x - p2x) * (x - p3x)) /
                       ((p1x - p2x) * (p1x - p3x)));
  float term2 = p2y * (((x - p1x) * (x - p3x)) /
                       ((p2x - p1x) * (p2x - p3x)));
  float term3 = p3y * (((x - p1x) * (x - p2x)) /
                       ((p3x - p1x) * (p3x - p2x)));
  return term1 + term2 + term3;
}

float rr(float min, float max) {
  return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

void drawPolyPlace(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  float y1 = rr(50, 100);
  float y2 = rr(100, 150);
  float y3 = rr(100, 250);
  float x1 = rr(1, SCREEN_WIDTH / 3);
  float x2 = rr(x1 + 25, (SCREEN_WIDTH / 2) * 1.5);
  float x3 = rr(x2 + 50, SCREEN_WIDTH);
  for (int i = 0; i < 500; i++) {
    y1 += 1.5;
    y3 += 1.5;
    y3 += 1.5;
    x1 += 1.5;
    x2 += 1.5;
    x3 += 1.5;
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      SDL_FRect rect = {
          .h = 1,
          .w = 1,
          .x = x,
          .y = getY(x, x1, y1, x2, y2, x3, y3),
      };
      SDL_RenderDrawRectF(renderer, &rect);
    }
  }
}