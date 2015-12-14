#include "player.h"

namespace player_constants
{
    const int SPEED = 10;
}

Player::Player()
{

}


Player::Player(Graphics& graph,std::string spritePath,int w,int h)
{
    this->sprite = Sprite(graph,spritePath,w,h);
    this->x=200;
    this->y=200;
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
