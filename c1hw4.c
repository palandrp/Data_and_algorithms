/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 28.05.17.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MaxN 10

clock_t start, stop;
long time_stop() {
	stop = clock();
	return stop - start;
}

void time_start() {
	start = clock(); 
}

/**
 * Задание №1.j: Печатаем массив с помощью арифметики указателей.
 */
void printArrey(int arrey[], int M){
    for (int i = 0; i < M; ++i){
        printf("%d ", *(arrey+i));
    }
}

/**
 * Собственная функция рандома.
 */
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

/**
 * Собственная функция паузы.
 * Параметр в секундах.
 */
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

/**
 * a. Ввод массива с клавиатуры.
 */
void toArrey(int arrey[], int M) {
    for (int i = 0; i < M; i++) {
        scanf("%d", &arrey[i]);
    }
}

/**
 * b. Заполняем массив случайными числами.
 * Заполнение происходит автоматически.
 * Пауза в секунду нужна, чтобы сгенерировать
 * разные случайные числа.
 */
void randomArrey(int arrey[], int M) {
    printf("#");
    for (int i = 0; i < M; i++) {
        srand(time(NULL));
        arrey[i] = genRealRandom();
        s_sleep(50000);
        printf("=");
        fflush(stdout);
    }
    printf("\n");
}

/**
 * c. Подсчитываем сумму элементов массива.
 * Предполагается, что в массиве цифры (int)
 */
int findSumm(int arrey[], int M){
    int sum = 0;
    for (int i = 0; i < M; i++){
        sum += arrey[i];
    }
    return sum;
}

/**
 * d. Подсчитываем среднеарифметическую сумму элементов
 * массива.
 */
int averageSumm(int arrey[], int M){
    int sum = 0, i = 0, count = 0;
    for (; i < M; i++){
        sum += arrey[i];
        count++;
    }
    return sum/count;
}

/**
 * e. Находим номер самого отличающегося от средней суммы
 * элемента.
 */
int findFirst(int arrey[], int M){
    int diff, max = 0;
    int av_sum = averageSumm(arrey, M);
    for (int i = 0; i < M; i++){
        if (max < av_sum - arrey[i]){
            max = av_sum - arrey[i];
            diff = i;
        }
    }
    return diff;
}

/**
 * f. Находим максимальный элемент в массиве.
 */
int findMax(int arrey[], int M){
    int max = arrey[0];
    for (int i = 0; i < M; i++){
        if (max < arrey[i]) max = arrey[i];
    }
    return max;
}

/**
 * g. Читаем массив из файла.
 */
int printFile(char file_name[]){
    FILE *file;
    file = fopen(file_name,"r");
    
    if (file != NULL){
        int M;
        fscanf(file, "%d", &M);
        int arrey[M];
        for (int i = 0; i < M; ++i){
            fscanf(file, "%d", &arrey[i]);
        }
        printArrey(arrey, M);
        printf("\n");
        return 0;
    } else {
        printf("Файл не найден!\n");
        return 1;
    }
}

/**
 * h. Находим ДВА номера элементов, которые максимально отличаются
 * от среднего арифметического массива. (Что значит "найти ВСЕ" я не понимаю)
 * Модифицируем уже написанную функцию, так чтобы она находила первый элемент, а затем
 * искала второй элемент игнорируя попадания на найденный первые элемент.
 */
void findFirstPro(int arrey[], int M){
    int diff1, diff2, max = 0;
    int av_sum = averageSumm(arrey, M);
    for (int i = 0; i < M; i++){
        if (max < av_sum - arrey[i]){
            max = av_sum - arrey[i];
            diff1 = i;
        }
    }
    max = 0;
    for (int i = 0; i < M; i++){
        if (max < (av_sum - arrey[i]) && i != diff1){
            max = av_sum - arrey[i];
            diff2 = i;
        }
    }
    printf("[%d] и [%d]\n", diff1, diff2);
}

/**
 * Задание №3, Решето Эратосфена.
 */
void rErato(int N){
	int arrey[N];
	int p = 2, j;
	for (int i = 2; i < N; ++i)
	{
		arrey[i] = i;
	}
	while (p < N){
		j = 2;
		while (j < N){
			if ((j*p) < N) arrey[j*p] = 0;
			j++;
		}
		p++;
	}
	for (int i = 0; i < N; ++i)
	{
		if (arrey[i] != 0) 
		printf("%d ", arrey[i]);
	}
}


int main(int argc, char const *argv[]) {
    
    // printf("\nВведите цифры массива int, нажимая Enter.\n");
    // printf("Всего 10 цифр:\n");
    // int arrey0[MaxN];
    // toArrey(arrey0, MaxN);
    // printf("Выводим полученный массив:\n");
    // printArrey(arrey0, MaxN);
    
    // printf("\n\nВторое задание. Генерируется массив случайных чисел:\n");
    // int arrey1[MaxN];
    // randomArrey(arrey1, MaxN);
    // printf("Теперь этот массив выводится:\n");
    // printArrey(arrey1, MaxN);
    
    // printf("\n\nПодсчитываем сумму элементов массива:\n");
    // printf("%d\n", findSumm(arrey1, MaxN));
    
    // printf("\nНаходим среднеарифметическую сумму элементов\n");
    // printf("массива из второго задания:\n");
    // printf("%d\n", averageSumm(arrey1, MaxN));
    
    // printf("\nНаходим номер максимально отличного от неё элемента:\n");
    // printf("[%d]\n", findFirst(arrey1, MaxN));
    
    // printf("\nНаходим максимальный элемент массива:\n");
    // printf("%d\n", findMax(arrey1, MaxN));
    
    // printf("\nЧитаем из файла:\n");
    // char file_name[20];
    // printf("Введите имя файла в формате ""data.txt"":\n");
    // scanf("%20s", file_name);
    // printFile(file_name);
    
    // printf("\n\nНаходим два максимально отличающихся от среднеарифметической\n");
    // printf("суммы элементы:\n");
    // findFirstPro(arrey1, MaxN);

	printf("Печать простых по алгоритму Эратосфена\n");
	time_start();
    rErato(1000);
	printf("\nTime: %ld millisecond\n", time_stop());
    
    return 0;
}
