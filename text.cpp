#include "text.h"
#include <sstream>


Text::Text() {} // Default constructor (not used)

Text::~Text() {} // Default Destructor

Text::Text(Graphics& graph, std::string fontName, int fontSize, std::string defaultText,int base_x, int base_y)
{
    this->font = TTF_OpenFont(fontName.c_str(),fontSize);
    this->fontColor = {255,255,255};
    this->x = base_x; // Added later into the constructor parameters
    this->y = base_y;
    this->w=0;
    this->h=0;
    editText(defaultText.c_str());
}

// editText : Edit the text to be displayed by this text object
void Text::editText (std::string newText)
{
    this->currentText = newText;
    this->renderCall = true;    // Since the text have changed, the texture need to be re-rendered at the next draw call
}

// draw : Draw the text on the screen
void Text::draw(Graphics& graph)
{
    // If the texture need to be rendered again
    if (this->renderCall)
    {
        SDL_Surface* tmpSurface = TTF_RenderText_Solid(this->font,this->currentText.c_str(),this->fontColor);
        this->fontTexture = SDL_CreateTextureFromSurface(graph.getRenderer(),tmpSurface);
        SDL_FreeSurface(tmpSurface);
        SDL_QueryTexture(this->fontTexture,NULL,NULL,&this->w,&this->h);
        this->renderCall = false;
    }

    SDL_Rect destRect;
    destRect.x = this->x;
    destRect.y = this->y;
    destRect.w = this->w;
    destRect.h = this->h;
    graph.blitSurface(this->fontTexture,&destRect);
}

// intToString : convert an Integer into a string
std::string intToString(int input)
{
    std::string output;
    std::stringstream ss;
    ss << input;
    output = ss.str();

    return output;
}
