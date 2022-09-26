#include "TexMan.h"

SDL_Texture* TexMan::LoadTexture(const char* filename, SDL_Renderer* renderer)
{

    SDL_Surface* tempSurf = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurf);
    SDL_FreeSurface(tempSurf);

    return tex;

}