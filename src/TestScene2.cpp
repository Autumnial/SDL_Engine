#include "TestScene2.hpp"
#include "Game.hpp"
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_video.h>
#include <thread>
#include <chrono>

void TestSceneTwo::update(double dt) {
    if (_game->input.is_key_down(SDLK_SPACE)) {
        _game->switch_scene("TestScene1").unwrap();
    };
}

void TestSceneTwo::load() {
    std::cout << "Test Scene 2\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void TestSceneTwo::unload() {}

void TestSceneTwo::_render() {
}

void TestSceneTwo::fixed_update() {};
