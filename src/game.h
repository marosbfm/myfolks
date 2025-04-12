#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "bitmap_font.h"
#include "player.h"
#include "timer.h"

class Game
{
   public:
    Game();
    ~Game();

    void run();

   private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    BitmapFont font;
    Timer timer;
    bool isRunning;
    void processInput();
    void update();
    void render();
    void clean();
};

#endif