#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include "camera.h"
#include "scene_grid.h"

class Scene
{
   public:
    SDL_Renderer* renderer;
    Camera* camera;
    float width;
    float height;

    Scene(SDL_Renderer* renderer, Camera* camera, float width, float height)
        : renderer(renderer), camera(camera), width(width), height(height){};
    virtual void update(double delta) = 0;
    virtual void render(double alpha) = 0;
    virtual void handleInput(const Uint8* keystate) = 0;
    virtual SceneGrid* getSceneGrid() = 0;
    virtual ~Scene() = default;
};

#endif