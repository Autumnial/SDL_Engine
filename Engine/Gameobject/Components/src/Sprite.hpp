#pragma once

#include "Component.hpp"
#include "Gameobject.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <string>
namespace Engine::GO::Components {

class Sprite : public ComponentI {
    // figure out properties

  private:
    bool         changed = false;
    SDL_Color    color = SDL_Color{.r = 255, .g = 255, .b = 255, .a = 255};
    SDL_Texture *tex;
    SDL_Surface *surf;
    SDL_Rect     rect;
    std::string  src;

  public:
    Sprite(std::string source);
    // the important one
    void render() override;
    void update() override;
    void init() override;
    void destroy() override;

    void set_color_mod(SDL_Color col);
};
} // namespace Engine::GO::Components
