#ifndef COLLIDER_H
#define COLLIDER_H

#include <optional>
#include "collision_result.h"
#include "vec2.h"
#include "game_object.h"

class CollisionResult;
class Collider
{
   public:
    Collider() {}
    Collider(Vec2 position) : position(position) {}
    virtual ~Collider() = default;
    virtual CollisionResult* checkCollision(GameObject* other, Vec2 movement) = 0;
    Vec2 position;
    Vec2 movement;
};

#endif