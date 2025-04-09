#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL_render.h>
#include "vec2.h"

class GameObject
{
   protected:
    Vec2 position;

   public:
    GameObject(Vec2 position) : position(position){};
    virtual ~GameObject() = default;
    virtual void update(double delta) = 0;
    virtual void render(SDL_Renderer* renderer, double alpha) = 0;
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