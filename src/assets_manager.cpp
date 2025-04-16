#include "assets_manager.h"
#include <SDL_image.h>
#include "logger.h"
#include "string_utils.h"

AssetsManager* AssetsManager::getInstance()
{
    static AssetsManager instance;
    return &instance;
}

bool AssetsManager::loadAssets(SDL_Renderer* renderer)
{
    auto fontTexture = IMG_LoadTexture(renderer, FONT_PATH.c_str());
    if (fontTexture == nullptr)
    {
        Logger::log(LogLevel::ERROR,
                    strutil::to_string("Failed to load font texture: ", SDL_GetError()));
        return false;
    }
    textures[AssetsKey::FONT] = fontTexture;

    auto baseGroundTexture = IMG_LoadTexture(renderer, BASE_GROUND_PATH.c_str());
    if (baseGroundTexture == nullptr)
    {
        Logger::log(LogLevel::ERROR,
                    strutil::to_string("Failed to load base ground texture: ", SDL_GetError()));
        return false;
    }
    textures[AssetsKey::BASE_GROUND] = baseGroundTexture;

    return true;
}

SDL_Texture* AssetsManager::getTexture(AssetsKey key)
{
    SDL_Texture* texture = textures[key];
    return texture;
}

void AssetsManager::cleanAssets()
{
    for (auto& texture : textures)
    {
        SDL_DestroyTexture(texture.second);
    }
    textures.clear();
}
