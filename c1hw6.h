/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 01.06.17.
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
        printf("= ");
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
int doMenu() {

    int number_of_task;

    printf("\nЗадайте значение задачи:\n");
    printf("\n\t1 - задача #1 (возведение в степень)\n");
    printf("\t2 - задача #2 (является ли простым)\n");
    printf("\t3 - задача #3 (из 2-чной в 10-чную)\n");
    printf("\t4 - задача #4 (подсчет ""хороших"" чисел)\n");
    printf("\t5 - задача #5 (простые дроби)\n");
    printf("\t6 - задача #6 (обмен 3-х переменных)\n");
    printf("\t0 - exit\n");
    printf("\nВыбор: ");

    scanf("%d", &number_of_task);

    switch (number_of_task) {
        case 1: 
            doSolution1();
            return 0;
        case 2: 
            doSolution2();
            return 0;
        case 3: 
            doSolution3();
            return 0;
        case 4: 
            doSolution4();
            return 0;
        case 5: 
            doSolution5();
            return 0;
        case 6: 
            doSolution6();
            return 0;
        case 0: 
            printf("Goodbye!\n");
            return 0;
        default: {
            return -1;
        }
    }
}