#include "game.h"
#include "SDL.h"
#include "graphics.h"
#include "sprite.h"
#include <SDL_mixer.h>

#include <stdio.h>
#include <stdlib.h>

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    this->initSound();
    this->gameLoop();
}

void Game::initSound()
{
    audioMixer.loadSound("sounds/paddle_hit.wav");
    audioMixer.loadSound("sounds/paddle_hit2.wav");
}

bool checkCollision(struct Position a, struct Position b)
{
    float leftA,leftB;
    float topA,topB;
    float rightA,rightB;
    float bottomA,bottomB;

    leftA = a.x;
    leftB = b.x;
    topA = a.y;
    topB = b.y;
    rightA = a.x + a.w;
    rightB = b.x + b.w;
    bottomA= a.y + a.h;
    bottomB= b.y + b.h;

    if (bottomA <= topB)
        return false;
    if (topA >= bottomB)
        return false;
    if(rightA <= leftB)
        return false;
    if(leftA >= rightB)
        return false;

    return true;
}

// Main Game Loop
void Game::gameLoop()
{
    Graphics graphics;
    this->_player1 = Player(graphics,"img/player.png",15,100,30,SCREEN_HEIGHT/2 - 50);
    this->_player2 = Player(graphics,"img/player.png",15,100,SCREEN_WIDTH - 30,SCREEN_HEIGHT/2 - 50);
    this->_ball = Ball(graphics,"img/ball.png",10,10);
    this->scoreP1 = 0;
    this->scoreP2 = 0;
    this->UIInit(graphics);
    this->menuTexture = graphics.loadImage("img/menu.png");
    SDL_Event e;

    bool quit = false;
    gameState = 1;


    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit=true;
            }
             if (gameState == 1 && e.type == SDL_KEYDOWN)
            {
                gameState = 2;
            }
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

               handleInput(currentKeyStates);

        this->Update();
        this->draw(graphics);
    }
}

void Game::checkScore()
{
    if (_ball.getPendingPoint()==2)
    {
        scoreP2++;
        this->textScoreP2.editText(intToString(scoreP2));
        _ball.resetPendingPoint();
        reinitObjects();
    }
    else if (_ball.getPendingPoint()==1)
    {
         scoreP1++;
         this->textScoreP1.editText(intToString(scoreP1));
         _ball.resetPendingPoint();
         reinitObjects();
    }
}

void Game::reinitObjects()
{
    this->_player1.reinit();
    this->_player2.reinit();

    Uint32 startTime;
    startTime = SDL_GetTicks();

    this->_ball.init();
    SDL_Delay(500);
}


void Game::UIInit(Graphics& graph)
{
    this->textScoreP1 = Text(graph,"font/Retro.ttf",24,intToString(scoreP1),SCREEN_WIDTH/4,20);
    this->textScoreP2 = Text(graph,"font/Retro.ttf",24,intToString(scoreP2),(SCREEN_WIDTH/4) * 3,20);
}

// Calls all the update functions of the differents game objects
void Game::Update()
{
    if (gameState == 2)
    {
    this->_ball.Update();

    checkScore();

    if (checkCollision(_ball.getPos(),_player1.getPos()))
    {
        if (_ball.getPos().x >= _player1.getPos().x + _player1.getPos().w/2)
        {
            if (_ball.getPos().y >= _player1.getPos().y && _ball.getPos().y <= _player1.getPos().y + _player1.getPos().h / 3)
            {
                _ball.setDy(-0.05);
                printf("DEBUG : BALL HIT P1 TOP\n");
            }
            else if (_ball.getPos().y >= _player1.getPos().y + _player1.getPos().h / 3 && _ball.getPos().y <= _player1.getPos().y + _player1.getPos().h / 2)
            {
                _ball.setDy(0);
                printf("DEBUG : BALL HIT P1 MID\n");
            }
            else
            {
                _ball.setDy(0.05);
                printf("DEBUG : BALL HIT P1 BOTTOM\n");
            }
            _ball.invertDx();
            audioMixer.playSound("sounds/paddle_hit.wav");
        }
    }
    else  if (checkCollision(_ball.getPos(),_player2.getPos()))
    {
        if (_ball.getPos().x <= _player2.getPos().x - _player2.getPos().w/2)
        {
            if (_ball.getPos().y >= _player2.getPos().y && _ball.getPos().y <= _player2.getPos().y + _player2.getPos().h / 3)
            {
                _ball.setDy(-0.05);
                printf("DEBUG : BALL HIT P2 TOP\n");
            }
            else if (_ball.getPos().y >= _player2.getPos().y + _player2.getPos().h / 3 && _ball.getPos().y <= _player2.getPos().y + _player2.getPos().h / 2)
            {
                _ball.setDy(0);
                printf("DEBUG : BALL HIT P2 MID\n");
            }
            else
            {
                _ball.setDy(0.05);
                printf("DEBUG : BALL HIT P2 BOTTOM\n");
            }
            _ball.invertDx();
            audioMixer.playSound("sounds/paddle_hit2.wav");
        }
    }
    }

}

// Handle the keyboard input
void Game::handleInput(const Uint8 *keystate)
{
    if (keystate[SDL_SCANCODE_UP])
    {
        this->_player2.moveUp();
    }
    if (keystate[SDL_SCANCODE_DOWN])
    {
        this->_player2.moveDown();
    }
    if (keystate[SDL_SCANCODE_W])
    {
        this->_player1.moveUp();
    }
    if (keystate[SDL_SCANCODE_S])
    {
        this->_player1.moveDown();
    }

}

// Draw all the differents games objects
void Game::draw(Graphics& graph)
{
    graph.clear();

    if (gameState == 1)
    {
        graph.blitSurface(this->menuTexture,&this->menuRect);
    }
    if (gameState == 2)
    {
        this->_player1.draw(graph);
        this->_player2.draw(graph);
        this->_ball.draw(graph);
        this->textScoreP1.draw(graph);
        this->textScoreP2.draw(graph);
    }

    graph.flip();
}

Game::~Game()
{
    SDL_Quit();
}
