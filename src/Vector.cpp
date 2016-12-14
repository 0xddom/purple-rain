#include <Vector.h>

Vector::Vector()
  : x(0), y(0), z(0) {}

Vector::Vector(float x, float y)
  : x(x), y(y), z(0) {}

Vector::Vector(float x, float y, float z)
  : x(x), y(y), z(z) {}

static Vector add2Vectors(Vector v1, Vector v2) {
  return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector Vector::operator+(Vector other) {
  return add2Vectors(*this, other);
}

Vector Vector::operator+=(Vector other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return Vector(x,y,z);
}
