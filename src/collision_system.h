#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "collision_result.h"

class CollisionSystem
{
   private:
    Scene* scene;

   public:
    std::vector<CollisionResult> sweep(GameObject* object, Vec2 movement);
    void setScene(Scene* scene) { this->scene = scene; };
};

#endif