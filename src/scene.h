#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include "camera.h"

class Scene
{
   public:
    SDL_Renderer* renderer;
    Camera* camera;

    Scene(SDL_Renderer* renderer, Camera* camera) : renderer(renderer), camera(camera){};
    virtual void update(double delta) = 0;
    virtual void render(double alpha) = 0;
    virtual void handleInput(const Uint8* keystate) = 0;

    virtual ~Scene() = default;
};

#endif