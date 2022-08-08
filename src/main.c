#include <SDL.h>
#include <stdio.h>

#define MAX_ARG_SIZE 100

const int WIDTH = 640;
const int HEIGHT = 480;
const int BALL_SIZE = 30;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Pass an argument to pick piece\n");
    exit(1);
  }
  char *piece = argv[1];

  // int init = SDL_Init(SDL_INIT_VIDEO);
  // if (init != 0) {
  //   fprintf(stderr, "Failed to init %s\n", SDL_GetError());
  //   exit(1);
  // }

  // SDL_Window *window = SDL_CreateWindow("Pong?", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

  // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
  // SDL_RenderClear(renderer);

  // SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
  // SDL_Rect ballRect = {
  //     .x = WIDTH / 2 - BALL_SIZE / 2,
  //     .y = HEIGHT / 2 - BALL_SIZE / 2,
  //     .w = BALL_SIZE,
  //     .h = BALL_SIZE,
  // };
  // SDL_RenderFillRect(renderer, &ballRect);

  // SDL_RenderPresent(renderer);

  // SDL_Event event;
  // while (SDL_WaitEvent(&event)) {
  //   if (event.type == SDL_QUIT) {
  //     break;
  //   }
  // }

  // SDL_Quit();
  return 0;
}