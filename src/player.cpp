#include "player.h"
#include <SDL.h>
#include "logger.h"
#include "string_utils.h"

void Player::update(double delta)
{
    lastPosition = position;
    position += velocity * speed * delta;
    velocity = Vec2(0, 0);
    Logger::logOnecePerTime("player", LogLevel::DEBUG,
                            strutil::to_string("Player position: ", position));
}

void Player::render(double alpha)
{
    Vec2 pos = lastPosition + (position - lastPosition) * alpha;

    SDL_Rect rect = scene->camera->worldToScreenRect(pos, size, size);
    SDL_SetRenderDrawColor(scene->renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(scene->renderer, &rect);
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