#pragma once
#include <chrono>
namespace Engine {

class Timer {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

  public:
    Timer();
    // Elapsed time in nanoseconds
    unsigned long long elapsed_ns();
    // Elapsed time in microseconds
    unsigned long long elapsed_mcs();
    // Elapsed time in milliseconds
    unsigned long long elapsed_mls();
    // Elapsed time in seconds
    unsigned long long elapsed_s();

    // Start timer again
    void reset();
};

} // namespace Engine
