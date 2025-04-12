#include "scene_manager.h"

SceneManager* SceneManager::getInstance()
{
    static SceneManager instance;
    return &instance;
}

Scene* SceneManager::getCurrentScene()
{
    return currentScene;
}

void SceneManager::setCurrentScene(Scene* scene)
{
    currentScene = scene;
}

void SceneManager::update(double delta)
{
    if (currentScene == nullptr)
        return;
    currentScene->update(delta);
}

void SceneManager::render(double alpha)
{
    if (currentScene == nullptr)
        return;
    currentScene->render(alpha);
}

void SceneManager::handleInput(const Uint8* keystate)
{
    if (currentScene == nullptr)
        return;
    currentScene->handleInput(keystate);
}

void SceneManager::clean() {
    delete currentScene;
}
