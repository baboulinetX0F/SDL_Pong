#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "graphics.h"

class Text
{
public:
    Text();
    ~Text();
    Text(Graphics& graph,std::string fontName,int fontSize,std::string defaultText);
    void editText(std::string newText);
    void draw(Graphics& graph);

private:
    TTF_Font* font;
    SDL_Texture* fontTexture;
    SDL_Color fontColor;
    std::string currentText;
    bool renderCall = false;            // To know if the text texture need to be re-rendered (ex. When the text is changed)
    int x;
    int y;


};

#endif // TEXT_H_INCLUDED
