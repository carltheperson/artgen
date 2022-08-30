#include "./main.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./circle_explosion/circle_explosion.h"
#include "./line_tiles/line_tiles.h"
#include "./poly_place/poly_place.h"
#include "./static_dust/static_dust.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Pass an argument to pick piece\n");
    exit(1);
  }
  char *piece = argv[1];

  int init = SDL_Init(SDL_INIT_VIDEO);
  if (init != 0) {
    fprintf(stderr, "Failed to init %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window *window = SDL_CreateWindow(piece, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

  srand(time(NULL));

  if (strcmp(piece, "line_tiles") == 0) {
    drawLineTiles(renderer);
  } else if (strcmp(piece, "static_dust") == 0) {
    drawStaticDust(renderer);
  } else if (strcmp(piece, "poly_place") == 0) {
    drawPolyPlace(renderer);
  } else if (strcmp(piece, "circle_explosion") == 0) {
    drawCircleExplosion(renderer);
  } else {
    printf("Unkown peice\n");
    exit(1);
  }

  SDL_RenderPresent(renderer);

  SDL_Event event;
  while (SDL_WaitEvent(&event)) {
    if (event.type == SDL_QUIT) {
      break;
    }
  }

  SDL_Quit();
  return 0;
}