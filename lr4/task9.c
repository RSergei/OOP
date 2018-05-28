#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Header.h"

int main(void)
{
	setlocale(LC_ALL, "RUS");
	int g, x;
	const int n = 10;
	int arr[10];

	while (g = -1)
	{
		printf("Задание 2 - 1\n");
		printf("Задание 3 - 2\n");
		printf("Задание 7 - 3\n");
		printf("Задание 8 - 4\n");
		printf("Выход - 5\n");
		printf("Выберите задание\n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:
		{
			printf("Число в стеке\n");
			incrementStackVariable();
			break;
		}
		case 2:
		{
			printf("Число в динамической памяти\n");
			incrementHeapVariable();
			break;
		}
		case 3:
		{
			printf("Массив из 10-элементов в стеке\n");
			sortStackArray(arr, n);
			break;
		}
		case 4:
			printf("Массив из n-элементов в динамической памяти\n");
			sortHeapArray(arr, n);
			break;
		case 5:
			return(0);
		default:
			printf("Неправильный ввод\n");
			break;
		}
		getchar();
		getchar();
	}
	return(0);
}