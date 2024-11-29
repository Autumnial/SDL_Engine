#pragma once
namespace Engine::GO {
    class GameObject; 
}
#include "Scene.hpp"
namespace Engine::GO {
class GameObject;
template <typename T> int get_id();
} // namespace Engine::GO
#include "Component.hpp"
#include <Option.hpp>
#include <Result.hpp>
#include <bitset>
#include <vector>

namespace Engine::GO {

const int BITSET_SIZE = 500;

Result<void *, void *> GameObjectConstructorConstructsGameObjectWithRightId();

class GameObject {
    friend Result<void *, void *>
    GameObjectConstructorConstructsGameObjectWithRightId();
    friend class Scene;

    inline static int        next_id = 0;
    std::bitset<BITSET_SIZE> component_map;
    // TODO: my good fucking god this is so memory inefficient, 
    // prob worth a refactor at some point!! works for now though :)
    Option<ComponentI *> components[BITSET_SIZE];
    int                  id;


  public:
    Scene * scene; 
    GameObject();
    ~GameObject();
    void update();
    void render();

    template <typename T> bool has_component() {
        return component_map.test(get_id<T>());
    }
    template <typename T> void add_component(T comp) {
        if (has_component<T>()) {
            return;
        }

        T *c_ptr = new T(comp);

        c_ptr->owner = this;
        
        c_ptr->init();  

        components[get_id<T>()] =
            Option<ComponentI *>::Some((ComponentI *)c_ptr);
        component_map.set(get_id<T>(), true);
    };

    template <typename T> void remove_component() {
        if (!has_component<T>()) {
            return;
        };

        auto p = get_component<T>().unwrap();
        delete p;

        components[get_id<T>()] = Option<ComponentI *>::None();
        component_map.reset(get_id<T>());
    }

    template <typename T> Option<T *> get_component() {
        if (!has_component<T>()) {
            return Option<T *>::None();
        }

        auto comp = components[get_id<T>()].unwrap();
        return Option<T *>::Some(dynamic_cast<T *>(comp));
    };
};
} // namespace Engine::GO
