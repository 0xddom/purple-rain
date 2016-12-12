#ifndef _DROP_H
#define _DROP_H

#include <SDL2/SDL.h>

class Drop {
 private:
  float x;
  float y;
  float yspeed;

  SDL_Renderer *renderer;

  void reset();
 public:
  Drop(SDL_Renderer *);
  ~Drop();
  void update();
  void draw();
};

#endif
