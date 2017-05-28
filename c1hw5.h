/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 28.05.17.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int array[], int M)
{
    for (int i = 0; i < M; ++i)
    {
        printf("%d ", array[i]);
    }
}
int genRealRandom()
{
    int m = 101;
    int b = 1;
    int a = 2;
    clock_t ttime;
    ttime = clock();
    int ptime = 0;
    for (int i = 0; i < 2; i++)
    {
        ptime = ptime * 10 + ttime % 10;
        ttime /= 10;
    }
    return (a * ptime + b) % m;
}
void s_sleep(int _time)
{
    clock_t ttime, ntime;
    ttime = clock();
    while (ntime < _time)
    {
        ntime = clock();
        ntime -= ttime;
    }
}
void randomArray(int array[], int M, int S)
{
    printf("#");
    for (int i = 0; i < M; i++)
    {
        srand(time(NULL));
        array[i] = genRealRandom();
        s_sleep(S);
        printf("=");
        fflush(stdout);
    }
    printf("\n");
}
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
