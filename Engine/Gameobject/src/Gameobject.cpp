#include "Gameobject.hpp"
#include "Transform.hpp"

namespace Engine::GO {
GameObject::GameObject() {
    id = next_id++;
    add_component<Components::Transform>(Components::Transform());
}

GameObject::~GameObject(){
    for (auto component: components){
        if (component.is_none()){
            continue;
        } 
        auto c = component.unwrap();
        c->destroy(); 
        delete c; 
    }
}

void GameObject::update() {
    for (auto component : components) {
        if (component.is_none()) {
            continue;
        }

        // Cannot be empty, so unwrap is fine.
        component.unwrap()->update();
    }
}

void GameObject::render() {
    for (auto component : components) {
        if (component.is_none()) {
            continue;
        }

        // Might be empty!!
        component.unwrap()->render();
    }
}

} // namespace Engine::GO
