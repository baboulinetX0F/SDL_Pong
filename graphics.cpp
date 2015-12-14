#include "graphics.h"

#include <SDL.h>
#include <SDL_image.h>

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

void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->renderer);
}

SDL_Texture* Graphics::loadImage(std::string path)
{
    // if the image was not previously load
    if (this->_sprites.count(path)==0)
    {
        SDL_Surface* tmp_surface = NULL;
        tmp_surface = IMG_Load(path.c_str());
        this->_sprites[path] = SDL_CreateTextureFromSurface(this->renderer,tmp_surface);
        SDL_FreeSurface(tmp_surface);
        tmp_surface=NULL;
    }

    return this->_sprites[path];
}

void Graphics::blitSurface(SDL_Texture* texture,SDL_Rect* dest_rect)
{
    SDL_RenderCopy(this->renderer,texture,NULL,dest_rect);
}
