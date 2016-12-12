#ifndef _DROP_H
#define _DROP_H

#include <SDL2/SDL.h>

class Drop {
 private:
  float x;
  float y;
  float yspeed;
  float z;
  float len;
  float thick;
  float acc;

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
