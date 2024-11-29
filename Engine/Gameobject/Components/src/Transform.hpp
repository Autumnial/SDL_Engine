#pragma once
#include "Component.hpp"
#include "Vector.hpp"
namespace Engine::GO::Components {

class Transform : public ComponentI {
  public:
    Transform()
        :  position(0, 0), rotation(0, 0), scale(0, 0) {}

    Math::Vector2<float> position;
    Math::Vector2<float> rotation;
    Math::Vector2<float> scale;
    float                z_index;

    virtual void render();
    virtual void update();
};

} // namespace Engine::GO::Components
