#ifndef RAYCAST_H
#define RAYCAST_H

#include <SDL2/SDL.h>
#include <math.h>
#include "constants.h"
#include "vector2.h"
#include "functions.h"
#include "wall.h"

typedef struct
{
   vector2 position;
   vector2 direction;
   float length;
} ray;

void ray_create(ray *r, float position_x, float position_y, float length, float radian);
void ray_lookat(ray *r, float x, float y);
void ray_render(ray r, SDL_Renderer *renderer);
vector2 ray_intersect(ray r, wall w);

#endif
