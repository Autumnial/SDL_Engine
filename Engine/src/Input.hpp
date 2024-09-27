#pragma once
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
namespace Engine {

class InputHandler {

    friend class Game;

    bool keys[SDL_NUM_SCANCODES] = {false};

    void updateKey(SDL_KeyboardEvent key);

  public:
    bool isKeyDown(SDL_KeyCode k);
    bool isKeyDown(SDL_Scancode k);
};
} // namespace Engine
