#ifndef _SIZES_H
#define _SIZES_H

//#define DEBUG

#define SURFACE_WIDTH 1200
#define SURFACE_HEIGHT 900
#define BACKGROUND_COLOR 230,230,250,255
#define DROP_COLOR 138,43,226,255
#define FPS 60
#define TICKS_PER_FRAME 1000 / FPS
#ifdef DEBUG
#define NDROPS 1
#else
#define NDROPS 500
#endif

#endif
