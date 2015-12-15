#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Graphics& graph, std::string spritePath,int width,int height)
{
    this->texture = graph.loadImage(spritePath);
    this->sourceRect = {0,0,width,height};
}

void Sprite::draw(Graphics& graph,float x,float y)
{
    SDL_Rect dest_rect = { x,y, this->sourceRect.w, this->sourceRect.h};
    graph.blitSurface(this->texture,&dest_rect);
}

Sprite::~Sprite()
{

}


