#include <math.h>
#include <stdio.h>

double a;
void print(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		if ((i + 1) % k == 0)
			continue;
		printf("%.2lf  ", a);
	}
}