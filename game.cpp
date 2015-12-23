#include "game.h"
#include "SDL.h"
#include "graphics.h"
#include "sprite.h"

#include <stdio.h>
#include <stdlib.h>

// Default Constructor : Initialize everything (SDL,IMG,TTF,sounds) and launch the gameloop
Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    this->initSound();
    this->gameLoop();
}

// initSound : Load all the sounds use in the game
void Game::initSound()
{
    audioMixer.loadSound("sounds/paddle_hit.wav");
    audioMixer.loadSound("sounds/paddle_hit2.wav");
}

// checkCollision : Return true if the object a is in collision with the object b
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
    Graphics graphics;  // Initialize the graphics object

    // Intialisation of the game objects (player's paddle + ball)
    this->_player1 = Player(graphics,"img/player.png",15,100,30,SCREEN_HEIGHT/2 - 50);
    this->_player2 = Player(graphics,"img/player.png",15,100,SCREEN_WIDTH - 30,SCREEN_HEIGHT/2 - 50);
    this->_ball = Ball(graphics,"img/ball.png",10,10);

    // Init the score count
    this->scoreP1 = 0;
    this->scoreP2 = 0;

    this->initUI(graphics);
    this->menuTexture = graphics.loadImage("img/menu.png");

    SDL_Event e;

    bool quit = false;
    gameState = 1;      // Change the gamestate to 1 (Title) when everything is initialized

    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit=true;
            }
            // When a key is pressed during the title screen Gamestate, go to Game gamestation
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

// checkScore : Called at every update to check if a player scored
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

// reinitObjects : Replace the game objects when called (called after a point is scored)
void Game::reinitObjects()
{
    this->_player1.reinit();
    this->_player2.reinit();

    Uint32 startTime;
    startTime = SDL_GetTicks();

    this->_ball.init();
    SDL_Delay(500);
}

// initUI : Initialize all the object UI related (Text objects in our case for the score display)
void Game::initUI(Graphics& graph)
{
    this->textScoreP1 = Text(graph,"font/Retro.ttf",24,intToString(scoreP1),SCREEN_WIDTH/4,20);
    this->textScoreP2 = Text(graph,"font/Retro.ttf",24,intToString(scoreP2),(SCREEN_WIDTH/4) * 3,20);
}

// Update : Calls all the update functions of the differents game objects
void Game::Update()
{
    // Check if we are in the Game gamestate
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
                //printf("DEBUG : BALL HIT P1 TOP\n");
            }
            else if (_ball.getPos().y >= _player1.getPos().y + _player1.getPos().h / 3 && _ball.getPos().y <= _player1.getPos().y + _player1.getPos().h / 2)
            {
                _ball.setDy(0);
                //printf("DEBUG : BALL HIT P1 MID\n");
            }
            else
            {
                _ball.setDy(0.05);
                //printf("DEBUG : BALL HIT P1 BOTTOM\n");
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
                //printf("DEBUG : BALL HIT P2 TOP\n");
            }
            else if (_ball.getPos().y >= _player2.getPos().y + _player2.getPos().h / 3 && _ball.getPos().y <= _player2.getPos().y + _player2.getPos().h / 2)
            {
                _ball.setDy(0);
                //printf("DEBUG : BALL HIT P2 MID\n");
            }
            else
            {
                _ball.setDy(0.05);
                //printf("DEBUG : BALL HIT P2 BOTTOM\n");
            }
            _ball.invertDx();
            audioMixer.playSound("sounds/paddle_hit2.wav");
        }
    }
    }

}

// handleInput : Handle the user's keyboard input
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

    // When gamestate is menu, only draw titlemenu texture
    if (gameState == 1)
    {
        graph.blitSurface(this->menuTexture,&this->menuRect);
    }

    // When gamestate is game, draw all the gameobject and UI
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
