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
    void invertDx();
    void setDy(float y);
    int getPendingPoint();
    void resetPendingPoint();

private:
    struct Position pos;
    float d_x;
    float d_y;
    Sprite sprite; // Sprite of the ball
    int pendingPoint = 0;
};

#endif // BALL_H_INCLUDED
