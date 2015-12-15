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

// Main Game Loop
void Game::gameLoop()
{
    Graphics graphics;
    this->_player1 = Player(graphics,"img/player.png",15,100,30,SCREEN_HEIGHT/2 - 50);
    this->_player2 = Player(graphics,"img/player.png",15,100,SCREEN_WIDTH - 30,SCREEN_HEIGHT/2 - 50);
    this->_ball = Ball(graphics,"img/ball.png",10,10);
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
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        handleInput(currentKeyStates);

        this->Update();
        this->draw(graphics);
    }
}

// Calls all the update functions of the differents game objects
void Game::Update()
{
    this->_ball.Update();
}

// Handle the keyboard input
void Game::handleInput(const Uint8 *keystate)
{
    if (keystate[SDL_SCANCODE_UP])
    {
        this->_player1.moveUp();
        printf("KEYBOARD INPUT : UP\n");
    }
    if (keystate[SDL_SCANCODE_DOWN])
    {
        this->_player1.moveDown();
        printf("KEYBOARD INPUT : DOWN\n");
    }
    if (keystate[SDL_SCANCODE_W])
    {
        this->_player2.moveUp();
        printf("KEYBOARD INPUT : z\n");
    }
    if (keystate[SDL_SCANCODE_S])
    {
        this->_player2.moveDown();
        printf("KEYBOARD INPUT : s\n");
    }

}

// Draw all the differents games objects
void Game::draw(Graphics& graph)
{
    graph.clear();

    this->_player1.draw(graph);
    this->_player2.draw(graph);
    this->_ball.draw(graph);

    graph.flip();
}

Game::~Game()
{
    SDL_Quit();
}
