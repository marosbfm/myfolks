#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <SDL_render.h>
#include <string>
#include <unordered_map>
#include "assets_key.h"

class AssetsManager
{
   private:
    const std::string ASSETS_PATH = "assets/";
    const std::string BASE_GROUND_PATH = ASSETS_PATH + "base-ground.png";
    const std::string FONT_PATH =
        ASSETS_PATH +
        "/fonts/hello_my_old_friend/spr_font_hellomyoldfriend_12x12_by_lotovik_sheet.png";
    std::unordered_map<AssetsKey, SDL_Texture*> textures;

   public:
    static AssetsManager* getInstance();
    bool loadAssets(SDL_Renderer* renderer);
    SDL_Texture* getTexture(AssetsKey key);
    void cleanAssets();
};

#endif