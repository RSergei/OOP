#include <math.h>
#include "func.h"
 double x, result;

void func(void)
{
	result = sqrt(pow(3 * x + 2, 2) - 24 * x) / (3 * sqrt(x) - 2 / sqrt(x));
}
