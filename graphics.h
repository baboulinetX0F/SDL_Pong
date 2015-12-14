#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <SDL.h>
#include <map>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics
{
public:
    Graphics();
    ~Graphics();
    void flip();
    void clear();
    SDL_Texture* loadImage(std::string path);
    void blitSurface(SDL_Texture* texture,SDL_Rect* dest_rect);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::map<std::string,SDL_Texture*> _sprites;
};

#endif // GRAPHICS_H_INCLUDED
