#include "TestScene1.hpp"
#include "Game.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <SDL2/SDL_keycode.h>
#include <string>

extern Engine::Game *Engine::game;
void                 TestSceneOne::update(double dt) {

    if (Engine::game->input.isKeyDown(SDLK_SPACE)) {
        Engine::game->switchScene("TestScene2").unwrap();
    };

    fps = 1'000'000'000 / (1. / dt);
}

void TestSceneOne::render() {
    SDL_Color text_colour = {255, 0, 0};

    Engine::game->drawText(50, 50, "FPS: " + std::to_string(fps), text_colour);
}

void TestSceneOne::load() {

    Engine::game->addFont(
        "free_sans", "/usr/share/fonts/truetype/freefont/FreeSans.ttf", 80);

    std::cout << "Test Scene 1\n";
    sleep(1);
};

void TestSceneOne::unload() { TTF_CloseFont(font); };

void TestSceneOne::fixed_update() {};
