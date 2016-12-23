#include <Drop.h>
#include <sizes.h>
#include <utils.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <Vector.h>

Drop::Drop()
  : pos(Vector()), speed(Vector()), acc(Vector()) {
  reset ();
}

Drop::~Drop() {}

void Drop::applyForces() {
  pos += speed;
  speed += acc;
}

bool Drop::isOffLimits(int limit) {
  return pos.y > limit;
}

void Drop::reset() {
  pos.x = random_int (0, SURFACE_WIDTH);
  pos.y = random_int (-500, -100);
  pos.z = random_int (0, 20);
  speed.y = map (pos.z, 0, 20, 4, 10);
  len = floor (map (pos.z, 0, 20, 10, 20));
  thick = floor (map (pos.z, 0, 20, 1, 3));
  acc.y = map (pos.z, 0, 20, 0.01, 0.2);
}

float Drop::getX() {
  return pos.x;
}

float Drop::getY() {
  return pos.y;
}

float Drop::getThickness() {
  return thick;
}

float Drop::getLength() {
  return len;
}
