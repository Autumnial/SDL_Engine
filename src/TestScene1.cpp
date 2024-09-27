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
        Engine::game->switchScene("TestScene2");
    };

    fps = 1'000'000'000 / (1. / dt);
}

void TestSceneOne::render() {
    SDL_Color    text_colour = {255, 0, 0};
    SDL_Surface *textSurf = TTF_RenderText_Solid(
        font, (std::to_string(fps) + " FPS").c_str(), text_colour);

    if (!textSurf) {
        std::cout << "no text string D:";
        exit(-5);
    }

    SDL_Texture *text_tex =
        SDL_CreateTextureFromSurface(Engine::game->renderer, textSurf);

    if (!text_tex) {
        std::cout << "D: D:";
        exit(-7);
    }

    SDL_Rect text_rec = {50, 50, 200, 200};
    SDL_RenderCopy(Engine::game->renderer, text_tex, NULL, &text_rec);
}

void TestSceneOne::load() {

    font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeSans.ttf", 48);

    if (!font) {
        std::cout << "failed to load font";
        exit(-4);
    }

    std::cout << "Test Scene 1\n";
    sleep(1);
};
