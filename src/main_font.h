#ifndef MAIN_FONT_H
#define MAIN_FONT_H

#include "bitmap_font.h"

class MainFont : public BitmapFont
{
   public:
    MainFont() : BitmapFont(CHAR_WIDTH, CHAR_HEIGHT, CHARS_PER_ROW) {}
    MainFont(int charWidth, int charHeight, int charsPerRow)
        : BitmapFont(charWidth, charHeight, charsPerRow)
    {
    }
    ~MainFont() = default;

    bool init() override;

   private:
    static constexpr int CHAR_WIDTH = 12;
    static constexpr int CHAR_HEIGHT = 12;
    static constexpr int CHARS_PER_ROW = 10;
    static const std::string CHARSET;
};

#endif