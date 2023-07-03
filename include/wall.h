#ifndef WALL_H
#define WALL_H

#include <SDL2/SDL.h>
#include "vector2.h"

typedef struct
{
   vector2 point1;
   vector2 point2;
} wall;

void wall_create(wall *w, float x1, float y1, float x2, float y2);
void wall_render(wall w, SDL_Renderer *renderer);

#endif
