#include "./circle_explosion.h"

#include <SDL.h>
#include <stdlib.h>

#include "../main.h"

void drawCircleExplosion(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 85, 255);
  SDL_RenderClear(renderer);
  float scale = 400;
  float interval = 0.003;
  float offset = 400;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  float ringSpacing = 20;
  float maxRings = 100;
  for (float ring = 0; ring < maxRings; ring++) {
    for (float r = 0; r < M_PI * 2; r += interval) {
      float x = cos(r) + sin(r) * 0.5;
      float y = sin(r) + cos(r) * 0.1;
      SDL_FRect rect = {
          .h = 1,
          .w = 1,
          .x = offset + x * (ring * ringSpacing),
          .y = offset + y * (ring * ringSpacing),
      };
      SDL_RenderDrawRectF(renderer, &rect);
    }
  }

  float lineInterval = 0.1;
  for (float l = 0; l < M_PI * 2; l += lineInterval) {
    float lx1 = (cos(l) + sin(l) * 0.1) * (SCREEN_WIDTH * 2) + offset;
    float ly1 = (sin(l) + cos(l) * 0.1) * (SCREEN_HEIGHT * 2) + offset;
    float lx2 = (SCREEN_WIDTH / 2);
    float ly2 = (SCREEN_HEIGHT / 2);
    SDL_RenderDrawLineF(renderer, lx1, ly1, lx2, ly2);
  }
}