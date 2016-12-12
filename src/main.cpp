#include <iostream>
#include <Game.h>
#include <utils.h>

int main(int argc, char **argv) {
  Game *game = new Game(argc, argv);

  int ret = game->run();
  delete game;

  return ret;
}
