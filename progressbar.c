#include <stdio.h>
#include <time.h>

void sleep(int _time) {
	unsigned long ntime = 0;
	unsigned long ttime = time(NULL);
	while (ntime < _time) {
		ntime = time(NULL);
		ntime -= ttime;
	}
}

int main(int argc, char const *argv[]){
	printf("#");
	for (int i = 0; i < 100; ++i){
		printf("=");
		fflush(stdout);
		sleep(1);
	}
	printf("\n");

	return 0;
}