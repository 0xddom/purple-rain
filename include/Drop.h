#ifndef _DROP_H
#define _DROP_H

#include <Vector.h>

class Drop {
 private:
  Vector pos, speed, acc;
  float len;
  float thick;

 public:
  Drop();
  ~Drop();
  float getX();
  float getY();
  float getThickness();
  float getLength();
  void applyForces();
  bool isOffLimits(int);
  void reset();
};

#endif
