#include "Game.hpp"
#include <Option.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <ostream>
#include <ratio>
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
    window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
    if (window == NULL) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(-2);
    }

    SDL_CreateRenderer(window, 0, 0);
    renderer = SDL_GetRenderer(window); 
    
    if(renderer == NULL){
        std::cout << "D: render failure"; 
        exit(-6);
    }

    if(TTF_Init() < 0){
        std::cout<< "SDL_TTF failed to init. exiting...";
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
        switchScene(title);
    }
}

void Game::switchScene(std::string title) {

    // TODO: throw custom exception to make it clearer
    Scene *new_scene = scenes.at(title);

    if (active_scene.is_some()) {
        auto scene = active_scene.unwrap();
        scene->unload();
        scene->post_unload();
    }

    new_scene->pre_init();
    new_scene->load();
    active_scene = Option<Scene *>::Some(new_scene);
}
} // namespace Engine
