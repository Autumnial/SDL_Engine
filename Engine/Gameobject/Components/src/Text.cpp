#include "Text.hpp"
#include "Transform.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

namespace Engine::GO::Components {

Text::Text(std::string text) {
    this->text = text;
    changed = true;
};

Text::Text(std::string text, TTF_Font *font) {
    if (!font) {
        this->font = Option<TTF_Font *>::None();
    }

    this->font = Option<TTF_Font *>::Some(font);
}

Text::Text(std::string text, int size) : Text(text) { this->size = size; }

Text::Text(std::string text, SDL_Color col) : Text(text) { this->col = col; }

Text::Text(std::string text, int size, SDL_Color col) : Text(text, size) {
    this->col = col;
}

Text::Text(std::string text, TTF_Font *font, int size) : Text(text, font) {
    this->size = size;
}
Text::Text(std::string text, TTF_Font *font, SDL_Color col) : Text(text, font) {
    this->col = col;
}
Text::Text(std::string text, TTF_Font *font, int size, SDL_Color col)
    : Text(text, font, size) {
    this->col = col;
}

void Text::update() {

    if (changed) {
        auto f = font.unwrap_or(owner->scene->game()->current_font.unwrap());
        TTF_SetFontSize(f, size);

        surf = TTF_RenderText_Solid(f, text.c_str(), col);

        if (!surf) {
            std::cout << TTF_GetError() << std::endl;
        }

        tex =
            SDL_CreateTextureFromSurface(owner->scene->game()->renderer, surf);

        if (!tex) {
            std::cout << SDL_GetError() << std::endl;
        }
    }
}

void Text::render() {
    auto t = owner->get_component<Transform>().unwrap();
    rect = SDL_Rect{.x = (int)t->position.x,
                    .y = (int)t->position.y,
                    .w = surf->w,
                    .h = surf->h};

    SDL_RenderCopy(owner->scene->game()->renderer, tex, nullptr, &rect);
}

} // namespace Engine::GO::Components
