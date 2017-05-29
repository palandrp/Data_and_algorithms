/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 28.05.17.
 */

#include "c1hw5.h"

#define MaxA 20

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
    for (i = 0; i < N; i++)
        for (j = 0; j < N-1; j++)
            if (a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

/**
 * Пузырьковая сортировка, собственный вариант.
 */
void bubleSort(int array[], int M)
{
    for (int j = 1; j < M; j++)
        for (int i = 1; i < M; i++)
            if (array[i-1] > array[i])
            {
                array[i-1] ^= array[i];
                array[i] ^= array[i-1];
                array[i-1] ^= array[i];
            }
}

/**
 * Шейкерная сортировка.
 */
void cocktailSort(int array[], int M)
{
    int left = 0;
    int right = M - 1;
    do
    {
        for (int i = left; i < right; i++)
        {
            if (array[i] > array[i+1])
            {
                array[i] ^= array[i+1];
                array[i+1] ^= array[i];
                array[i] ^= array[i+1];
            }
        } right--;
        for (int i = right; i > left; i--)
        {
            if (array[i] < array[i-1])
            {
                array[i] ^= array[i-1];
                array[i-1] ^= array[i];
                array[i] ^= array[i-1];
            }
        } left++;
    } while (left <= right);
}

/**
 * Бинарный поиск.
 */
int binarySearch(int array[], int M, int required)
{
    while (M/2 > 1)
    {
        if (array[M/2] == required)
            return M/2;
        else if (array[M/2 + 1] == required)
            return M/2 + 1;
        else if (array[M/2 - 1] == required)
            return M/2 - 1;
        else if (array[M/2] > required)
            M /= 2;
        else
        {
            if (M % 2 == 0)
            {
                for (int i = 0; i < (M/2 - 2); i++){
                    array[i] = array[i + M/2 + 2];
                    printf("%d ", array[i]);}
                M /= 2;
                printf("\nM = %d", M);
            }
            else
            {
                for (int i = 0; i < (M/2); i++){
                    array[i] = array[i + M/2 + 2];
                    printf("%d ", array[i]);}
                M = M/2 + 1;
                printf("\nM = %d", M);
            }
        }
    }
    if (array[M/2] == required)
        return M/2;
    else if (array[M/2 - 1] == required)
        return M/2 - 1;
    else
        return -1;
}



/**
 * Исполнение:
 * ======================================================
 */
int main(int argc, char const *argv[])
{
    int array[MaxA];
    
    printf("Базовая пузырьковая:\n");
    randomArray(array,MaxA,20000);
    printArray(array,MaxA);
    printf("\n");
    b_bubleSort(array,MaxA);
    printArray(array,MaxA);
    printf("\n\n");
    
    printf("Собственная пузырьковая:\n");
    randomArray(array,MaxA,20000);
    printArray(array,MaxA);
    printf("\n");
    bubleSort(array,MaxA);
    printArray(array,MaxA);
    printf("\n\n");
    
    printf("Шейкерная сортировка:\n");
    randomArray(array,MaxA,20000);
    printArray(array,MaxA);
    printf("\n");
    cocktailSort(array,MaxA);
    printArray(array,MaxA);
    printf("\n\n");
    
    printf("Бинарный поиск с проверкой соседей:\n");
    printf("Задайте число для поиска в массиве:\n");
    int X;
    scanf("%d", &X);
    printf("Индекс искомого числа: %d", binarySearch(array,MaxA,X));
    printf("\n");
    
    return 0;
}