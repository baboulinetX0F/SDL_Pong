#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "player.h"
#include "ball.h"

class Game
{
public:
    Game();
    ~Game();
    void gameLoop();
    void draw(Graphics& graph);

private:
    Player _player1;
    Player _player2;
    Ball _ball;
};

#endif // GAME_H_INCLUDED
