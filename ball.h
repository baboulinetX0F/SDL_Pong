#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "sprite.h"
#include "SDL.h"

class Ball
{
public:
    Ball(); // Default constructor
    Ball(Graphics& graph,std::string spritePath,int w,int h);
    ~Ball();
    void draw(Graphics& graph);
    void init();
    void Update();
    struct Position getPos();
    void changeDirection();

private:
    struct Position pos;
    bool direction = false;
    Sprite sprite; // Sprite of the ball
};

#endif // BALL_H_INCLUDED
