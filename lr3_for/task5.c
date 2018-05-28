#include <math.h>
#include <stdio.h>

int findFirstNegativeElement(double eps)
{
	double a;
	for (int i = 0; ; ++i)
	{
		a = pow(-1, i)*(1 - ((pow(i, 2) + 1) / (pow(i, 2) + 3)));
		if (fabs(a) <= eps && a < 0.0)
		{
			return(i + 1);
		}
	}
}
