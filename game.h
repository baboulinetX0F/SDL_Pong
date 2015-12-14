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
    Player _player;
    Ball _ball;
};

#endif // GAME_H_INCLUDED
