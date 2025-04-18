#include "base_ground.h"
#include <vector>
#include "assets_manager.h"
#include "box_collider.h"
#include "logger.h"

bool BaseGround::init()
{
    texture = AssetsManager::getInstance()->getTexture(AssetsKey::BASE_GROUND);
    if (texture == nullptr)
    {
        Logger::log(LogLevel::ERROR, "Failed to load ground texture");
        return false;
    }
    groundTilesMap = std::vector<std::vector<int>>(rows, std::vector<int>(cols));

    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            groundTilesMap[i][j] = rand() % GROUND_TAIL_COUNT;
        }
    }

    collider = new BoxCollider(position, width, height);

    return true;
}

void BaseGround::render(double alpha)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            SDL_Rect srcRect = {groundTilesMap[i][j] * TAIL_SIZE, 0, TAIL_SIZE, TAIL_SIZE};
            SDL_Rect dstRect = {static_cast<int>(position.x + j * TAIL_SIZE),
                                static_cast<int>(position.y + i * TAIL_SIZE), TAIL_SIZE, TAIL_SIZE};
            dstRect = scene->camera->worldToScreenRect(dstRect);
            SDL_RenderCopy(scene->renderer, texture, &srcRect, &dstRect);
        }
    }
}

void BaseGround::update(double delta) {}

BaseGround::~BaseGround()
{
    delete collider;
}
