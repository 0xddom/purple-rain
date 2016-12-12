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
  this->yspeed += this->acc;

  if (this->y > SURFACE_HEIGHT) reset ();
}

void Drop::draw() {
  SDL_SetRenderDrawColor (this->renderer, DROP_COLOR);
  /* SDL_Rect rect;
  rect.x = this->x;
  rect.y = this->y;
  rect.w = this->thick;
  rect.y = this->len;

  SDL_RenderDrawRect (this->renderer, &rect);
  //SDL_RenderDrawLine (this->renderer, this->x, this->y, this->x, this->y + this->len);*/
  drawLine ();
}

void Drop::drawLine() {
  int i;
  for (i = 0; i < this->thick; i++) {
    SDL_RenderDrawLine (this->renderer, this->x + i, this->y, this->x + i, this->y + this->len);
  }
}

void Drop::reset() {
  this->x = random_int (0, SURFACE_WIDTH);
  this->y = random_int (-500, -100);
  this->z = random_int (0, 20);
  this->yspeed = map (this->z, 0, 20, 4, 10);
  this->len = floor (map (this->z, 0, 20, 10, 20));
  this->thick = floor (map (this->z, 0, 20, 1, 3));
  this->acc = map (this->z, 0, 20, 0.01, 0.2);
}
