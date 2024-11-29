#include "Sprite.hpp"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Game.hpp"
#include "Transform.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

namespace Engine::GO::Components {

void Sprite::update() {

    tex = SDL_CreateTextureFromSurface(owner->scene->game()->renderer, surf);

    SDL_SetTextureColorMod(tex, color.r, color.g, color.b);
}

void Sprite::render() {

    auto transform = owner->get_component<Transform>().unwrap();
    rect = SDL_Rect{(int)transform->position.x, (int)transform->position.y,
                    (int)transform->scale.x, (int)transform->scale.y};
    SDL_RenderCopy(owner->scene->game()->renderer, tex, NULL, &rect);
}

Sprite::Sprite(std::string src) { this->src = src; }

void Sprite::init() {

    surf = IMG_Load(src.c_str());

    if (surf == NULL) {
        std::cout << IMG_GetError() << std::endl;
        std::exit(-1);
    }
}
void Sprite::set_color_mod(SDL_Color col) { color = col; }

void Sprite::destroy() {

    std::cout << "destroying sprite";
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
};

} // namespace Engine::GO::Components
