#include "Game.h"
#include "TexMan.h"
#include "Thing.h"
#include "Player.h"
#include "Ball.h"

Game::Game(){}
Game::~Game(){}

const char* blockTextureSheet = "assets/blockRect.png";
const char* playerTextureSheet = "assets/playerRect.png";
const char* ballTextureSheet = "assets/ballCircle.png";

int blockW = 50;
int blockH = 25;

Player* player;
Ball* ball;

void Game::init(const char* title, int xpos, int ypos, int w, int h, int fs)
{

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        if(TTF_Init() == 0){

            std::cout << "TTF Initialised..." << std::endl;

        }

        std::cout << "Subsystems Initialised..." << std::endl;

        win = SDL_CreateWindow(title, xpos, ypos, w, h, fs);
        if(win){

            std::cout << "Game Window Initialised..." << std::endl;

        }

        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
        if(ren){
            SDL_SetRenderDrawColor(ren, 0, 0, 80, 255);
            std::cout << "Renderer Initialised..." << std::endl;

        }

        isRunning = true;

    } else {

        isRunning = false;

    }

    player = new Player(playerTextureSheet, ren, 375, 550);
    ball = new Ball(ballTextureSheet, ren, 395, 500);

}

void Game::createLevel(int sizeX, int sizeY)
{

    int size = sizeX * sizeY;
    levelSize = size;
    level = new Thing[size];

    int posX, posY;

    for(int i = 0; i < sizeY; i++){

        for(int j = 0; j < sizeX; j++){

            posX = 100 + (j * (blockW));
            posY = 100 + (i * (blockH));

            level[i * sizeX + j] = Thing(blockTextureSheet, ren, posX, posY);

            //std::cout << level[i*sizeX+j].xpos << " " << level[i*sizeX+j].ypos << std::endl;

        }

    }

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

            }else if(state[SDL_SCANCODE_RETURN]){

                if(SDL_GetRelativeMouseMode() == 0){
                   
                    SDL_SetRelativeMouseMode(SDL_TRUE);
                    SDL_SetWindowGrab(win, SDL_TRUE);
                    std::cout << "Mouse in Relative Mode" << std::endl;
                    SDL_WarpMouseInWindow(win, player->get_xpos(), player->get_ypos());

                } else {
                    
                    SDL_SetWindowGrab(win, SDL_FALSE);
                    SDL_SetRelativeMouseMode(SDL_FALSE);
                    std::cout << "Mouse taken out of Relative Mode" << std::endl;

                }

            }else if(state[SDL_SCANCODE_R]){

                this->reset();

            }

        default:
            break;

    }

}

void Game::update()
{

    player->Update();

    ball->Update(player->get_xpos(), player->get_yLevel(), 50, level, levelSize);
    //std :: cout << player->get_xpos() << " " << player->get_yLevel() << std::endl;

    for(int i = 0; i < levelSize; i++){

        level[i].Update();

    }

    if(ball->isOut == true){

        this->reset();

    }

}

void Game::render()
{

    SDL_RenderClear(ren);

    player->Draw();
    ball->Draw();

    for(int i = 0; i < levelSize; i++){

        level[i].Draw();

    }

    SDL_RenderPresent(ren);

}

void Game::clean()
{

    delete [] level;
    delete player;
    delete ball;

    std::cout << "\n" << "Level, Player & Ball destroyed..." << std::endl;

    SDL_DestroyWindow(win);

    SDL_DestroyRenderer(ren);

    SDL_Quit();

    TTF_Quit();

    std::cout << "Renderer Stopped..." << "\n" << "Game Environment Cleaned :)" << std::endl;

}

void Game::reset()
{

    delete [] level;
    delete player;
    delete ball;

    std::cout << "Level Resetting..." << std::endl;

    player = new Player(playerTextureSheet, ren, 375, 550);
    ball = new Ball(ballTextureSheet, ren, 395, 500);

    SDL_SetRelativeMouseMode(SDL_FALSE);

    this->createLevel(12, 8);

}