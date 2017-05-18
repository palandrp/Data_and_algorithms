#include <stdio.h>
#include <time.h>
	
int main(int argc, char const *argv[])
{

	int random;
	int m = 101;
	int b = 1;
	int a = 2;

	unsigned long int ttime;
	ttime = time (NULL);

	/* ============================================
	*  Переворачиваем пепеменную ttime задом наперед
	*  берем остатоки от деления, формируем новое число
	*  с меняющейся верхней частью (а не нижней, как у ttime)
	*/
	int ptime;
	int count = 0;
	int array[50];
	unsigned int Xn = 0;

	while (ttime > 0) {
		ptime = ttime % 10;
		ttime = ttime / 10;
		array[count] = ptime;
		// printf("%d", array[count]);  // отладочное сообщение
		count++;
	}

	Xn = array[0];
	for (int i = 1; i < 2; i++) {	// берем только две первые цифры,
		Xn = Xn *10 + array[i];		// которые меняются быстрее всего
	}
	// printf("\n%d\n", Xn);  // отладочное сообщение
	//==============================================

	random = (a * Xn + b) % m;

	printf("%d\n", random);

	return 0;
}