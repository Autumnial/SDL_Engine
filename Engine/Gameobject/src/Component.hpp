#pragma once
#include <cstdlib>
#include <iterator>
#include <type_traits>
#include "iostream"
namespace Engine::GO {
class ComponentI;
}

#include "Gameobject.hpp"
namespace Engine::GO {
extern int id_count;

template <typename T> int get_id() {

    if (!std::is_base_of<ComponentI, T>()) {
        std::cout << "getID called on non-component object" << std::endl;
        std::exit(-1);
    }

    static int id = id_count++;
    return id;
}

class ComponentI {
    friend GameObject;

  protected:
    GameObject *owner;

  public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void init() {};
    virtual void destroy() {};
};

} // namespace Engine::GO
