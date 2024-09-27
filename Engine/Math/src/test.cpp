#include "Vector.hpp"
#include <cassert>
#include <iostream>

void test_VectorDotProduct() {
  Engine::Math::Vector2<double> v1 = Engine::Math::Vector2(1., 2.);
  Engine::Math::Vector2<double> v2 = Engine::Math::Vector2(2., 1.);

  assert(v1.dot(v2) == 4);
}

void test_VectorAngle(){
  Engine::Math::Vector2<double> v1 = Engine::Math::Vector2(1., 2.);
  Engine::Math::Vector2<double> v2 = Engine::Math::Vector2(2., 1.);

  assert(v1.angle_to(v2) >= 0.642 && v1.angle_to(v2) <= 0.644);

}

int main(int argc, char *argv[]) { 
    test_VectorDotProduct(); 
    test_VectorAngle(); 

    std::cout << "all tests pass for Vector" << std::endl; 
}

