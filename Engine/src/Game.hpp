#pragma once
#include "Input.hpp"
#include "Scene.hpp"
#include <Option.hpp>
#include <Result.hpp>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <map>
#include <stdexcept>
#include <string>
#include "Timer.hpp"

namespace Engine {
class font_not_found : public std::exception {};
class not_found : public std::exception {}; 
class render_error :public std::exception {};
class no_surface : public render_error {};
class surface_to_texture : public render_error {};

class Game {

  private:
    SDL_Window                    *window;
    SDL_Surface                   *surf;
    std::map<std::string, Scene *> scenes;
    Option<Scene *>                active_scene = Option<Scene *>::None();
    bool                           should_quit;

    Timer fixed_update_timer;
    Timer delta_time_timer;

    std::map<std::string, TTF_Font *> fonts;
    Option<TTF_Font *>                current_font = Option<TTF_Font *>::None();

  public:
    InputHandler  input;
    SDL_Renderer *renderer;

    Game(std::string title, int width, int height);
    Game(std::string title);
    Game(std::string title, int width);
    void run();

    Result<void *, not_found> switchScene(std::string title);
    void                              addScene(std::string title, Scene *scene);
    void                              quit();

    Result<void *, font_not_found> addFont(std::string title, std::string path,
                                           int pt_size);
    Result<void *, not_found> setFont(std::string title);
    void                              destroyFont(std::string title);
    Result<void *, render_error *> drawText(int x, int y, std::string, SDL_Color text_col = {
                                                             255, 255, 255});
    //    Result<void*, render_error *> drawText(std::string, std::string
    //    title);
};

extern Game *game;
} // Namespace Engine
