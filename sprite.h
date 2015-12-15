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

// Structure to remplace SDL_Rect to have a float type instead of int for x and y
// h and y remains unchanged
struct Position
{
    float x;
    float y;
    int w;
    int h;
};

#endif // SPRITE_H_INCLUDED
