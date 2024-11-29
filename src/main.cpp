#include "Game.hpp"
#include <pthread.h>

#include "Vector.hpp"

#include "TestScene1.hpp"
#include "TestScene2.hpp"
const int WIDTH = 800;
const int HEIGHT = WIDTH;

int main(int argc, char *argv[]) {
    Engine::Game app = Engine::Game("Game");

    TestSceneOne *scene1 = new TestSceneOne();
    TestSceneTwo *scene2 = new TestSceneTwo();

    Engine::Math::Vector2 v(1,2); 

    app.add_scene("TestScene1", scene1);

    app.add_scene("TestScene2", scene2);


    app.run();

    return 0;
}
