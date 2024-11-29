#pragma once
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
namespace Engine {

class InputHandler {

    friend class Game;

    bool keys[SDL_NUM_SCANCODES] = {false};

    void update_key(SDL_KeyboardEvent key);

  public:
    bool is_key_down(SDL_KeyCode k);
    bool is_key_down(SDL_Scancode k);
};
} // namespace Engine
