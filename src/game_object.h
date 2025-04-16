#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL_render.h>
#include "scene.h"
#include "vec2.h"

class GameObject
{
   protected:
    Scene* scene;
    Vec2 position;
    float width;
    float height;

   public:
    GameObject(Scene* scene, Vec2 position, float width, float height)
        : scene(scene), position(position), width(width), height(height){};
    virtual ~GameObject() = default;
    virtual bool init() = 0;
    virtual void update(double delta) = 0;
    virtual void render(double alpha) = 0;
    Vec2 getPosition()
    {
        return position;
    }
    void setPosition(Vec2 position)
    {
        this->position = position;
    }
};

#endif