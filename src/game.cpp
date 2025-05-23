#include "game.h"
#include <iostream>
#include "assets_manager.h"
#include "base_scene.h"
#include "cmath"
#include "logger.h"
#include "main_font.h"
#include "scene_manager.h"
#include "string_utils.h"
#include "timer.h"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false)
{
    float width = 800;
    float height = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Logger::log(LogLevel::FATAL, strutil::to_string("SDL init failed: ", SDL_GetError()));
        return;
    }

    window = SDL_CreateWindow("MyFolks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,
                              height, SDL_WINDOW_SHOWN);

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

    AssetsManager::getInstance()->loadAssets(renderer);

    font = new MainFont();

    if (!font->init())
    {
        Logger::log(LogLevel::FATAL, "Failed to init font");
        return;
    }

    isRunning = true;
    timer.init(60.0);
    Camera* camera = new Camera(Vec2(0, 0), Vec2(width, height), 1);
    SceneManager::getInstance()->setCurrentScene(new BaseScene(renderer, camera, width, height));
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
    SceneManager::getInstance()->handleInput(keystate);
}

void Game::update()
{
    SceneManager::getInstance()->update(timer.getDelta());
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    font->drawText(renderer,
                   strutil::to_string("FPS: ", static_cast<int>(std::floor(timer.getFPS()))), 10,
                   10, 4);

    SceneManager::getInstance()->render(timer.getAlpha());
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    delete font;
    SceneManager::getInstance()->clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
