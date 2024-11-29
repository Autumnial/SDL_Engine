#pragma once
namespace Engine {
    class Scene; 
}

#include "Gameobject.hpp"
#include "Game.hpp"
#include "vector" 
namespace Engine {

class Scene {

friend class Game;

  private:
    void pre_init();
    void post_unload();
    std::vector<GO::GameObject *> gameObjects; 
  protected: 
    Game* _game; 

  public:
    virtual void unload() = 0;
    virtual void load() = 0;

    virtual void go_update(); 
    virtual void update(double dt) = 0;
    // TODO: figure out how often this function should run :p
    virtual void fixed_update() = 0;

    virtual void _render();
    void add_game_object(GO::GameObject *go); 
    Game* game(){
        return this->_game; 
    }
     
};
} // namespace Engine
