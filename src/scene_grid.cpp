#include "scene_grid.h"

SceneGrid::SceneGrid(float width, float height, float cellSize)
    : width(width), height(height), cellSize(cellSize)
{
    rows = height / cellSize;
    cols = width / cellSize;
    grid.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        grid[i].resize(cols);
    }
}

void SceneGrid::addGameObject(GameObject* object)
{
    int row = static_cast<int>(object->getPosition().y / cellSize);
    int col = static_cast<int>(object->getPosition().x / cellSize);
    grid[row][col].insert(object);
}
void SceneGrid::removeGameObject(GameObject* object)
{
    int row = static_cast<int>(object->getPosition().y / cellSize);
    int col = static_cast<int>(object->getPosition().x / cellSize);
    grid[row][col].erase(object);
}

void SceneGrid::updatePositionForGameObject(Vec2 oldPosition, GameObject* object)
{
    int oldRow = static_cast<int>(oldPosition.y / cellSize);
    int oldCol = static_cast<int>(oldPosition.x / cellSize);
    int newRow = static_cast<int>(object->getPosition().y / cellSize);
    int newCol = static_cast<int>(object->getPosition().x / cellSize);
    grid[oldRow][oldCol].erase(object);
    grid[newRow][newCol].insert(object);
}

GameObjectSet SceneGrid::getCloseObjectsForGameObject(GameObject* gameObject)
{
    int row = static_cast<int>(gameObject->getPosition().y / cellSize);
    int col = static_cast<int>(gameObject->getPosition().x / cellSize);
    GameObjectSet closeObjects;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                closeObjects.insert(grid[newRow][newCol].begin(), grid[newRow][newCol].end());
            }
        }
    }
    return closeObjects;
}