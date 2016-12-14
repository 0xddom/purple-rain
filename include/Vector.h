#ifndef _VECTOR_H
#define _VECTOR_H

class Vector {
 private:

 public:
  float x, y, z;

  Vector();                    // 0 vector
  Vector(float, float);        // 2D vector
  Vector(float, float, float); // 3D vector

  Vector operator+(Vector);
  Vector operator+=(Vector);
};

#endif
