#include <stdio.h>
#include <time.h>

clock_t start, stop;
long time_stop();
void time_start();

int main() {
	// Засекаем время
	time_start();

	// Какие-то действия
	
	// Подсчитаем сумму первых 10000000 чисел
	int i;
	double s = 0;
	for (i = 0; i < 200000000; i++) 
		s += i;
	printf("Sum = %.3lf\n", s);
	printf("Time: %ld millisecond\n", time_stop());
	getchar();

	return 0;
}

// Запоминаем в глобальных переменных текущее время
long time_stop() {
	stop = clock();
	return stop - start;
}

// Рассчитываем время прошедшее с момента запуска time_start()
void time_start() {
 	start=clock(); 
}