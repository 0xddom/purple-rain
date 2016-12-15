#ifndef _ICOMPOSITENODE_H
#define _ICOMPOSITENODE_H

#include <SDL2/SDL.h>

class ICompositeNode {
 public:
  // ~ICompositeNode() {}
  virtual void update() = 0;
  virtual void draw(SDL_Renderer*) = 0;
};

#endif
