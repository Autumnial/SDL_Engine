#pragma once
#include <chrono>
namespace Engine {

class Timer {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

  public:
    Timer();
    // elapsed time in nano-seconds
    unsigned long long elapsed_ns();
    // elapsed time in micro-seconds
    unsigned long long elapsed_mcs();
    // elapsed time in milli-seconds
    unsigned long long elapsed_mls();
    // elapsed time in seconds
    unsigned long long elapsed_s();

    // start timeer again
    void reset();
};

} // namespace Engine
