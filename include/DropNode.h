#ifndef _DROP_NODE_H
#define _DROP_NODE_H

#include <SDL2/SDL.h>
#include <Drop.h>
#include <ICompositeNode.h>

class DropNode : public ICompositeNode {
 private:
  Drop *drop;
  void drawLine(SDL_Renderer *);
 public:
  DropNode();
  virtual ~DropNode();
  virtual void update();
  virtual void draw(SDL_Renderer *);
};

#endif
