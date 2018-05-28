#include <stdio.h>
#include <math.h>

void incrementStackVariable()
{
	int g;
	printf("Задание 2\n");
	printf("Введите число = ");
	scanf_s("%d", &g);
	printf("Адрес = %p, Значение  = %d\n", &g, g);
	increment(&g);
	printf("Адрес = %p, Значение = %d\n", &g, g);
}
