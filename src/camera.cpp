#include "camera.h"

SDL_Rect Camera::worldToScreenRect(SDL_Rect worldRect)
{
    auto pos = worldToScreen(Vec2(worldRect.x, worldRect.y));
    auto width = sizeToScreen(worldRect.w);
    auto height = sizeToScreen(worldRect.h);
    worldRect.x = static_cast<int>(pos.x);
    worldRect.y = static_cast<int>(pos.y);
    worldRect.w = static_cast<int>(width);
    worldRect.h = static_cast<int>(height);
    return worldRect;
}

SDL_Rect Camera::worldToScreenRect(Vec2 worldPos, float worldWidth, float worldHeight)
{
    auto pos = worldToScreen(worldPos);
    auto width = sizeToScreen(worldWidth);
    auto height = sizeToScreen(worldHeight);
    return SDL_Rect{static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width),
                    static_cast<int>(height)};
}

Vec2 Camera::worldToScreen(Vec2 worldPos)
{
    auto pos = worldPos - position;
    pos = pos * zoom;
    return pos;
}

float Camera::sizeToScreen(float worldSize)
{
    return worldSize * zoom;
}

Vec2 Camera::screenToWorld(Vec2 screenPos)
{
    auto pos = screenPos / zoom;
    pos = pos + position;
    return pos;
}
