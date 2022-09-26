#include <iostream>

#include "Game.h"
using namespace std;

Game *game = nullptr;

int main() { 

  const int FPS = 240;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;
  
  game = new Game(); 

  game->init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

  while(game->running()){

    frameStart = SDL_GetTicks();

    game->events();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime){

      SDL_Delay(frameDelay - frameTime); //Frame rate limiter! 

    }

  }

  game->clean();

  delete game;

  return (0);
  
}