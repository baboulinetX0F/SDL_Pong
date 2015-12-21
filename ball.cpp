#import "ball.h"

namespace ball_constants
{
    const float SPEED_X = 0.05;
    const float SPEED_Y = 0.05;
}

// Default constructor
Ball::Ball() { }

// Constructor
Ball::Ball(Graphics& graph,std::string spritePath,int w,int h)
{
    sprite = Sprite(graph,spritePath,w,h);
    pos.w = w;
    pos.h = h;
    d_y=0;
    d_x=ball_constants::SPEED_X;
    init();
}

// Draw the sprite of the ball on the screen
void Ball::draw(Graphics& graph)
{
    sprite.draw(graph,pos.x,pos.y);
}

// Set the ball to the center of the screen and set his direction
// (called at the begin or after a player score a point)
void Ball::init()
{
    pos.x = (float)SCREEN_WIDTH/2;
    pos.y = (float)SCREEN_HEIGHT/2;
    d_y=0;
    if (d_x < 0)
        d_x = ball_constants::SPEED_X;
    else
        d_x = -ball_constants::SPEED_X;
}

void Ball::invertDx()
{
    d_x = -(d_x);
}

void Ball::setDy(float y)
{
    d_y=y;
}


// Update the position of the ball based on this direction at each call
// and check if the ball is outside the screen
// return 1 if the player 1 score / return 2 if the player 2 score
void Ball::Update()
{
    pos.x+=d_x;
    pos.y+=d_y;

    if (pos.x < 0)
    {
       init();
    }
    else if (pos.x > SCREEN_WIDTH)
    {
        init();
    }
    if (pos.y <= 0)
    {
        setDy(ball_constants::SPEED_Y);
    }
    if (pos.y >= SCREEN_HEIGHT)
    {
        setDy(-ball_constants::SPEED_Y);
    }
}

struct Position Ball::getPos()
{
    return pos;
};

Ball::~Ball()
{

}
