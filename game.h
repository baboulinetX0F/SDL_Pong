#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "player.h"

class Game
{
public:
    Game();
    ~Game();
    void gameLoop();
    void draw(Graphics& graph);

private:
    Player _player;
};

#endif // GAME_H_INCLUDED
