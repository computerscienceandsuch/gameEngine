#ifndef THING_H
#define THING_H

#include "SDL.h"
#include "SDL_image.h"

class Thing
{

public:

    Thing();
    Thing(const char* filename, SDL_Renderer* renderer, int x, int y);
    ~Thing();

    void Update();
    void Draw();

    int xpos;
    int ypos;

    int get_xpos();
    int get_ypos();

    SDL_Texture* thingTexture;
    SDL_Rect sRect, dRect;
    SDL_Renderer* ren;

};

#endif