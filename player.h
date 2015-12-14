#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <string.h>

#include "graphics.h"
#include "sprite.h"

class Player
{
public:
    Player(); // Default Constructor
    Player(Graphics& graph,std::string spritePath,int w, int h);
    ~Player();
    void draw(Graphics& graphics);
    void moveUp();
    void moveDown();

private:
    int x;
    int y;
    Sprite sprite;
};

#endif // PLAYER_H_INCLUDED
