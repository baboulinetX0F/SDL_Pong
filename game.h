#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL_ttf.h>

#include "player.h"
#include "ball.h"
#include "text.h"

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

private:
    Player _player1;
    Player _player2;
    Ball _ball;
    Text textScoreP1;
    Text textScoreP2;
    int scoreP1;
    int scoreP2;
};

#endif // GAME_H_INCLUDED
