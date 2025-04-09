#include "game.h"
#include <iostream>
#include "logger.h"
#include "string_utils.h"
#include "timer.h"
#include "cmath"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Logger::log(LogLevel::FATAL, strutil::to_string("SDL init failed: ", SDL_GetError()));
        return;
    }

    window = SDL_CreateWindow("MyFolks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                              SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        Logger::log(LogLevel::FATAL,
                    strutil::to_string("Window creation failed: ", SDL_GetError()));
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        Logger::log(LogLevel::FATAL,
                    strutil::to_string("Renderer creation failed: ", SDL_GetError()));
        return;
    }

    font = BitmapFont();
    if (!font.load(
            renderer,
            "assets/fonts/hello_my_old_friend/spr_font_hellomyoldfriend_12x12_by_lotovik_sheet.png",
            12, 12, 10))
    {
        Logger::log(LogLevel::FATAL, "Failed to load font");
        return;
    }
    font.setCharset(
        " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789$￠€£¥¤+-*/"
        "÷=%‰\"'#@&_(),.;:¿?¡!\\|{}<>[]§¶µ`^~©®™");

    isRunning = true;
    timer.init(60.0);

    player = Player(Vec2(100, 100), 100);

    Logger::log(LogLevel::INFO, "Game initialized");
}

Game::~Game()
{
    clean();
    Logger::log(LogLevel::INFO, "Game destroyed");
}

void Game::run()
{
    while (isRunning)
    {
        timer.frame();
        processInput();
        while (timer.shouldUpdate())
        {
            update();
        }
        render();
        SDL_Delay(1);
    }
}

void Game::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }

    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    player.handleInput(keystate);
}

void Game::update()
{
    player.update(timer.getDelta());
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    font.drawText(renderer, strutil::to_string("FPS: ", static_cast<int>(std::floor(timer.getFPS()))), 10, 10, 4);

    player.render(renderer, timer.getAlpha());
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
