#ifndef BITMAPFONT_H
#define BITMAPFONT_H

#include <SDL.h>
#include <string>
#include <unordered_map>

class BitmapFont
{
   public:
    BitmapFont();
    ~BitmapFont();

    bool load(SDL_Renderer* renderer, const std::string& path, int charWidth, int charHeight,
              int charsPerRow);
    void setCharset(const std::string& charset);
    void drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, int scale = 1);

   private:
    SDL_Texture* texture;
    int charWidth;
    int charHeight;
    int charsPerRow;

    std::unordered_map<char, int> charMap;
};

#endif
