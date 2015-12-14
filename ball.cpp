#import "ball.h"

Ball::Ball() { }

Ball::Ball(Graphics& graph,std::string spritePath,int w,int h)
{
    sprite = Sprite(graph,spritePath,w,h);
    x = SCREEN_WIDTH/2;
    y = SCREEN_HEIGHT/2;
}

void Ball::draw(Graphics& graph)
{
    sprite.draw(graph,x,y);
}

Ball::~Ball()
{

}
