#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <SDL2/SDL.h>
#include "Entity.h"
#include "Player.h"
#include "Enermy.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern PlayerClass PlayerInstance;
extern Entity Box;

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

#endif