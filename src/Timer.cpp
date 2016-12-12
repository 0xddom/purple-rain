#include <Timer.h>
#include <SDL2/SDL.h>

Timer::Timer() {
  startTicks = 0;
  pausedTicks = 0;

  paused = false;
  started = false;
}

void Timer::setState(bool started, bool paused, int startTicks, int pausedTicks) {
  this->started = started;
  this->paused = paused;
  this->startTicks = startTicks;
  this->pausedTicks = pausedTicks;
}

void Timer::start() {
  setState (true, // started
            false, // paused
            SDL_GetTicks (), // startTicks
            0); // pausedTicks
}

void Timer::stop() {
  setState (false, // started
            false, // paused
            0, // startTicks
            0); // paused Ticks
}

void Timer::pause() {
  if (started && !paused) {
    setState (started,
              true,
              0,
              SDL_GetTicks () - startTicks);
  }
}

void Timer::unpause() {
  if (started && paused) {
    setState (started,
              false,
              SDL_GetTicks () - pausedTicks,
              0);
  }
}

int Timer::getTicks() {
  if (started) {
    if (paused) return pausedTicks;
    else return SDL_GetTicks () - startTicks;
  }
  return 0;
}

bool Timer::isStarted() {
  return started;
}

bool Timer::isPaused() {
  return paused;
}
