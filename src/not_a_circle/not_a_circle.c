#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

typedef struct {
  float x;
  float y;
} Point;

/*
[0  1] [x]
[-1 0] [y]
*/

Point rotate90deg(float x, float y) {
  Point p = {.x = 0 * x + 1 * y, .y = (-1) * x + 0 * y};
  return p;
}

void drawNotACircle(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 204, 255, 229, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  float scale = 100;
  float offset = 400;

  float lineAmount = 40;
  float lineSpacing = (M_PI * 2) / lineAmount;
  float lineExtraScale = 1000;

  // Tagent lines
  for (float l = 0; l <= M_PI * 2; l += lineSpacing) {
    Point p1, p2;
    float cX = cos(l) * scale + offset;
    float cY = sin(l) * scale + offset;

    float newX1 = cX - (cos(l) * (scale + lineExtraScale) + offset);
    float newY1 = cY - (sin(l) * (scale + lineExtraScale) + offset);
    float newX2 = cX - (cos(l) * (scale - lineExtraScale) + offset);
    float newY2 = cY - (sin(l) * (scale - lineExtraScale) + offset);

    p1 = rotate90deg(newX1, newY1);
    p2 = rotate90deg(newX2, newY2);

    float finalLx1 = p1.x + cX;
    float finalLy1 = p1.y + cY;
    float finalLx2 = p2.x + cX;
    float finalLy2 = p2.y + cY;

    SDL_RenderDrawLineF(renderer, finalLx1, finalLy1, finalLx2, finalLy2);
  }
}
