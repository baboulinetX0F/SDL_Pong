#include "player.h"

namespace player_constants
{
    const float SPEED = 0.1;
}

Player::Player()    // Default Constructor (not used)
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

// draw : Use to draw the player on the screen
void Player::draw(Graphics& graph)
{
    this->sprite.draw(graph,this->pos.x,this->pos.y);
}

/////////////////////////// MOUVEMENT //////////////////////////////
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

// getPos : return the position of the player (with a Position struct)
struct Position Player::getPos()
{
    return pos;
};

// reinit : Replace the player to his initial position
void Player::reinit()
{
    this->pos.y = SCREEN_HEIGHT/2 - this->pos.h/2;
}

Player::~Player()
{

}
