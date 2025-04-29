#ifndef PLAYER_H
#define PLAYER_H

#include "box_collider.h"
#include "game_object.h"
#include "scene.h"

class Player : public GameObject
{
   private:
    float speed = 500;
    Vec2 lastPosition;
    Vec2 direction;
    Vec2 velocity;
    float size = 34;
    BoxCollider* collider = nullptr;

   public:
    Player(Scene* scene, Vec2 position, float width, float height);
    void handleInput(const Uint8* keystate);
    void update(double delta) override;
    void render(double alpha) override;
    bool init() override
    {
        return true;
    }
    Collider* getCollider() override
    {
        return collider;
    }
    Vec2 getPosition()
    {
        return position;
    }

    Vec2 getLastPosition()
    {
        return lastPosition;
    }
};

#endif