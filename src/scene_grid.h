#ifndef SCENE_GRID_H
#define SCENE_GRID_H

#include <unordered_set>
#include <vector>
#include "game_object.h"
#include "vec2.h"

using GameObjectSet = std::unordered_set<GameObject*>;

class SceneGrid
{
   public:
    SceneGrid(float width, float height, float cellSize);
    ~SceneGrid() {}
    void addGameObject(GameObject* object);
    void updatePositionForGameObject(Vec2 oldPosition, GameObject* object);
    void removeGameObject(GameObject* object);
    GameObjectSet getCloseObjectsForGameObject(GameObject* gameObject);

   private:
    float width;
    float height;
    float cellSize;
    int cols;
    int rows;
    std::vector<std::vector<GameObjectSet>> grid;
};
#endif