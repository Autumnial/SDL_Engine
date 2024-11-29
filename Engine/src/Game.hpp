#pragma once
namespace Engine {
class Game;
}
#include "Gameobject.hpp"
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
#include "Exceptions.hpp"
#include <string>
#include "Timer.hpp"

namespace Engine {

class Game {

  private:
    SDL_Surface                   *surf;
    std::map<std::string, Scene *> scenes;
    Option<Scene *>                active_scene = Option<Scene *>::None();
    bool                           should_quit;

    Timer fixed_update_timer;
    Timer delta_time_timer;

    std::map<std::string, TTF_Font *> fonts;

  public:
    Option<TTF_Font *>                current_font = Option<TTF_Font *>::None();
    SDL_Window   *window;
    InputHandler  input;
    SDL_Renderer *renderer;

    Game(std::string title, int width, int height);
    Game(std::string title);
    Game(std::string title, int width);
    void run();

    Result<void *, not_found> switch_scene(std::string title);
    void                      add_scene(std::string title, Scene *scene);
    void                      quit();

    Result<void *, font_not_found> add_font(std::string title, std::string path,
                                           int pt_size = 16);
    Result<void *, not_found>      set_font(std::string title);
    Result<void *, not_found>      set_font_size(int pt_size);
    void                           destroy_font(std::string title);
    Result<void *, render_error *>
    draw_text(int x, int y, std::string, SDL_Color text_col = {255, 255, 255});
    //    Result<void*, render_error *> drawText(std::string, std::string
    //    title);
};

} // Namespace Engine
