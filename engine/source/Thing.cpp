#include "Thing.h"
#include "TexMan.h"

Thing::Thing(){}
Thing::Thing(const char* filename, SDL_Renderer* renderer, int x, int y)
{

    ren = renderer;
    thingTexture = TexMan::LoadTexture(filename, renderer);

    xpos = x;
    ypos = y;

}

void Thing::Update()
{
    
    sRect.w = 800;
    sRect.h = 400;

    sRect.x = 0;
    sRect.y = 0;

    dRect.x = xpos;
    dRect.y = ypos;
    dRect.w = sRect.w / 16;
    dRect.h = sRect.h / 16;


}

void Thing::Draw()
{

    SDL_RenderCopy(ren, thingTexture, &sRect, &dRect);

}

int Thing::get_xpos() {
    return xpos;
}

int Thing::get_ypos() {
    return ypos;
}