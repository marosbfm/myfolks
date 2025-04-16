#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "scene.h"

class Player : public GameObject
{
   private:
    float speed = 100;
    Vec2 lastPosition;
    Vec2 direction;
    Vec2 velocity;
    float size = 10;

   public:
    Player(Scene* scene, Vec2 position) : GameObject(scene, position, size, size){};
    void handleInput(const Uint8* keystate);
    void update(double delta) override;
    void render(double alpha) override;
    bool init() override
    {
        return true;
    }
};

#endif