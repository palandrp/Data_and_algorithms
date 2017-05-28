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
void bubleSort(int array[], int M)
{
	int temp, i;
	bool flag = true;
	while (flag)
	{
		i = 1;
		while (i < M)
		{
			flag = false;
			if (array[i-1] > array[i])
			{
				temp = array[i-1];
				array[i-1] = array[i];
				array[i] = temp;
				flag = true;
			}
			// printArray(array,MaxA);
			// printf("\n");
			i++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int array[MaxA];
	randomArray(array,MaxA);
	printArray(array,MaxA);
	printf("\n");
	bubleSort(array,MaxA);
	printArray(array,MaxA);
	return 0;
}