#include <math.h>
#include <stdio.h>

double summ2(double eps)
{
	double a = 0.66;
	double value = 0.0;
	for (int i = 0; fabs(a) >= eps; ++i)
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		value = value + a;
		printf(" %lf\n", a);
	}
	printf("Последний член ряда %lf\n", a);
	return(value);
}