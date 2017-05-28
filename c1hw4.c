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
void printArray(int array[], int M){
    for (int i = 0; i < M; ++i){
        printf("%d ", *(array+i));
    }
}

/**
 * Собственная функция рандома.
 */
int genRealRandom() {
    int m = 101;
    int b = 1;
    int a = 2;
    
    unsigned long ttime;
    ttime = time(NULL);
    
    int ptime = 0;
    for (int i = 0; i < 2; i++) {
        ptime = ptime * 10 + ttime % 10;
        ttime /= 10;
    }
    
    return (a * ptime + b) % m;
}

/**
 * Собственная функция паузы.
 * Параметр в секундах.
 */
void s_sleep(int _time) {
    unsigned long ntime = 0;
    unsigned long ttime = time(NULL);
    while (ntime < _time) {
        ntime = time(NULL);
        ntime -= ttime;
    }
}

/**
 * a. Ввод массива с клавиатуры.
 */
void toArray(int array[], int M) {
    for (int i = 0; i < M; i++) {
        scanf("%d", &array[i]);
    }
}

/**
 * b. Заполняем массив случайными числами.
 * Заполнение происходит автоматически.
 * Пауза в секунду нужна, чтобы сгенерировать
 * разные случайные числа.
 */
void ramdomArray(int array[], int M) {
    printf("#");
    for (int i = 0; i < M; i++) {
        srand(time(NULL));
        array[i] = genRealRandom();
        s_sleep(1);
        printf("=");
        fflush(stdout);
    }
    array[M+1] = 0;
    printf("\n");
}

/**
 * c. Подсчитываем сумму элементов массива.
 * Предполагается, что в массиве цифры (int)
 */
int findSumm(int array[], int M){
    int sum = 0;
    for (int i = 0; i < M; i++){
        sum += array[i];
    }
    return sum;
}

/**
 * d. Подсчитываем среднеарифметическую сумму элементов
 * массива.
 */
int averageSumm(int array[], int M){
    int sum = 0, i = 0, count = 0;
    for (; i < M; i++){
        sum += array[i];
        count++;
    }
    return sum/count;
}

/**
 * e. Находим номер самого отличающегося от средней суммы
 * элемента.
 */
int findFirst(int array[], int M){
    int diff, max = 0;
    int av_sum = averageSumm(array, M);
    for (int i = 0; i < M; i++){
        if (max < av_sum - array[i]){
            max = av_sum - array[i];
            diff = i;
        }
    }
    return diff;
}

/**
 * f. Находим максимальный элемент в массиве.
 */
int findMax(int array[], int M){
    int max = array[0];
    for (int i = 0; i < M; i++){
        if (max < array[i]) max = array[i];
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
        int array[M];
        for (int i = 0; i < M; ++i){
            fscanf(file, "%d", &array[i]);
        }
        printArray(array, M);
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
void findFirstPro(int array[], int M){
    int diff1, diff2, max = 0;
    int av_sum = averageSumm(array, M);
    for (int i = 0; i < M; i++){
        if (max < av_sum - array[i]){
            max = av_sum - array[i];
            diff1 = i;
        }
    }
    max = 0;
    for (int i = 0; i < M; i++){
        if (max < (av_sum - array[i]) && i != diff1){
            max = av_sum - array[i];
            diff2 = i;
        }
    }
    printf("[%d] и [%d]\n", diff1, diff2);
}

/**
 * Задание №3, Решето Эратосфена.
 */
void rErato(int N){
	int array[N];
	int p = 2, j;
	for (int i = 2; i < N; ++i)
	{
		array[i] = i;
	}
	while (p < N){
		j = 2;
		while (j < N){
			if ((j*p) < N) array[j*p] = 0;
			j++;
		}
		p++;
	}
	for (int i = 0; i < N; ++i)
	{
		if (array[i] != 0) 
		printf("%d ", array[i]);
	}
}


int main(int argc, char const *argv[]) {
    
    // printf("\nВведите цифры массива int, нажимая Enter.\n");
    // printf("Всего 10 цифр:\n");
    // int array0[MaxN];
    // toArray(array0, MaxN);
    // printf("Выводим полученный массив:\n");
    // printArray(array0, MaxN);
    
    // printf("\n\nВторое задание. Генерируется массив случайных чисел:\n");
    // int array1[MaxN];
    // ramdomArray(array1, MaxN);
    // printf("Теперь этот массив выводится:\n");
    // printArray(array1, MaxN);
    
    // printf("\n\nПодсчитываем сумму элементов массива:\n");
    // printf("%d\n", findSumm(array1, MaxN));
    
    // printf("\nНаходим среднеарифметическую сумму элементов\n");
    // printf("массива из второго задания:\n");
    // printf("%d\n", averageSumm(array1, MaxN));
    
    // printf("\nНаходим номер максимально отличного от неё элемента:\n");
    // printf("[%d]\n", findFirst(array1, MaxN));
    
    // printf("\nНаходим максимальный элемент массива:\n");
    // printf("%d\n", findMax(array1, MaxN));
    
    // printf("\nЧитаем из файла:\n");
    // char file_name[20];
    // printf("Введите имя файла в формате ""data.txt"":\n");
    // scanf("%20s", file_name);
    // printFile(file_name);
    
    // printf("\n\nНаходим два максимально отличающихся от среднеарифметической\n");
    // printf("суммы элементы:\n");
    // findFirstPro(array1, MaxN);

	printf("Печать простых по алгоритму Эратосфена\n");
	time_start();
    rErato(1000);
	printf("\nTime: %ld millisecond\n", time_stop());
    
    return 0;
}
