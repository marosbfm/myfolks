#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "main_font.h"
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
    MainFont* font;
    Timer timer;
    bool isRunning;
    void processInput();
    void update();
    void render();
    void clean();
};

#endif