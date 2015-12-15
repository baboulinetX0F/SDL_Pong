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
    void init(); // Reinitialize the ball when an user score a point
    void Update();

private:
    float x;  // Position of the ball
    float y;
    bool direction = false;
    Sprite sprite; // Sprite of the ball
};

#endif // BALL_H_INCLUDED
