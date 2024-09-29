#include "Game.hpp"
#include <Option.hpp>
#include <Result.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <cmath>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

namespace Engine {

Game *game;

Game::Game(std::string title) : Game::Game(title, 800, 800){};

Game::Game(std::string title, int width) : Game::Game(title, width, width) {}

Game::Game(std::string title, int width, int height) {
    game = this;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // TODO:
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
    if (window == NULL) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(-2);
    }

    SDL_CreateRenderer(window, 0, 0);
    renderer = SDL_GetRenderer(window);

    if (renderer == NULL) {
        std::cout << "D: render failure";
        exit(-6);
    }

    if (TTF_Init() < 0) {
        std::cout << "SDL_TTF failed to init. exiting...";
        SDL_Quit();
        exit(-3);
    }

    surf = SDL_GetWindowSurface(window);
}

void Game::run() {

    SDL_Event e;
    bool      quit = false;

    // delta time
    long long dt;

    while (quit == false) {

        delta_time_timer.reset();

        SDL_RenderClear(renderer);

        SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 255, 255, 255));
        SDL_Rect rect = SDL_Rect{300, 300, 200, 200};
        SDL_FillRect(surf, &rect, SDL_MapRGB(surf->format, 255, 0, 124));
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_KEYUP || e.type == SDL_KEYDOWN) {
                input.updateKey(e.key);
            }
            if (game->input.isKeyDown(SDLK_ESCAPE)) {
                quit = true;
            }
        }

        active_scene.expect("No Scene Set")->update(1. / dt);
        active_scene.expect("No Scene Set")->render();

        //        SDL_UpdateWindowSurface(window);
        SDL_RenderPresent(renderer);

        dt = delta_time_timer.elapsed_ns();
    }
}

void Game::addScene(std::string title, Scene *scene) {
    scenes.emplace(title, scene);

    if (active_scene.is_none()) {
        switchScene(title).unwrap();
    }
}

Result<void *, not_found> Game::switchScene(std::string title) {
    Scene *new_scene;

    try {
        new_scene = scenes.at(title);
    } catch (std::out_of_range e) {
        return Result<void *, not_found>::Err(not_found());
    }

    if (active_scene.is_some()) {
        auto scene = active_scene.unwrap();
        scene->unload();
        scene->post_unload();
    }

    new_scene->pre_init();
    new_scene->load();
    active_scene = Option<Scene *>::Some(new_scene);

    return Result<void *, not_found>::Ok(nullptr);
}

Result<void *, font_not_found> Game::addFont(std::string title,
                                             std::string path, int pt_size) {

    TTF_Font *font = TTF_OpenFont(path.c_str(), pt_size);

    if (!font) {
        return Result<void *, font_not_found>::Err(font_not_found());
    }

    fonts.emplace(title, font);

    if (current_font.is_none()) {
        current_font = Option<TTF_Font *>::Some(fonts.at(title));
    }

    return Result<void *, font_not_found>::Ok(nullptr);
};

Result<void *, not_found> Game::setFont(std::string title) {
    try {
        current_font = Option<TTF_Font *>::Some(fonts.at(title));
        return Result<void *, not_found>::Ok(nullptr);
    } catch (std::out_of_range e) {
        return Result<void *, not_found>::Err(not_found());
    }
}

void Game::destroyFont(std::string title) {

    try {
        auto font = fonts.find(title);
        TTF_CloseFont(font->second);
        fonts.erase(font);

    } catch (std::exception e) {
        // warn user, but nothing more. this is a very recoverable state.
        std::cout << "WARN: Tried to delete font `" << title
                  << "` which is not a loaded font. ";
        return;
    }
}

Result<void *, render_error *> Game::drawText(int x, int y, std::string text,
                                              SDL_Color text_col) {
    auto         font = current_font.unwrap();
    SDL_Surface *text_surface =
        TTF_RenderText_Solid(font, text.c_str(), text_col);

    if (!text_surface) {
        return Result<void *, render_error *>::Err(new no_surface());
    }

    SDL_Texture *text_texture =
        SDL_CreateTextureFromSurface(renderer, text_surface);

    if (!text_texture) {
        return Result<void *, render_error *>::Err(new surface_to_texture());
    }

    SDL_Rect text_rec = {x, y, text_surface->w, text_surface->h};
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rec);
    SDL_FreeSurface(text_surface); 
    SDL_DestroyTexture(text_texture); 
    return Result<void *, render_error *>::Ok(nullptr);

};

} // namespace Engine
