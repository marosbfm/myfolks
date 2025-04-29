#include "player.h"
#include <SDL.h>
#include "logger.h"
#include "string_utils.h"

void Player::update(double delta)
{
    /*
    scene->getSceneGrid()->removeGameObject(this);
    auto objects = scene->getSceneGrid()->getCloseObjectsForGameObject(this);

    lastPosition = Vec2(position);
    Vec2 movement = velocity * speed * delta;
    velocity = Vec2(0, 0);
    position += movement;

    Logger::logOnecePerTime("player", LogLevel::DEBUG,
                            strutil::to_string("Player position: ", position));

    collider->position = position;

    for (auto object : objects)
    {
        if (object == this)
            continue;

        if (collider->checkCollision(object->getCollider()))
        {
            auto optionalPosition = collider->getContactPoint(movement, object->getCollider());
            if (optionalPosition.has_value())
            {
                collider->position = optionalPosition.value();
                position = collider->position;
                break;
            }
        }
    }

    scene->getSceneGrid()->addGameObject(this);
    */
}

void Player::render(double alpha)
{
    Vec2 pos = lastPosition + (position - lastPosition) * alpha;

    SDL_Rect rect = scene->camera->worldToScreenRect(pos, size, size);
    SDL_SetRenderDrawColor(scene->renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(scene->renderer, &rect);
}

Player::Player(Scene* scene, Vec2 position, float width, float height) : GameObject(scene, position, width, height)
{
    collider = new BoxCollider(position, width, height);
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