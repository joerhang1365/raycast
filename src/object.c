#include "object.h"

void object_create(object *o, float x, float y)
{
   o->position.x = x;
   o->position.y = y;

   unsigned int index = 0;
   for(float i = 0; i < 360; i += (float) 360 / NUMBER_OF_RAYS)
   {
      float radian = i * PI / 180;
      ray_create(&o->rays[index], x, y, 0, radian); 
      index++;
   }
}

void object_update(object *o, float x, float y)
{
   o->position.x = x;
   o->position.y = y;

   unsigned int index = 0;
   for(float i = 0; i < 360; i += (float) 360 / NUMBER_OF_RAYS)
   {
      float radian = i * PI / 180;
      ray_create(&o->rays[index], x, y, 0, radian); 
      index++;
   }
}

void object_render(object o, SDL_Renderer *renderer)
{
   SDL_Rect rect = {o.position.x, o.position.y, 10, 10};
   SDL_RenderDrawRect(renderer, &rect);
   for(int i = 0; i < NUMBER_OF_RAYS; i++)
   {
      ray_render(o.rays[i], renderer);
   }
}

void object_raycast(object *o, wall *w, int number_of_walls)
{
   for(int i = 0; i < NUMBER_OF_RAYS; i++)
   {
      vector2 nearest_wall = {-1, -1}; // NULL
      float nearest_distance = SCREEN_WIDTH; // max number it can be
      for(int j = 0; j < number_of_walls; j++)
      {
         // find the nearest wall
         const vector2 point = ray_intersect(o->rays[i], w[j]);
         if(point.x > -1 && point.y > -1)
         {
            const float distance = vector2_distance(point, o->position);
            if(distance < nearest_distance)
            {
               nearest_distance = distance;
               nearest_wall = point;
            }
         }
      }
      if(nearest_wall.x > -1 && nearest_wall.y > -1)
      {
         const float distance = vector2_distance(nearest_wall, o->position);
         o->rays[i].length = distance;
      }
   }
}
