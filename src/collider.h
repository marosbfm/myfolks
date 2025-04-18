#ifndef COLLIDER_H
#define COLLIDER_H

#include "vec2.h"

class Collider
{
   public:
    Collider() {}
    virtual ~Collider() = default;
    virtual bool checkCollision(Collider* other) = 0;
    virtual Vec2 getContactPoint(Vec2 movement, Collider* other) = 0;
};

#endif