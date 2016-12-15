#include <RainScene.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <sizes.h>

RainScene::RainScene(int ndrops)
  : ndrops(ndrops) {
  int i;

  drops = (Drop **)calloc (ndrops, sizeof (Drop *));
  if (drops == NULL) {
    perror("calloc");
    return;
  }

  for (i = 0; i < ndrops; i++) {
    drops[i] = new Drop ();
  }
}

RainScene::~RainScene() {
  int i;

  for (i = 0; i < ndrops; i++) {
    delete drops[i];
  }
  free (drops);
}

void RainScene::update() {
  int i;
  for (i = 0; i < ndrops; i++) {
    drops[i]->update ();
  }
}

void RainScene::draw(SDL_Renderer *renderer) {
  int i;

  background (renderer, BACKGROUND_COLOR);

  for (i = 0; i < ndrops; i++) {
    drops[i]->draw (renderer);
  }
}

void RainScene::background(SDL_Renderer *renderer, int r, int g, int b, int a) {
  SDL_SetRenderDrawColor (renderer, r, g, b, a);
  SDL_RenderClear (renderer);
}
