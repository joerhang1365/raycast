#include "raycast.h"

void ray_create(ray *r, float position_x, float position_y, float length, float radian)
{
   r->position.x = position_x;
   r->position.y = position_y;
   r->length = length;
   r->direction.x = cosf(radian);
   r->direction.y = sinf(radian);
}

void ray_lookat(ray *r, float x, float y)
{
   r->direction.x = math_normalize(x - r->position.x, 0, SCREEN_WIDTH);
   r->direction.y = math_normalize(y - r->position.y, 0, SCREEN_HEIGHT);
}

void ray_render(ray r, SDL_Renderer *renderer)
{
   SDL_SetRenderDrawColor(renderer, 255.0f, 255.0f, 255.0f, 255.0f);
   SDL_RenderDrawLine(renderer, r.position.x, r.position.y, r.position.x + r.direction.x * r.length, r.position.y + r.direction.y * r.length);
}

vector2 ray_intersect(ray r, wall w)
{
   const float x1 = w.point1.x;
   const float y1 = w.point1.y;
   const float x2 = w.point2.x;
   const float y2 = w.point2.y;

   const float x3 = r.position.x;
   const float y3 = r.position.y;
   const float x4 = r.position.x + r.direction.x;
   const float y4 = r.position.y + r.direction.y;

   const float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
   if(denominator == 0)
   {
      // -1 is value for null
      const vector2 point = {-1, -1};
      return point;
   }

   const float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
   const float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

   if(t > 0 && t < 1 && u > 0)
   {
      const vector2 point = {x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
      return point;
   }
   else
   {
      const vector2 point = {-1, -1};
      return point;
   }
}
