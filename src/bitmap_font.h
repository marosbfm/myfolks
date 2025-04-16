#ifndef BITMAPFONT_H
#define BITMAPFONT_H

#include <SDL.h>
#include <string>
#include <unordered_map>

class BitmapFont
{
   public:
    BitmapFont(int charWidth, int charHeight, int charsPerRow)
        : charWidth(charWidth), charHeight(charHeight), charsPerRow(charsPerRow){};
    virtual ~BitmapFont() = 0;

    void drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, int scale = 1);
    virtual bool init() = 0;

   protected:
    SDL_Texture* texture;
    int charWidth;
    int charHeight;
    int charsPerRow;
    std::unordered_map<char, int> charMap;

    void setCharset(const std::string& charset);
};

#endif
