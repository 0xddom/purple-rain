#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#include <Drop.h>
#include <ICompositeNode.h>

class Game {
 private:
  SDL_Window *window;
  SDL_Surface *surface;
  SDL_Renderer *renderer;

  ICompositeNode *root;

  bool quit;
  bool success;

  bool initSDL();
  /* bool initDrops(); */
  void loop();
  void stopLoop();

  void background(int, int, int, int);

  void update();
  void draw();
 public:
  Game(ICompositeNode*);
  ~Game();
  int run();
};

#endif
