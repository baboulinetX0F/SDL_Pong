#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL_ttf.h>

#include "player.h"
#include "ball.h"
#include "text.h"
#include "audio.h"

class Game
{
public:
    Game();
    ~Game();
    void gameLoop();
    void draw(Graphics& graph);
    void handleInput(const Uint8 *keystate);
    void Update();
    void checkScore();
    void UIInit(Graphics& graph);
    void initSound();

private:
    // Game objects
    Player _player1;
    Player _player2;
    Ball _ball;

    // UI / Score Display
    Text textScoreP1;
    Text textScoreP2;
    int scoreP1;
    int scoreP2;

    Audio audioMixer;
    int gameState = 0;      // 0 : Not loaded   1 : Menu    2 : Game

    // Menu
    SDL_Texture* menuTexture = NULL;
    SDL_Rect menuRect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
};

#endif // GAME_H_INCLUDED
