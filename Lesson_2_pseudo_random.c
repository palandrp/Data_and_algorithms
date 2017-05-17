#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int Xn,a,b,m;
	
	// Произвольно выбираем a,b,m и x
	m = 100; // Вершина последовательности
	b = 3;
	a = 2;
	Xn = 1;
	int i, N = 100;
	
	// Сгенерируем N случайных чисел
	for(i = 0; i < N; i++) {
		Xn = (a * Xn + b) % m;
		printf("|%d:%d|", i, Xn);
	}
	
	return 0;
}