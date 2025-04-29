#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "game_object.h"
#include "collider.h"
#include "vec2.h"
#include <optional>

class BoxCollider : public Collider
{
   public:
    BoxCollider() {}
    BoxCollider(Vec2 position, float width, float height)
        : width(width), height(height)
    {
        this->position = position;
    }
    ~BoxCollider() override;

    CollisionResult* checkCollision(GameObject* other, Vec2 movement) override;

    float width;
    float height;
};

#endif