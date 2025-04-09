#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

class Player : public GameObject
{
   private:
    float speed;
    Vec2 lastPosition;
    Vec2 direction;
    Vec2 velocity;
    float size = 10;

   public:
    Player() : GameObject(Vec2(0, 0)){};
    Player(Vec2 position, float speed) : GameObject(position), speed(speed){};
    void handleInput(const Uint8* keystate);
    void update(double delta) override;
    void render(SDL_Renderer* renderer, double alpha) override;
};

#endif