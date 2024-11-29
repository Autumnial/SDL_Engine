#include "TestScene1.hpp"
#include "Game.hpp"
#include "Gameobject.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Transform.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <SDL2/SDL_keycode.h>
#include <string>
#include <thread>

void TestSceneOne::update(double dt) {

    if (_game->input.is_key_down(SDLK_SPACE)) {
        _game->switch_scene("TestScene2").unwrap();
    };

    fps = 1'000'000'000 / (1. / dt);
}

void TestSceneOne::load() {

    _game->add_font("free_sans",
                   "/usr/share/fonts/truetype/freefont/FreeSans.ttf");

    std::cout << "Test Scene 1\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    sprite_test.add_component<Engine::GO::Components::Sprite>(
        Engine::GO::Components::Sprite("Resources/Sprites/apple.png"));

    textObject.add_component<Engine::GO::Components::Text>(
        Engine::GO::Components::Text("Text Object Working :o", 60,
                                     SDL_Color{255, 0, 0, 255}));

    textObject.get_component<Engine::GO::Components::Transform>()
        .unwrap()
        ->position = Engine::Math::Vector2<float>(50, 50);

    auto t =
        sprite_test.get_component<Engine::GO::Components::Transform>().unwrap();

    t->scale.x = 200;
    t->scale.y = 200;
    t->position.x = 100;
    t->position.y = 500;

    //add_game_object(&sprite_test);
   //add_game_object(&textObject);
};

void TestSceneOne::unload() { _game->destroy_font("free_sans"); }

void TestSceneOne::fixed_update() {};
