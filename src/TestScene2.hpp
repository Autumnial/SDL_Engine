
#include "Game.hpp"
#include "Scene.hpp"
#include <SDL2/SDL_keycode.h>
#include <iostream>
#include <unistd.h>

class TestSceneTwo : public Engine::Scene {

  public:
    void update(double dt);
    void fixed_update();

    void load();
    void unload();

    void _render();
};
