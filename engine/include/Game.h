#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Game
{

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int w, int h, int fs);

    void events();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;};

private:
    bool isRunning;
    SDL_Window* win;
    SDL_Renderer* ren;

};

#endif