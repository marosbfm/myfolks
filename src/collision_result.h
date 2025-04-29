#ifndef COLLISION_RESULT_H
#define COLLISION_RESULT_H

#include "vec2.h"
#include "game_object.h"

class GameObject;
struct CollisionResult
{
    bool hit = false;
    Vec2 normal = Vec2(0, 0);
    Vec2 point = Vec2(0, 0);
    float distance = 0;
    GameObject* object = nullptr;
};

#endif