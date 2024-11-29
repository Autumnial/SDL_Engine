#include "Component.hpp"
#include "Gameobject.hpp"
#include <Result.hpp>
#include <cassert>
#include <iostream>

struct TestComponent : Engine::GO::ComponentI {

    virtual void init() {};
    virtual void update() {};
    virtual void render() {};
    virtual void destroy() {};
    
};

struct TestComponent1 : Engine::GO::ComponentI {

    virtual void init() {};
    virtual void update() {};
    virtual void render() {};
    virtual void destroy() {};
};

struct TestComponent2 : Engine::GO::ComponentI {
    int health = 100;

    virtual void init() {};
    virtual void update() {};
    virtual void render() {};
    virtual void destroy() {};
};

namespace Engine::GO {
// Added to main
Result<void *, void *> GameObjectConstructorConstructsGameObjectWithRightId() {
    GameObject go1;
    GameObject go2;

    if (go1.id != 0) {
        return Result<void *, void *>::Err(NULL);
    }

    if (go2.id != 1) {
        return Result<void *, void *>::Err(NULL);
    }

    return Result<void *, void *>::Ok(NULL);
};

// Added to main
Result<void *, void *> hasComponentReturnsTrueWhenHasComponent() {
    GameObject go;

    go.add_component<TestComponent>(TestComponent());

    if (!go.has_component<TestComponent>()) {
        return Result<void *, void *>::Err(nullptr);
    }
    return Result<void *, void *>::Ok(nullptr);
}

// Added to main
Result<void *, void *> hasComponentReturnsFalseWhenDoesntHaveComponent() {
    GameObject go;
    go.add_component<TestComponent>(TestComponent());

    if (go.has_component<TestComponent1>()) {
        return Result<void *, void *>::Err(nullptr);
    }
    return Result<void *, void *>::Ok(nullptr);
}

// Added to main
Result<void *, void *> removeComponentRemovesComponent() {

    GameObject go;
    go.add_component<TestComponent>(TestComponent());

    if (!go.has_component<TestComponent>()) {
        return Result<void *, void *>::Err(nullptr);
    }

    go.remove_component<TestComponent>();

    if (go.has_component<TestComponent1>()) {
        return Result<void *, void *>::Err(nullptr);
    }
    return Result<void *, void *>::Ok(nullptr);
}

// Added to main
Result<void *, void *> getComponentReturnsSameComponent() {
    GameObject go;
    go.add_component<TestComponent2>(TestComponent2());

    go.get_component<TestComponent2>().expect("has component")->health = 50;

    if (go.get_component<TestComponent2>().unwrap()->health == 50) {
        return Result<void *, void *>::Ok(nullptr);
    }

    return Result<void *, void *>::Err(nullptr);
}

} // namespace Engine::GO

int main(int argc, char *argv[]) {
    Engine::GO::GameObjectConstructorConstructsGameObjectWithRightId().expect(
        "Constructor failed");
    Engine::GO::hasComponentReturnsTrueWhenHasComponent().expect(
        "hasComponent failed");
    Engine::GO::hasComponentReturnsFalseWhenDoesntHaveComponent().expect(
        "hasComponent failed 2");
    Engine::GO::removeComponentRemovesComponent().expect(
        "remove component failed");

    Engine::GO::getComponentReturnsSameComponent().expect(
        "get component failed");
    std::cout << "all tests pass for Gameobject" << std::endl;
    return 0;
}
