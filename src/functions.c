#include "functions.h"

double math_normalize(double value, double min, double max)
{
   return (value - min) / (max - min);
}
