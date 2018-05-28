#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	system("chcp 1251");

	system("cls");

	double fun, x = 4;

	fun = sqrt(pow(3 * x + 2, 2) - 24 * x) / (3 * sqrt(x) - 2 / sqrt(x));

	printf("Результат при x=4 \n fun= %.3lf \n", fun);

	printf("введите x= ");

	scanf_s("%lf", &x);

	fun = sqrt(pow(3 * x + 2, 2) - 24 * x) / (3 * sqrt(x) - 2 / sqrt(x));

	printf("Результат при введенном x с клавиатуры \n fun= %.3lf ", fun);

	getchar(), getchar();


	return 0;
}
