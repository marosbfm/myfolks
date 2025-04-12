
#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "scene.h"
#include "player.h"

class BaseScene : public Scene
{
public:
    BaseScene( SDL_Renderer* renderer, Camera *camera);
    ~BaseScene() override = default;
    void update(double delta) override;
    void render(double alpha) override;
    void handleInput(const Uint8* keystate) override;

private:
    Player player;
};

#endif