/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 22.05.17.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MaxN 100
#define D char

// ввод массива с клавиатуры

void toCharArray(char array[]) {
	char end = -1;
	int i = 0;
	while (end != '0') {
		scanf("%s", &array[i]);
		end = array[i];
		i++;
	}
}

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

void sleep(int _time) {
	unsigned long ntime = 0;
	unsigned long ttime = time(NULL);
	while (ntime < _time) {
		ntime = time(NULL);
		ntime -= ttime;
	}
}

void ramdomArray(int array[], int M) {
	for (int i = 0; i < M; i++) {
		srand(time(NULL));
		array[i] = genRealRandom();
		sleep(1);
	}
	array[M+1] = 0;
	printf("\n");
}

int arrayLength(D array[]) {
	int count = 0, i = 0;
	while (array[i] != '0') {
		count++;
		i++;
	}
	return count;
}

int averageSumm(int array[]) {
	int count = 0, i = 0, sum;
	while (array[i] != 0){
		sum += array[i];
		i++;
	}
	i = 0;
	while (array[i] != 0) {
		count++;
		i++;
	}
	return sum/count;
}

int findFirst(int array[]){
	int count = 0, i = 0, sum, diff, max;
	while (array[i] != 0){
		sum += array[i];
		i++;
	}
	i = 0;
	while (array[i] != 0) {
		count++;
		i++;
	}
	i = 0;
	max = sum - array[0];
	while(array[i] != 0){
		if (max < sum - array[i]){
			max = sum - array[i];
			diff = array[i];
		}
	}
	return diff;
}

int findMax(int array[]){
	int i = 0, max = array[0];
	if (max < array[i]) max = array[i];
	return max;
}


int main(int argc, char const *argv[]) {

	char array0[MaxN];
	toCharArray(array0);
	printf("%s\n", array0);

	int array1[MaxN];
	int count = 10;
	ramdomArray(array1, count);
	for (int i; i < count; i++) {
		printf("%i\n", array1[i]);
	}

	D array2[] = {'d','f','a','e','0'};
	arrayLength(array2);

	printf("\n\n");
	printf("%d\n", averageSumm(array1));
	printf("%d\n", findMax(array1));
	printf("%d\n", findFirst(array1));

	return 0;
}