#include "vector2.h"

void vector2_create(vector2 *v, double x, double y)
{
   v->x = x;
   v->y = y;
}

double vector2_distance(vector2 a, vector2 b)
{
   return sqrt(abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}
