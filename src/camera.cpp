#include "camera.h"

SDL_Rect Camera::worldToScreenRect(Vec2 worldPos, float worldWidth, float worldHeight)
{   auto pos = worldToScreen(worldPos);
    auto width = sizeToScreen(worldWidth);
    auto height = sizeToScreen(worldHeight);
    return SDL_Rect{static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height)};
}

Vec2 Camera::worldToScreen(Vec2 worldPos)
{   
    auto pos = position - worldPos;
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
