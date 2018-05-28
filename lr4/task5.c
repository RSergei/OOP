#include <stdio.h>

void readArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\n", i + 1, arr[i]);
	}
}