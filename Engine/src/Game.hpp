#pragma once
#include "Input.hpp"
#include "Scene.hpp"
#include <Option.hpp>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <map>
#include <string>
#include "Timer.hpp"

namespace Engine {
class Game {

  private:
    SDL_Window                    *window;
    SDL_Surface                   *surf;
    std::map<std::string, Scene *> scenes;
    Option<Scene *>                active_scene = Option<Scene *>::None();
    bool                           should_quit;

    Timer fixed_update_timer;
    Timer delta_time_timer;

  public:
    InputHandler input;
    SDL_Renderer * renderer;

    Game(std::string title, int width, int height);
    Game(std::string title);
    Game(std::string title, int width);
    void run();

    void switchScene(std::string title);
    void addScene(std::string title, Scene *scene);
    void quit();
};

extern Game *game;
} // Namespace Engine
