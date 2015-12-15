#import "ball.h"

// Default constructor
Ball::Ball() { }

// Constructor
Ball::Ball(Graphics& graph,std::string spritePath,int w,int h)
{
    sprite = Sprite(graph,spritePath,w,h);
    init();
}

// Draw the sprite of the ball on the screen
void Ball::draw(Graphics& graph)
{
    sprite.draw(graph,x,y);
}

// Set the ball to the center of the screen and set his direction
// (called at the begin or after a player score a point)
void Ball::init()
{
    x = (float)SCREEN_WIDTH/2;
    y = (float)SCREEN_HEIGHT/2;
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
        x+=0.05;
    else
        x-=0.05;

    if (x < 0 || x > SCREEN_WIDTH)
    {
       // Ajouter addScore dépendant de la direction de la balle
       init();
    }
}

Ball::~Ball()
{

}
