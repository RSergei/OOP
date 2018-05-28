#include <stdio.h>
//Вариант 17 - быстрая сортировка
void sort(int *arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = arr[(left + right) / 2];
		do
		{
			while (arr[left] < middle) left++;
			while (arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		sort(arr, first, right);
		sort(arr, left, last);
	}
}