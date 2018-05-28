#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double func(double x)
{
	double resh;
	resh = sqrt(pow(3 * x + 2, 2) - 24 * x) / (3 * sqrt(x) - 2 / sqrt(x));
	return(resh);
}


int main(void)
{
	system("chcp 1251"); /*Переход в консоли на русский язык*/
	system("cls"); /*Очистка консоли*/

	double a, x=4;

	a = func(x);

	printf("При X=4 Ответ = %.3lf\n", a);

	printf("Введите Х=");

	scanf_s("%lf", &x);

	a = func(x);

	printf("Ответ = %.3lf", a);

	getchar();
	getchar();


	return(0);
}
