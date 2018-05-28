#include <math.h>
#include <stdio.h>
#include <windows.h>
#include "Header.h"

int main(void)
{
	system("chcp 1251");
	system("cls");
	int i = 0, numOfTask;

	while (i != -1)
	{
		system("cls");
		printf("Задание 1\n");
		printf("Задание 2\n");
		printf("Задание 3\n");
		printf("Задание 4\n");
		printf("Задание 5\n");
		printf("Выход - 6\n\n");
		int n = 0, k = 0;
		double eps = 0.0;

		printf("Введите номер задания: ");
		scanf_s("%d", &numOfTask);
		switch (numOfTask)
		{
		case 1:
			system("cls");
			printf("Задание 1\n");
			printf("Введите число слагаемых n: ");
			scanf_s("%d", &n);
			printf("Cумма = %lf\n\n", summ(n));
			system("pause");
			break;


		case 2:
			system("cls");
			printf("Задание 2\n");
			printf("Введите точность eps = ");
			scanf_s("%lf", &eps);
			printf("Сумма = %f\n\n", summ2(eps));
			system("pause");
			break;

		case 3:
			system("cls");
			printf("Задание 3\n");
			printf("Введите n=");
			scanf_s("%d", &n);
			printf("Введите k=");
			scanf_s("%d", &k);
			printf("Последовательность = \n");
			print(n, k);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("Задание 4\n");
			printf("Введите еps = ");
			scanf_s("%lf", &eps);
			printf("Номер =  %d\n\n", findFirstElement(eps));
			system("pause");
			break;
		case 5:
			system("cls");
			printf("Задание 5\n");
			printf("Введите eps = ");
			scanf_s("%lf", &eps);
			printf("Номер = %d\n\n", findFirstNegativeElement(eps));
			system("pause");
			break;
		case 6:
			i = -1;
			break;
		default:
			printf("Неправильный ввод \n");
			system("pause");
		}

	}
}