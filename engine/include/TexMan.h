#ifndef TEXMAN_H
#define TEXMAN_H

#include "SDL.h"
#include "SDL_image.h"

class TexMan
{

    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);

};

#endif