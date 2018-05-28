#include <math.h>
#include <stdio.h>
#include "Header.h"

double a;
void print(int n, int k)
{

	int i = 0;
	do
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		if ((i + 1) % k == 0)
		{
			++i;
			continue;
		}
		++i;
		printf("%f ", a);
	} while (i < n);
}