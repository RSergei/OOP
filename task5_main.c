#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x);

int main(void)
{
	system("chcp 1251"); /*Переход в консоли на русский язык*/
	system("cls"); /*Очистка консоли*/

	double result, x = 4;

	result = func(x);
	printf("При X=4 Ответ = %.3lf\n", result);
	printf("Введите Х=");
	scanf_s("%lf", &x);

	result = func(x);
	printf("Ответ = %.3lf", result);

	getchar();
	getchar();


	return(0);
}
