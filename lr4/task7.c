#include <stdio.h>
#include "Header.h"

void sortStackArray(int *arr, int n)
{
	writeArray(arr, n);
	sort(arr, 0,n-1);
	printf("\n ��������������� ������ \n");
	readArray(arr, n);
}