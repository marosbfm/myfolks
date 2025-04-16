#include "base_scene.h"

BaseScene::BaseScene(SDL_Renderer* renderer, Camera* camera, float width, float height)
    : Scene(renderer, camera, width, height)
{
    player = new Player(this, Vec2(100, 100));
    auto yPos = height - 64;
    baseGround = new BaseGround(this, Vec2(0, yPos), width, 64);
    baseGround->init();
}

void BaseScene::update(double delta)
{
    player->update(delta);
}

void BaseScene::render(double alpha)
{
    player->render(alpha);
    baseGround->render(alpha);
}

void BaseScene::handleInput(const Uint8* keystate)
{
    player->handleInput(keystate);
}

BaseScene::~BaseScene()
{
    delete player;
}
