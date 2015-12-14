#include "game.h"
#include "SDL.h"
#include "graphics.h"

#include <stdio.h>

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    this->gameLoop();
}

void Game::gameLoop()
{
    Graphics graphics;
    this->_player = Player(graphics,"img/player.png",15,100);
    SDL_Event e;

    bool quit = false;

    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit=true;
            }
            else if(e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    this->_player.moveUp();
                    printf("KEYBOARD INPUT : UP\n");
                    break;
                case SDLK_DOWN:
                    this->_player.moveDown();
                    printf("KEYBOARD INPUT : DOWN\n");
                    break;
                }
            }
        }
        this->draw(graphics);
    }
}

void Game::draw(Graphics& graph)
{
    graph.clear();

    this->_player.draw(graph);

    graph.flip();
}

Game::~Game()
{
    SDL_Quit();
}
