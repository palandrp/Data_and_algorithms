/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 28.05.17.
 */

#include "c1hw5.h"

#define MaxA 30

/**
* Пузырьковая сортировка, базовый вариант.
*/
void b_bubleSort(int a[], int N)
{
	int i, j, count = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N-1; j++)
			if (a[j] > a[j+1])
			{
				swap(&a[j], &a[j+1]); count++;
			}
	printf("Вычислительная сложность: %d\n", count);
}

/**
* Пузырьковая сортировка, собственный вариант.
*/
void bubleSort(int array[], int M)
{
	int count = 0;
	for (int j = 1; j < M; j++)
		for (int i = 1; i < M; i++)
			if (array[i-1] > array[i])
			{
				swap(&array[i-1], &array[i]); count++;
			}
	printf("Вычислительная сложность: %d\n", count);
}

int main(int argc, char const *argv[])
{
	int array[MaxA];

	printf("Базовая пузырьковая:\n");
	randomArray(array,MaxA,1000);
	printArray(array,MaxA);
	printf("\n");
	b_bubleSort(array,MaxA);
	printArray(array,MaxA);
	printf("\n\n");

	printf("Собственная пузырьковая:\n");
	randomArray(array,MaxA,1000);
	printArray(array,MaxA);
	printf("\n");
	bubleSort(array,MaxA);
	printArray(array,MaxA);

	return 0;
}