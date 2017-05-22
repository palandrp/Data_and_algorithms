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

	int ptime = 0;
	for (int i = 0; i < 2; i++) {
		ptime = ptime * 10 + ttime % 10;
		ttime /= 10;
	}
	// printf("%ld : %d\n", ttime, ptime);  // отладочное сообщение

	random = (a * ptime + b) % m;

	printf("%d\n", random);

	return 0;
}