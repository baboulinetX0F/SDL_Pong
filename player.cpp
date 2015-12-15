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
    this->x=x;
    this->y=y;
}

void Player::draw(Graphics& graph)
{
    this->sprite.draw(graph,this->x,this->y);
}

void Player::moveUp()
{
    this->y-=player_constants::SPEED;
}

void Player::moveDown()
{
    this->y+=player_constants::SPEED;
}

Player::~Player()
{

}
