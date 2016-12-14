#include <Drop.h>
#include <sizes.h>
#include <utils.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <Vector.h>

Drop::Drop(SDL_Renderer *renderer)
  : pos(Vector()), speed(Vector()),
    acc(Vector()), renderer(renderer) {
  reset ();
}

Drop::~Drop() {}

void Drop::update() {
  pos += speed;
  speed += acc;

  if (pos.y > SURFACE_HEIGHT) reset ();

#if 0
  fprintf(stdout,
          "pos(%f, %f, %f)\n"
          "speed(%f, %f, %f)\n"
          "acc(%f, %f, %f)\n\n",
          pos.x, pos.y, pos.z,
          speed.x, speed.y, speed.z,
          acc.x, acc.y, acc.z);
#endif
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
    SDL_RenderDrawLine (this->renderer, pos.x + i, pos.y, pos.x + i, pos.y + this->len);
  }
}

void Drop::reset() {
  pos.x = random_int (0, SURFACE_WIDTH);
  pos.y = random_int (-500, -100);
  pos.z = random_int (0, 20);
  speed.y = map (pos.z, 0, 20, 4, 10);
  len = floor (map (pos.z, 0, 20, 10, 20));
  thick = floor (map (pos.z, 0, 20, 1, 3));
  acc.y = map (pos.z, 0, 20, 0.01, 0.2);
}
