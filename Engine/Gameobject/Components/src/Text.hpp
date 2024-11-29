#pragma once

#include "Component.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
namespace Engine::GO::Components {
class Text : public ComponentI {

  private:
    SDL_Surface       *surf;
    SDL_Texture       *tex;
    SDL_Rect           rect;
    Option<TTF_Font *> font = Option<TTF_Font *>::None();
    int                size = 16;
    SDL_Color          col = SDL_Color{0, 0, 0, 255};
    bool               changed = false;

  public:
    std::string text;
    Text(std::string text);
    Text(std::string text, TTF_Font *font);
    Text(std::string text, TTF_Font *font, int size);
    Text(std::string text, TTF_Font *font, SDL_Color col);
    Text(std::string text, TTF_Font *font, int size, SDL_Color col);
    Text(std::string text, int size);
    Text(std::string text, SDL_Color col);
    Text(std::string text, int size, SDL_Color col);

    virtual void update();

    virtual void render();
};

} // namespace Engine::GO::Components
