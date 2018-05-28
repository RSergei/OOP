#include <stdio.h>	//Использование библиотеки ввода/вывода

#include <math.h>	//Использование математической библиотеки

#include <stdlib.h> //Использование функции system

double func(double x);

_Bool isInArea(double x, double y);

int main(void)
{

	system("chcp 1251"); /*Переход в консоли на русский язык*/

	system("cls"); /*Очистка консоли*/
	
	double  x, y;
	
	int n;

	printf("Выберите задание 1 или 2:\n");

	scanf_s("%d", &n);

	switch (n)
	{
	
	case 1:
	{

		printf("Выполнение первого задания:\n");

		printf("Введите Х=");

		scanf_s("%lf", &x);

		printf("Введите Y=");

		scanf_s("%lf", &y);

		isInArea( x, y);

		printf("%d", isInArea(x, y));
	}

	break;

	case 2:

	{

		printf("Выполнение второго задания:\n");

		printf("Введите Х=");

		scanf_s("%lf", &x);

		func(x);

		printf("%.3lf", func(x));

	}

	break;

	default:

		printf("Неправильный ввод ");

		break;

	}

	getchar();

	getchar();

	return(0);

}

//Создадим функцию, которая будет просчитывыть попадание в заштрихованную область
_Bool isInArea(double x, double y)

{

	if (sqrt(x*x + y * y) <= 1)

		if (x >= 0 && y <= 0)

			return(1);

		else if (x <= 0 && y >= 0)

			return(1);

		else

			return(0);

	else
		return(0);

}

//Создадим функцию для второго задания

double func(double x)
{

	double f;

	x >= 1.1 ? (f = (9 - x)) : (f = ((sin(3 * x)) / (pow(x, 4) + 1)));

	return(f);
}

