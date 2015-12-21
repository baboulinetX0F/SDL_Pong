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
    void Score(int player_id);
    void UIInit(Graphics& graph);

private:
    Player _player1;
    Player _player2;
    Ball _ball;
    Text scoreP1;
    Text scoreP2;
    int* score; // score[0] = Player 1 SCORE / score[1] = Player 2 SCORE
};

#endif // GAME_H_INCLUDED
