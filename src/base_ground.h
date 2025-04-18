#ifndef BASE_GROUND_H
#define BASE_GROUND_H

#include <vector>
#include "collider.h"
#include "game_object.h"

class BaseGround : public GameObject
{
   public:
    BaseGround(Scene* scene, Vec2 position, float width, float height)
        : GameObject(scene, position, width, height){};
    ~BaseGround() ;
    bool init() override;
    void update(double delta) override;
    void render(double alpha) override;

    Collider* getCollider() override { return collider; }

   private:
    SDL_Texture* texture;
    const int TAIL_SIZE = 32;
    const int GROUND_TAIL_COUNT = 4;
    int rows = height / TAIL_SIZE;
    int cols = width / TAIL_SIZE;
    Collider* collider;

    std::vector<std::vector<int>> groundTilesMap;
};

#endif