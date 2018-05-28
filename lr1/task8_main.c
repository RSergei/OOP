#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "H.h"
int main(void)
{
	system("chcp 1251"); /*Переход в консоли на русский язык*/
	system("cls"); /*Очистка консоли*/
	x = 4;
	func();
	printf("При Х=4 Ответ = %.3lf\n", result);
	printf("Введите Х=");
	scanf_s("%lf", &x);
	func();
	printf("Ответ = %.3lf", result);
	getchar();
	getchar();

	return(0);
}
