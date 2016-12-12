#include <Game.h>
#include <SDL2/SDL.h>
#include <sizes.h>
#include <Drop.h>
#include <stdio.h>
#include <Timer.h>
#include <utils.h>
#include <stdlib.h>

Game::Game(int argc, char** argv) {
  init_random ();
  this->success = initSDL () && initDrops ();
  if(this->success) {
    this->quit = false;
    //this->drop = new Drop (this->renderer);

  }
}

Game::~Game() {
  SDL_DestroyWindow (this->window);
  SDL_Quit ();
}

int Game::run() {
  if (!success) return -1;
  loop ();
  return 0;
}

bool Game::initDrops() {
  this->drops = (Drop **)calloc (NDROPS, sizeof (Drop *));
  int i;
  if (this->drops == NULL) {
    fprintf (stderr, "Could not create the drops\n");
    return false;
  }

  for (i = 0; i < NDROPS; i++) {
    this->drops[i] = new Drop (this->renderer);
  }

  return true;
}

bool Game::initSDL() {
  this->window = NULL;
  this->surface = NULL;

  if (SDL_Init (SDL_INIT_VIDEO) < 0) {
    fprintf (stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError ());
    return false;
  }
  this->window = SDL_CreateWindow ("Purple Rain",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SURFACE_WIDTH, SURFACE_HEIGHT, SDL_WINDOW_SHOWN);
  if (this->window == NULL) {
    fprintf (stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError ());
    return false;
  }
  this->surface = SDL_GetWindowSurface (this->window);
  this->renderer = SDL_GetRenderer(this->window);
  if (this->renderer == NULL) {
    fprintf (stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError ());
    return false;
  }
  SDL_UpdateWindowSurface (this->window);

  return true;
}

void Game::loop() {
  Timer timer;
  while (!quit) {
    timer.start ();
    draw ();
    update ();
    int frameTicks = timer.getTicks ();
    if (frameTicks < TICKS_PER_FRAME) SDL_Delay (TICKS_PER_FRAME - frameTicks);
  }
}

void Game::stopLoop() {
  this->quit = true;
}

void Game::update() {
  SDL_Event e;
  while (SDL_PollEvent (&e) != 0) {
    if (e.type == SDL_QUIT) stopLoop();
  }
  int i;
  for (i = 0; i < NDROPS; i++)
    this->drops[i]->update ();
}

void Game::draw() {
  background (BACKGROUND_COLOR);
  int i;
  for (i = 0; i < NDROPS; i++)
    this->drops[i]->draw ();
  SDL_RenderPresent (this->renderer);
}

void Game::background(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor ( this->renderer, r, g, b, a);
  SDL_RenderClear ( this->renderer );
  // SDL_FillRect (this->surface, NULL, SDL_MapRGB (this->surface->format, r, g, b));
}
