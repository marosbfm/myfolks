#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include "vec2.h"

class Camera
{
   private:
    Vec2 position;
    Vec2 size;
    float zoom;

   public:
    Camera(Vec2 position, Vec2 size, float zoom) : position(position), size(size), zoom(zoom) {}
    SDL_Rect worldToScreenRect(SDL_Rect worldRect);
    SDL_Rect worldToScreenRect(Vec2 worldPos, float worldWidth, float worldHeight);
    Vec2 worldToScreen(Vec2 worldPos);
    float sizeToScreen(float worldSize);
    Vec2 screenToWorld(Vec2 screenPos);
    void setZoom(float zoom) { this->zoom = zoom; }
    void setPosition(Vec2 position) { this->position = position; }
    void setSize(Vec2 size) { this->size = size; }
};

#endif