#ifndef _DROP_H
#define _DROP_H

#include <SDL2/SDL.h>
#include <Vector.h>

class Drop {
 private:
  Vector pos, speed, acc;
  //  float x;
  //  float y;
  //  float yspeed;
  //  float z;
  float len;
  float thick;
  //  float acc;

  SDL_Renderer *renderer;

  void reset();
  void drawLine();
 public:
  Drop(SDL_Renderer *);
  ~Drop();
  void update();
  void draw();
};

#endif
