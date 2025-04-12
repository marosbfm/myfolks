#include "base_scene.h"

BaseScene::BaseScene(SDL_Renderer* renderer, Camera *camera) : Scene(renderer, camera) {
    player = Player(this, Vec2(100, 100), 100);
}

void BaseScene::update(double delta) {
    player.update(delta);
}

void BaseScene::render(double alpha) {
    player.render(alpha);
}

void BaseScene::handleInput(const Uint8* keystate) {
    player.handleInput(keystate);
}
