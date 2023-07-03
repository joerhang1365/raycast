#include "wall.h"

void wall_create(wall *w, float x1, float y1, float x2, float y2)
{
   w->point1.x = x1;
   w->point1.y = y1;
   w->point2.x = x2;
   w->point2.y = y2;
}

void wall_render(wall w, SDL_Renderer *renderer)
{
   SDL_SetRenderDrawColor(renderer, 255.0f, 255.0f, 255.0f, 255.0f);
   SDL_RenderDrawLine(renderer, w.point1.x, w.point1.y, w.point2.x, w.point2.y);
}

