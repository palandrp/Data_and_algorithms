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
		putchar('\\');
		srand(time(NULL));
		array[i] = genRealRandom();
		sleep(1);
	}
	printf("\n");
}


int main(int argc, char const *argv[]) {

	char array0[MaxN];
	toCharArray(array0);
	printf("%s\n", array0);

	int array1[MaxN];
	ramdomArray(array1, 10);
	for (int i; i < 10; i++) {
		printf("%i\n", array1[i]);
	}

	return 0;
}