#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "collision_result.h"

class CollisionSystem
{
   private:
    Scene* scene;

   public:
    CollisionResult sweep(Collider* collider, Vec2 movement);
    void setScene(Scene* scene) : scene(scene) {}
}

#endif