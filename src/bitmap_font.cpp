#include "bitmap_font.h"
#include <SDL_image.h>
#include "logger.h"
#include "string_utils.h"

void BitmapFont::drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, int scale)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        char c = text[i];
        auto it = charMap.find(c);
        if (it == charMap.end())
            continue;  // Character not found

        int index = it->second;

        SDL_Rect srcRect = {(index % charsPerRow) * charWidth, (index / charsPerRow) * charHeight,
                            charWidth, charHeight};

        SDL_Rect dstRect = {x + static_cast<int>(i * charWidth * scale), y, charWidth * scale,
                            charHeight * scale};

        SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
    }
}

void BitmapFont::setCharset(const std::string& charset)
{
    charMap.clear();
    for (size_t i = 0; i < charset.size(); ++i)
    {
        charMap[charset[i]] = static_cast<int>(i);
    }
}

BitmapFont::~BitmapFont() {}
