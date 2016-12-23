#include <DropNode.h>
#include <SDL2/SDL.h>
#include <sizes.h>
#include <Drop.h>

#define DROP_RECT(drop, i) \
  drop->getX () + i,       \
    drop->getY (),         \
    drop->getX () + i,     \
    drop->getY () + drop->getLength ()

DropNode::DropNode()
  : drop(new Drop ()) { }

DropNode::~DropNode() {
  delete drop;
}

void DropNode::update() {
  drop->applyForces ();
  if (drop->isOffLimits (SURFACE_HEIGHT)) {
    drop->reset ();
  }
}

void DropNode::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor (renderer, DROP_COLOR);
  drawLine (renderer);
}

void DropNode::drawLine(SDL_Renderer *renderer) {
  int i;
  for (i = 0; i < drop->getThickness (); i++) {
    SDL_RenderDrawLine (renderer, DROP_RECT(drop, i));
  }
}
