#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void incrementHeapVariable()
{
	printf("Задание 3\n");

	int *d = (int *)malloc(sizeof(int));
	printf("Введите число ");
	scanf_s("%d", d);

	printf("Адрес = %p, Значение = %d \n", d, *d);
	increment(d);
	printf("Адрес = %p, Значение = %d \n", d, *d);
	free(d);
}
