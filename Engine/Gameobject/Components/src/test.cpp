#include "Collider.hpp"
#include "Gameobject.hpp"
int main() {
    Engine::GO::GameObject go;
    go.addComponent<Engine::GO::Components::Collider>(
        Engine::GO::Components::Collider());
}
