#ifndef _RAINSCENE_H
#define _RAINSCENE_H

#include <ICompositeNode.h>
#include <SDL2/SDL.h>
#include <Drop.h>

class RainScene : public ICompositeNode {
 private:
  int ndrops;
  Drop **drops;

  void background(SDL_Renderer*,int, int, int, int);

 public:
  RainScene(int);
  ~RainScene();

  virtual void update();
  virtual void draw(SDL_Renderer *);
};

#endif
