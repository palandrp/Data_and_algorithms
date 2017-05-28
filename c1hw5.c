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
	int i, j;
	for (i = 0; i < N; i++)
	for (j = 0; j < N-1; j++)
	if (a[j] > a[j+1])
	{
		swap(&a[j], &a[j+1]);
	}
}

/**
* Пузырьковая сортировка, собственный вариант.
*/
void bubleSort(int array[], int M)
{
	int temp, i;
	bool flag = true;
	while (flag)
	{
		i = 1;
		flag = false;
		while (i < M)
		{
			if (array[i-1] > array[i])
			{
				temp = array[i-1];
				array[i-1] = array[i];
				array[i] = temp;
				flag = true;
			}
			i++;
		}
	}
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