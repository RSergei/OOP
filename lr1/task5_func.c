#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
	double  a;
	a = sqrt(pow(3 * x + 2, 2) - 24 * x) / (3 * sqrt(x) - 2 / sqrt(x));
	return(a);
}
