
#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "base_ground.h"
#include "player.h"
#include "scene.h"

class BaseScene : public Scene
{
   public:
    BaseScene(SDL_Renderer* renderer, Camera* camera, float width, float height);
    ~BaseScene() override;
    void update(double delta) override;
    void render(double alpha) override;
    void handleInput(const Uint8* keystate) override;

   private:
    Player* player;
    BaseGround* baseGround;
};

#endif