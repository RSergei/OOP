#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Header.h"

void sortHeapArray(int *arr, int n)
{
	n = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	writeArray(arr, n);
	sort(arr, 0,n-1);
	printf("\n Отсортированный массив \n");
	readArray(arr, n);
	free(arr);
}