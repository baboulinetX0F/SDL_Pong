#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "sprite.h"

class Ball
{
public:
    Ball(); // Default constructor
    Ball(Graphics& graph,std::string spritePath,int w,int h);
    ~Ball();
    void draw(Graphics& graph);

private:
    int x;  // Position of the ball
    int y;
    int dx; // Direction of the ball
    int dy;
    int speed;
    Sprite sprite; // Sprite of the ball
};

#endif // BALL_H_INCLUDED
