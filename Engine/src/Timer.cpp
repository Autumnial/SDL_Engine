#include "Timer.hpp"
#include <chrono>

namespace Engine {

    Timer::Timer(){
        start = std::chrono::high_resolution_clock::now(); 
    }

unsigned long long Timer::elapsed_ns() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
               std::chrono::high_resolution_clock::now() - start)
        .count();
}

unsigned long long Timer::elapsed_mcs() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::high_resolution_clock::now() - start)
        .count();
}

unsigned long long Timer::elapsed_mls() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::high_resolution_clock::now() - start)
        .count();
}

unsigned long long Timer::elapsed_s() {
    return std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::high_resolution_clock::now() - start)
        .count();
}

void Timer::reset(){start = std::chrono::high_resolution_clock::now();}
} // namespace Engine
