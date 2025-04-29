#ifndef SCENE_GRID_H
#define SCENE_GRID_H

#include <functional>
#include <unordered_set>
#include <vector>
#include "vec2.h"

class GameObject;  // forward declaration

using GameObjectSet = std::unordered_set<GameObject*>;

class SceneGrid
{
   public:
    SceneGrid(float width, float height, float cellSize);
    ~SceneGrid() {}
    void addGameObject(GameObject* object);
    void removeGameObject(GameObject* object);
    GameObjectSet getCloseObjectsForGameObject(GameObject* gameObject);
    GameObjectSet getCloseObjectsForGameObject(GameObject* gameObject, Vec2 movement);

   private:
    float width;
    float height;
    float cellSize;
    int cols;
    int rows;
    std::vector<std::vector<GameObjectSet>> grid;
    void forEachCellOccupiedByObject(Vec2 position, float objWidth, float objHeight, std::function<void(int, int)> callback);
};
#endif