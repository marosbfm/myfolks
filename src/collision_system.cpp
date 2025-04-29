#include "collision_system.h"

std::vector<CollisionResult> CollisionSystem::sweep(GameObject* object, Vec2 movement)
{
    std::vector<CollisionResult> results;
    GameObjectSet others = scene->getSceneGrid()->getCloseObjectsForGameObject(object, movement);
    for (auto other : others)
    {
        auto result = object->getCollider()->checkCollision(other, movement);
        if (result->hit)
        {
            results.push_back(*result);
        }
    }
    return results;
}