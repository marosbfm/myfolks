#include "scene_grid.h"
#include "game_object.h"

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
void SceneGrid::forEachCellOccupiedByObject(GameObject* object,
                                            std::function<void(int, int)> callback)
{
    float objX = object->getPosition().x;
    float objY = object->getPosition().y;

    for (float y = objY; y < objY + height; y += cellSize)
    {
        int row = static_cast<int>(y / cellSize);
        for (float x = objX; x < objX + width; x += cellSize)
        {
            int col = static_cast<int>(x / cellSize);
            callback(row, col);
        }
    }
}

void SceneGrid::addGameObject(GameObject* object)
{
    auto addToCell = [this, object](int row, int col)
    {
        if (row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 &&
            col < static_cast<int>(grid[0].size()))
        {
            grid[row][col].insert(object);
        }
    };

    forEachCellOccupiedByObject(object, addToCell);
}
void SceneGrid::removeGameObject(GameObject* object)
{
    auto removeFromCell = [this, object](int row, int col)
    {
        if (row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 &&
            col < static_cast<int>(grid[0].size()))
        {
            grid[row][col].erase(object);
        }
    };

    forEachCellOccupiedByObject(object, removeFromCell);
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