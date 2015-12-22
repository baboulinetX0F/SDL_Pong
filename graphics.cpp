#include "graphics.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


// Default Constructor : Create the window and the renderer
Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,NULL,&this->window,&this->renderer);
    SDL_SetWindowTitle(this->window,"SDLPong");
    SDL_SetRenderDrawColor(this->renderer,0,0,0,0);
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

////////////////////////// ACCESSORS ///////////////////////////////////////////////////////
SDL_Renderer* Graphics::getRenderer()
{
    return this->renderer;
}


void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->renderer);
}


// loadImage : Loads an image located on the path passed on parameter and stock it on the map
// if it's not previously load
SDL_Texture* Graphics::loadImage(std::string path)
{
    // if the image was not previously load, we stock it on the map
    if (this->_sprites.count(path)==0)
    {
        SDL_Surface* tmp_surface = NULL;
        tmp_surface = IMG_Load(path.c_str());
        this->_sprites[path] = SDL_CreateTextureFromSurface(this->renderer,tmp_surface);
        SDL_FreeSurface(tmp_surface);
        tmp_surface=NULL;
    }

    // else we return the image already load from the map
    return this->_sprites[path];
}


// Blit a texture passed on param1 to the position indicated by the rectangle passed on param2
void Graphics::blitSurface(SDL_Texture* texture,SDL_Rect* dest_rect)
{
    SDL_RenderCopy(this->renderer,texture,NULL,dest_rect);
}

