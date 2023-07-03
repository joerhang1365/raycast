#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdlib.h>
#include <math.h>

typedef struct
{
   double x;
   double y;
} vector2;

void vector2_create(vector2 *v, double x, double y);
double vector2_distance(vector2 a, vector2 b);

#endif
