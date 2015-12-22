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
    float d_x;  // Direction of the ball on the x/y axis
    float d_y;
    Sprite sprite; // Sprite of the ball
    int pendingPoint = 0;   // 0 = No point to add  1:Player1 scored  2:Player2 scored
};

#endif // BALL_H_INCLUDED
