#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "collider.h"
#include "vec2.h"
#include <optional>

class BoxCollider : public Collider
{
   public:
    BoxCollider() {}
    BoxCollider(Vec2 position, float width, float height)
        : position(position), width(width), height(height)
    {
    }
    ~BoxCollider() override;
    bool checkCollision(Collider* other) override;
    std::optional<Vec2> getContactPoint(Vec2 movement, Collider* other) override;

    Vec2 position;
    float width;
    float height;
};

#endif