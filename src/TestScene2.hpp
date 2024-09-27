
#include "Game.hpp"
#include "Scene.hpp"
#include <SDL2/SDL_keycode.h>
#include <iostream>
#include <unistd.h>

class TestSceneTwo : public Engine::Scene {

  public:
    void update(double dt) {
        if (Engine::game->input.isKeyDown(SDLK_SPACE)) {
            Engine::game->switchScene("TestScene1");
        };
    }
    void fixed_update() {};

    void load() {
        std::cout << "Test Scene 2\n";
        sleep(1);
    };
    void unload() {}

    void render() {}
};
