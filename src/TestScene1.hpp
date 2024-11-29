
#include "Gameobject.hpp"
#include "Scene.hpp"
#include <unistd.h>


class TestSceneOne : public Engine::Scene {
    private:
        int fps; 
        Engine::GO::GameObject sprite_test; 
        Engine::GO::GameObject textObject; 

  public:
    void update(double dt);
    void fixed_update(); 

    void load();
    void unload() ;
};
