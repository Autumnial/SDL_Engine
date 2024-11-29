#include "Scene.hpp"
#include "Gameobject.hpp"



void Engine::Scene::pre_init(){}; 
void Engine::Scene::post_unload(){}; 

void Engine::Scene::go_update(){
    for(auto go : gameObjects){
        go->update(); 
    }
}

void Engine::Scene::_render(){
    for(auto go : gameObjects){
        go->render(); 
    }
}

void Engine::Scene::add_game_object(Engine::GO::GameObject* go){
    go->scene = this; 
    
    gameObjects.push_back(go);
};
