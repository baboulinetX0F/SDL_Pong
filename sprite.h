#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <SDL.h>
#include "graphics.h"

class Sprite
{
public:
    Sprite();
    Sprite(Graphics& graph,std::string spritePath,int width,int height);
    void draw(Graphics& graphics,float x,float y);
    ~Sprite();

private:
    SDL_Texture* texture;
    SDL_Rect sourceRect;
    Graphics* graphics;
};

#endif // SPRITE_H_INCLUDED
