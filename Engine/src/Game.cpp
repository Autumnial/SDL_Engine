#include <SDL2/SDL_image.h>
namespace Engine {
class Game;
}
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
#include <SDL2/SDL_video.h>
#include <cmath>
#include <cstddef>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

namespace Engine {

Game::Game(std::string title) : Game::Game(title, 800, 800) {};

Game::Game(std::string title, int width) : Game::Game(title, width, width) {}

Game::Game(std::string title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // TODO:
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
    if (window == NULL) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(-2);
    }

    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cout << "SDL_IMG failed with error: " << IMG_GetError()
                  << ". exiting...";
        exit(-1);
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

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_KEYUP || e.type == SDL_KEYDOWN) {
                input.update_key(e.key);
            }
            if (input.is_key_down(SDLK_ESCAPE)) {
                quit = true;
            }
        }

        active_scene.expect("No Scene Set")->go_update();
        active_scene.expect("No Scene Set")->update(1. / dt);
        active_scene.expect("No Scene Set")->_render();

        //        SDL_UpdateWindowSurface(window);
        SDL_RenderPresent(renderer);

        dt = delta_time_timer.elapsed_ns();
    }
}

void Game::add_scene(std::string title, Scene *scene) {

    scene->_game = this;

    scenes.emplace(title, scene);

    if (active_scene.is_none()) {
        switch_scene(title).unwrap();
    }
}

Result<void *, not_found> Game::switch_scene(std::string title) {
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

Result<void *, font_not_found> Game::add_font(std::string title,
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

Result<void *, not_found> Game::set_font(std::string title) {
    try {
        current_font = Option<TTF_Font *>::Some(fonts.at(title));
        return Result<void *, not_found>::Ok(nullptr);
    } catch (std::out_of_range e) {
        return Result<void *, not_found>::Err(not_found());
    }
}

void Game::destroy_font(std::string title) {

    try {
        auto font = fonts.find(title);
        TTF_CloseFont(font->second);
        fonts.erase(font);
        current_font = Option<TTF_Font *>::None();

    } catch (std::exception e) {
        // Warn user, but nothing more. Failing to unload a font is not
        // a terminal error.
        std::cout << "WARN: Tried to delete font `" << title
                  << "` which is not a loaded font. ";
        return;
    }
}

Result<void *, not_found> Game::set_font_size(int pt_size) {
    TTF_SetFontSize(this->current_font.unwrap(), pt_size);
    return Result<void *, not_found>::Ok(NULL);
}

Result<void *, render_error *> Game::draw_text(int x, int y, std::string text,
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

    SDL_Rect text_rec = {x, y, (text_surface->w), (text_surface->h)};
    //    SDL_Rect text_rec = {x, y, 200, 200};

    SDL_RenderCopy(renderer, text_texture, NULL, &text_rec);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    return Result<void *, render_error *>::Ok(nullptr);
};

} // namespace Engine
