/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 01.06.17.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long toPow(int a, int b) {

    long n = 1;

    while (b != 0) {
        if (b % 2 == 0){
            a = a * a; 
            b /= 2;
        } else {
            b--;
            n = n * a;
        }
    }

    return n;
}
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
void doSolution1();
void doSolution2();
void doSolution3();
void doSolution4();
void doSolution5();
void doSolution6();
int doMenu() {

    int number_of_task;

    printf("\nЗадайте значение задачи:\n");
    printf("\n\t1 - задача #1 (поиск гласных)\n");
    printf("\t2 - задача #2 (перестановка строк)\n");
    printf("\t3 - задача #3 (сжатие строки)\n");
    printf("\t4 - задача #4 (циклический сдвиг строки)\n");
    printf("\t5 - задача #5 (формирование массива)\n");
    printf("\t6 - задача #6 (правильность расстановки скобок)\n");
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