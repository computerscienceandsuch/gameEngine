#include "Game.h"
#include "TexMan.h"
#include "Thing.h"

Game::Game(){}
Game::~Game(){}

const char* thingTex = "assets/blockRect.png";

Thing* thing;

void Game::init(const char* title, int xpos, int ypos, int w, int h, int fs)
{

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        std::cout << "Subsystems Initialised..." << std::endl;

        win = SDL_CreateWindow(title, xpos, ypos, w, h, fs);
        if(win){

            std::cout << "Game Window Initialised..." << std::endl;

        }

        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
        if(ren){
            SDL_SetRenderDrawColor(ren, 74, 44, 42, 255);
            std::cout << "Renderer Initialised..." << std::endl;

        }

        isRunning = true;

    } else {

        isRunning = false;

    }

    thing = new Thing(thingTex, ren, 10, 10);

}


void Game::events()
{

    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* state = SDL_GetKeyboardState(NULL);
    switch(event.type)
    {

        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:

            if(state[SDL_SCANCODE_ESCAPE]){

                isRunning = false;

            }
            break;

        default:
            break;

    }

}

void Game::update()
{
    thing->Update();
}

void Game::render()
{

    SDL_RenderClear(ren);
    
    thing->Draw();

    SDL_RenderPresent(ren);

}

void Game::clean()
{

    SDL_DestroyWindow(win);

    SDL_DestroyRenderer(ren);

    SDL_Quit();

    std::cout << "Renderer Stopped..." << "\n" << "Game Environment Cleaned :)" << std::endl;

}
