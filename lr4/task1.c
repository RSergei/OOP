#include <math.h>
#include <stdio.h>

void increment(int *n)
{
	if (*n != 0)
	{
		printf("Задание 1\n");
		printf("Адрес =%p , значение = %d\n", n, *n);
		++*n;
		printf("Новое значение = %d\n", *n);
	}
	else
		printf("Указатель пустой");
}