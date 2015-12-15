#import "ball.h"

Ball::Ball() { }

Ball::Ball(Graphics& graph,std::string spritePath,int w,int h)
{
    sprite = Sprite(graph,spritePath,w,h);
    x = (float)SCREEN_WIDTH/2;
    y = (float)SCREEN_HEIGHT/2;
}

void Ball::draw(Graphics& graph)
{
    sprite.draw(graph,x,y);
}

void Ball::init()
{
    if (!direction)
        direction = true;
    else
        direction = false;
}

void Ball::Update()
{
    if (direction)
        x+=0.05;
    else
        x-=0.05;
}

Ball::~Ball()
{

}
