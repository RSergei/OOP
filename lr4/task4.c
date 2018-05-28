#include <stdio.h>

void writeArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=", i + 1);
		scanf_s("%d", &arr[i]);
	}
}