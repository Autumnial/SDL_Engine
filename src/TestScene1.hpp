
#include "Game.hpp"
#include "Scene.hpp"
#include <unistd.h>
#include "SDL2/SDL_ttf.h"

extern Engine::Game *Engine::game;

class TestSceneOne : public Engine::Scene {
    private:
        TTF_Font *font; 
        int fps; 

  public:
    void update(double dt);
    void fixed_update(); 

    void render() ;

    void load();
    void unload() ;
};
