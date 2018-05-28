#include <math.h>
#include "Header.h"
double a, f;
double summ2(double eps)
{
	a = eps + 1.0;
	f = 0.0;
	int i = 0;
	while (fabs(a) > eps)
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		f += a;
		++i;
	}
	return (f);
}