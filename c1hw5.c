/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 28.05.17.
 */

#include "c1hw5.h"

#define MAX_A 30
#define PAUSE 30000

/**
 * 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить
 * количество операций сравнения оптимизированной и не оптимизированной программы.
 * 2. Реализовать шейкерную сортировку.
 * 3. Реализовать бинарный алгоритм поиска в виде функции, которой
 * передается отсортированный массив. Функция возвращает индекс найденного
 * элемента или -1, если элемент не найден.
 * 4. *Подсчитать количество операций для каждой из сортировок и сравнить
 * его с асимптотической сложностью алгоритма.
 */

/**
 * Пузырьковая сортировка, базовый вариант.
 */
void b_bubleSort(int a[], int N)
{
    int i, j;
    unsigned long count = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N-1; j++)
            if (a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                count++;
            }
   	printf("\nВычислительная сложность O(n^2): %ld\n", count);
}

/**
 * Пузырьковая сортировка, собственный вариант.
 */
void bubleSort(int array[], int M)
{
	unsigned long count = 0;
    for (int j = 1; j < M; j++)
        for (int i = 1; i < M; i++)
            if (array[i-1] > array[i])
            {
                array[i-1] ^= array[i];
                array[i] ^= array[i-1];
                array[i-1] ^= array[i];
                count++;
            }
   	printf("\nВычислительная сложность O(n^2): %ld\n", count);
}

/**
 * Шейкерная сортировка.
 */
void cocktailSort(int array[], int M)
{
    int left = 0;
    int right = M - 1;
    unsigned long count = 0;
    do
    {
        for (int i = left; i < right; i++)
        {
            if (array[i] > array[i+1])
            {
                array[i] ^= array[i+1];
                array[i+1] ^= array[i];
                array[i] ^= array[i+1];
            	count++;
            }
        } right--;
        for (int i = right; i > left; i--)
        {
            if (array[i] < array[i-1])
            {
                array[i] ^= array[i-1];
                array[i-1] ^= array[i];
                array[i] ^= array[i-1];
            	count++;
            }
        } left++;
    } while (left <= right);
   	printf("\nВычислительная сложность O(n^2): %ld\n", count);
}

/**
 * Бинарный поиск.
 */
int binarySearch(int array[], int M, int required)
{
    int L,R,m;
    unsigned long count = 0;
    L = 0;
    R = M-1;
    m = L+(R-L)/2;
    if (L <= R && array[m] != required)
    {
    	while (L <= R)
    	{
    	if (array[m] < required)
            L = m + 1;
        else
            R = m - 1;
        m = L+(R-L)/2;
        count++;
    	}
    }
    if (array[m] == required)
    {
   		printf("\nВычислительная сложность O(logn): %ld\n", count);
        return m;
    }
    else
    {
   		printf("\nВычислительная сложность O(logn): %ld\n", count);
        return -1;
    }
   	printf("\nВычислительная сложность O(logn): %ld\n", count);
    return m;
}

/**
 * Исполнение:
 * ======================================================
 */
int main(int argc, char const *argv[])
{
    int array[MAX_A];
    
    printf("Базовая пузырьковая:\n");
    randomArray(array,MAX_A,PAUSE);
    printArray(array,MAX_A);
    printf("\n");
    b_bubleSort(array,MAX_A);
    printArray(array,MAX_A);
    printf("\n\n");
    
    printf("Собственная пузырьковая:\n");
    randomArray(array,MAX_A,PAUSE);
    printArray(array,MAX_A);
    printf("\n");
    bubleSort(array,MAX_A);
    printArray(array,MAX_A);
    printf("\n\n");
    
    printf("Шейкерная сортировка:\n");
    randomArray(array,MAX_A,PAUSE);
    printArray(array,MAX_A);
    printf("\n");
    cocktailSort(array,MAX_A);
    printArray(array,MAX_A);
    printf("\n\n");
    
    printf("Бинарный поиск:\n");
    printf("Задайте число для поиска в массиве:\n");
    int X;
    scanf("%d", &X);
    printf("Индекс искомого числа: %d", binarySearch(array,MAX_A,X));
    printf("\n");
    
    return 0;
}