#include "Input.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>

namespace Engine {

bool InputHandler::is_key_down(SDL_KeyCode k) {
  int scancode = SDL_GetScancodeFromKey(k);
  return keys[scancode];
};
bool InputHandler::is_key_down(SDL_Scancode k) { return keys[k]; };
void InputHandler::update_key(SDL_KeyboardEvent key) {
  if (key.type == SDL_KEYDOWN) {
    keys[key.keysym.scancode] = true;
  } else if (key.type == SDL_KEYUP) {
    keys[key.keysym.scancode] = false;
  }
}
} // namespace Engine
