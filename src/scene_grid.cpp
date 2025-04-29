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
void SceneGrid::forEachCellOccupiedByObject(Vec2 position, float objWidth, float objHeight,
                                            std::function<void(int, int)> callback)
{
    float objX = position.x;
    float objY = position.y;

    for (float y = objY; y < objY + objHeight; y += cellSize)
    {
        int row = static_cast<int>(y / cellSize);
        for (float x = objX; x < objX + objWidth; x += cellSize)
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
        if (row >= 0 && row < rows && col >= 0 &&
            col < cols)
        {
            grid[row][col].insert(object);
        }
    };

    forEachCellOccupiedByObject(
        object->getPosition(), 
        object->getWidth(), 
        object->getHeight(), 
        addToCell
    );
}
void SceneGrid::removeGameObject(GameObject* object)
{
    auto removeFromCell = [this, object](int row, int col)
    {
        if (row >= 0 && row < rows && col >= 0 &&
            col < cols)
        {
            grid[row][col].erase(object);
        }
    };

    forEachCellOccupiedByObject(
        object->getPosition(), 
        object->getWidth(), 
        object->getHeight(), 
        removeFromCell
    );
}
GameObjectSet SceneGrid::getCloseObjectsForGameObject(GameObject* gameObject, Vec2 movement){
    GameObjectSet closeObjects;

    auto getCloseObjects = [this, gameObject, &closeObjects](int row, int col){
        
        if (row >= 0 && row < rows && col >= 0 &&
            col < cols)
        {
            for (int i = -1; i <= 1; i++){
                int newRow = row + i;
                for (int j = -1; j <= 1; j++){
                    int newCol = col + j;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)  
                    {
                        closeObjects.insert(grid[newRow][newCol].begin(), grid[newRow][newCol].end());
                    }
                }
            }
        }
    };

    auto newPosition = gameObject->getPosition() + movement;

    forEachCellOccupiedByObject(
        newPosition, 
        gameObject->getWidth(), 
        gameObject->getHeight(), 
        getCloseObjects
    );

    return closeObjects;
}