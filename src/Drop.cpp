#include <Drop.h>
#include <sizes.h>
#include <utils.h>
#include <SDL2/SDL.h>
#include <stdio.h>

Drop::Drop(SDL_Renderer *renderer) {
  this->renderer = renderer;

  reset ();
}

Drop::~Drop() {}

void Drop::update() {
  this->y += this->yspeed;

  if (this->y > SURFACE_HEIGHT) reset ();
}

void Drop::draw() {
  SDL_SetRenderDrawColor (this->renderer, DROP_COLOR);
  SDL_RenderDrawLine (this->renderer, this->x, this->y, this->x, this->y + 10);
}

void Drop::reset() {
  this->x = random_int (0, SURFACE_WIDTH);
  this->y = random_int (-500, -100);
  this->yspeed = 5;
}
