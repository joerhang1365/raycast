#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include "constants.h"
#include "vector2.h"
#include "wall.h"
#include "raycast.h"

#define NUMBER_OF_RAYS 360

typedef struct
{
   vector2 position;
   ray rays[NUMBER_OF_RAYS];
} object;

void object_create(object *o, float x, float y);
void object_update(object *o, float x, float y);
void object_render(object o, SDL_Renderer *renderer);
void object_raycast(object *o, wall *w, int number_of_walls);

#endif
