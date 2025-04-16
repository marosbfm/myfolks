#ifndef WALL_H
#define WALL_H
#include "game_object.h"

class Wall : public GameObject
{
    private:
    SDL_Texture* texture;

   public:
    Wall(Scene* scene, Vec2 position, float width, float height)
        : GameObject(scene, position, width, height){};
    ~Wall() = default;
    void loadTexture(SDL_Renderer* renderer, const std::string& path);
    void update(double delta) override;
    void render(double alpha) override;
};

#endif