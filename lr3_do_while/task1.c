#include <math.h>
#include "Header.h"

double a, f;
double summ(int n)
{

	f = 0.0;
	int i = 0;

	do
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		f += a;
		++i;
	} while (i < n);
	return f;
}