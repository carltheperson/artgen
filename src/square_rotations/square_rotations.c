#include "./square_rotations.h"

#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

float rotateX(float x, float y, float roation) {
  return x * cos(roation) - y * sin(roation);
}
float rotateY(float x, float y, float roation) {
  return x * sin(roation) + y * cos(roation);
}

void drawSquareRoations(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 234, 253, 207, 255);
  float endSize = 1200;
  float startSize = 10;
  int squareAmount = 90;
  for (int i = 0; i <= squareAmount; i++) {
    float rotation = 0.045 * i;
    // float rotation = 0;
    float size = ((endSize - startSize) / squareAmount) * i;
    float halfSize = size / 2;
    float middleX = SCREEN_WIDTH / 2;
    float middleY = SCREEN_HEIGHT / 2;

    //  c1--c2
    //  |    |
    //  c3--c4
    float c1x = (-halfSize);
    float c1y = (-halfSize);
    float c2x = (+halfSize);
    float c2y = (-halfSize);
    float c3x = (-halfSize);
    float c3y = (+halfSize);
    float c4x = (+halfSize);
    float c4y = (+halfSize);

    float rc1x = rotateX(c1x, c2y, rotation);
    float rc1y = rotateY(c1x, c2y, rotation);
    float rc2x = rotateX(c2x, c2y, rotation);
    float rc2y = rotateY(c2x, c2y, rotation);
    float rc3x = rotateX(c3x, c3y, rotation);
    float rc3y = rotateY(c3x, c3y, rotation);
    float rc4x = rotateX(c4x, c4y, rotation);
    float rc4y = rotateY(c4x, c4y, rotation);

    SDL_Point points[] = {
        {rc1x + middleX, rc1y + middleY},
        {rc2x + middleX, rc2y + middleY},
        {rc4x + middleX, rc4y + middleY},
        {rc3x + middleX, rc3y + middleY},
        {rc1x + middleX, rc1y + middleY},
    };

    SDL_RenderDrawLines(renderer, points, 5);

    // SDL_FRect rect = {
    //     .h = size,
    //     .w = size,
    //     .x = 400 - halfSize,
    //     .y = 400 - halfSize,
    // };
    // SDL_RenderDrawRectF(renderer, &rect);
  }
}