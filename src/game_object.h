#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL_render.h>
#include "vec2.h"
#include "scene.h"

class GameObject
{
   protected:
    Scene* scene;
    Vec2 position;


   public:
    GameObject(Scene *scene, Vec2 position) : scene(scene), position(position){};
    virtual ~GameObject() = default;
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