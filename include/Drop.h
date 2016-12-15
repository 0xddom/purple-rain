#ifndef _DROP_H
#define _DROP_H

#include <SDL2/SDL.h>
#include <Vector.h>
#include <ICompositeNode.h>

class Drop : public ICompositeNode {
 private:
  Vector pos, speed, acc;
  //  float x;
  //  float y;
  //  float yspeed;
  //  float z;
  float len;
  float thick;
  //  float acc;

  void reset();
  void drawLine(SDL_Renderer*);
 public:
  Drop();
  virtual ~Drop();
  virtual void update();
  virtual void draw(SDL_Renderer*);
};

#endif
