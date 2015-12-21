#include "text.h"


Text::Text() {} // Default constructor (not used)

Text::~Text() {} // Default Destructor

Text::Text(Graphics& graph, std::string fontName, int fontSize, std::string defaultText)
{
    this->font = TTF_OpenFont(fontName.c_str(),fontSize);
    this->fontColor = {255,255,255};
    SDL_Surface* tmpSurface = TTF_RenderText_Blended(this->font,this->currentText.c_str(),this->fontColor);
    this->fontTexture = SDL_CreateTextureFromSurface(graph.getRenderer(),tmpSurface);
    SDL_FreeSurface(tmpSurface);
    this->x = 200; // Added later into the constructor parameters
    this->y = 200;
}

void Text::editText (std::string newText)
{
    this->currentText = newText;
    this->renderCall = true;    // Since the text have changed, the texture need to be re-rendered at the next draw call
}

void Text::draw(Graphics& graph)
{
    // If the texture need to be rendered again
    if (this->renderCall)
    {
        SDL_Surface* tmpSurface = TTF_RenderText_Blended(this->font,this->currentText.c_str(),this->fontColor);
        this->fontTexture = SDL_CreateTextureFromSurface(graph.getRenderer(),tmpSurface);
        SDL_FreeSurface(tmpSurface);
        this->renderCall = false;
    }

    SDL_Rect destRect;
    destRect.x = this->x;
    destRect.y = this->y;
    graph.blitSurface(this->fontTexture,&destRect);
}
