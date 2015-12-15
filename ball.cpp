#import "ball.h"

namespace ball_constants
{
    const float SPEED = 0.05;
}

// Default constructor
Ball::Ball() { }

// Constructor
Ball::Ball(Graphics& graph,std::string spritePath,int w,int h)
{
    sprite = Sprite(graph,spritePath,w,h);
    pos.w = w;
    pos.h = h;
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
    if (!direction)
        direction = true;
    else
        direction = false;
}

// Update the position of the ball based on this direction at each call
// and check if the ball is outside the screen
void Ball::Update()
{
    if (direction)
        pos.x+=ball_constants::SPEED;
    else
        pos.x-=ball_constants::SPEED;

    if (pos.x < 0 || pos.x > SCREEN_WIDTH)
    {
       // Ajouter addScore dépendant de la direction de la balle
       init();
    }
}

Ball::~Ball()
{

}
