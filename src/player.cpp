#include "player.h"
#include <SDL.h>

void Player::update(double delta)
{
    lastPosition = position;
    position += velocity * speed * delta;
}

void Player::render(SDL_Renderer* renderer, double alpha)
{
    Vec2 pos = lastPosition + (position - lastPosition) * alpha;

    SDL_Rect rect = {static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(size),
                     static_cast<int>(size)};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void Player::handleInput(const Uint8* keystate)
{
    velocity = Vec2(0, 0);
    if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP])
        velocity.y = -1;
    if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
        velocity.y = 1;
    if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])
        velocity.x = -1;
    if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])
        velocity.x = 1;
}