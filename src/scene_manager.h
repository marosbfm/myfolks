#include "scene.h"
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

class SceneManager
{
   public:
    static SceneManager* getInstance();
    Scene* getCurrentScene();
    void setCurrentScene(Scene* scene);

    void update(double delta);
    void render(double alpha);
    void handleInput(const Uint8* keystate);

    void clean();

   private:
    SceneManager() = default;
    Scene* currentScene = nullptr;
};

#endif