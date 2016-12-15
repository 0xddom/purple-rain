#include <Game.h>
#include <sizes.h>
#include <RainScene.h>

int main(int argc, char **argv) {
  Game *game = new Game(new RainScene (NDROPS));

  int ret = game->run();
  delete game;

  return ret;
}
