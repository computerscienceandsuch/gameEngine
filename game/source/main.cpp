#include <iostream>
#include <Engine.h>

#include "SDL.h"

int main(){

    std::cout << "G'day Cobbers" << std::endl;
    Engine::Init();

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        std::cout << "Subsystems Initialised..." << std::endl;


    }

    SDL_Quit();

    return (0);

}