#include "math.h"
namespace Engine::Math {
template <typename T = float> class Vector2 {
public:
  T x, y;


  Vector2(T x, T y) {
    this->x = x;
    this->y = y;
  };

  double magnitude() { return sqrt(x * x + y * y); };
  double direction();
  double angle_to(Vector2<T> other) {

    return acos((this->dot(other) / (this->magnitude() * other.magnitude())));
  };

  Vector2<T> operator+(const Vector2<T> &rhs) {

    return Vector2<T>{x = this->x + rhs.x, y = this->y + rhs.y};
  };
  Vector2<T> operator-(const Vector2<T> &rhs) {

    return Vector2<T>{x = this->x - rhs.x, y = this->y - rhs.y};
  };

  double dot(Vector2<T> &other) {

    return this->x * other.x + this->y * other.y;
  };
};
} // namespace Engine::Math
