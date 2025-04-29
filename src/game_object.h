#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL_render.h>
#include "collider.h"
#include "scene.h"
#include "vec2.h"

class Collider;

class GameObject
{
   protected:
    Scene* scene;
    Vec2 position;
    float width;
    float height;

   public:
    GameObject(Scene* scene, Vec2 position, float width, float height)
        : scene(scene), position(position), width(width), height(height) {};
    virtual ~GameObject() = default;
    virtual bool init() = 0;
    virtual void update(double delta) = 0;
    virtual void render(double alpha) = 0;
    virtual Collider* getCollider() = 0;
    Vec2 getPosition()
    {
        return position;
    }
    void setPosition(Vec2 position)
    {
        this->position = position;
    }
    float getWidth()
    {
        return width;
    }

    float getHeight()
    {
        return height;
    }
};

#endif