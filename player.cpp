#include "player.h"

namespace player_constants
{
    const float SPEED = 0.1;
}

Player::Player()
{

}

Player::Player(Graphics& graph,std::string spritePath,int w,int h, float x, float y)
{
    this->sprite = Sprite(graph,spritePath,w,h);
    this->pos.x=x;
    this->pos.y=y;
    this->pos.w=w;
    this->pos.h=h;
}

void Player::draw(Graphics& graph)
{
    this->sprite.draw(graph,this->pos.x,this->pos.y);
}

void Player::moveUp()
{
    if (this->pos.y>0)
        this->pos.y-=player_constants::SPEED;
}

void Player::moveDown()
{
    if (this->pos.y<=SCREEN_HEIGHT-100)
        this->pos.y+=player_constants::SPEED;
}

struct Position Player::getPos()
{
    return pos;
};

Player::~Player()
{

}
