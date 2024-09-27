#pragma once

namespace Engine {

class Scene {

    friend class Game;

  private:
    void pre_init();
    void post_unload();

  public:
    virtual void unload() = 0;
    virtual void load() = 0;

    virtual void update(double dt) = 0;
    // TODO: figure out how often this function should run :p
    virtual void fixed_update() = 0;

    virtual void render() = 0;
};
} // namespace Engine
