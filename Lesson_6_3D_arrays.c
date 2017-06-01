#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

#ifndef MINDIM_M
#define MINDIM_M 1000
#endif

#ifndef MINDIM_N
#define MINDIM_N 1000
#endif

#ifndef MINDIM_K
#define MINDIM_K 1000
#endif

#ifndef MAXDIM_M
#define MAXDIM_M 3300
#endif

#ifndef MAXDIM_N
#define MAXDIM_N 3300
#endif

#ifndef MAXDIM_K
#define MAXDIM_K 3300
#endif

#ifndef INC_M
#define INC_M 100
#endif

#ifndef INC_N
#define INC_N 100
#endif

#ifndef INC_K
#define INC_K 100
#endif

#ifndef MIN_T
#define MIN_T 1
#endif

struct timeval tv1,tv2,dtv;
struct timezone tz;

// Запоминаем в глобальных переменных текущее время
void time_start() 
{ 
	gettimeofday(&tv1, &tz); 
}
// Рассчитываем время прошедшее с момента запуска time_start()
long time_stop()
{ 	
	gettimeofday(&tv2, &tz);
	dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;
	dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;
	if(dtv.tv_usec<0) { dtv.tv_sec--; dtv.tv_usec+=1000000; }
	return dtv.tv_sec*1000+dtv.tv_usec/1000;
}

double buffer1[MAXDIM_M*MAXDIM_N];
double buffer2[MAXDIM_M*MAXDIM_N];


void
initMatrix(size_t m, size_t n, double *A, size_t incRowA, size_t incColA) {
	for (size_t j = 0; j < n; ++j) {
		for (size_t i = 0; i < m; ++i) {
			A[i*incRowA+j*incColA] = j*n+i+1;
		}
	}
}

void
printMatrix(size_t m, size_t n, const double *A,
			size_t incRowA, size_t incColA) {
	for (size_t i = 0; i < m; ++i) {
		printf(" ");
		for (size_t j = 0; j < n; ++j) {
		printf("%4.1lf ", A[i*incRowA+j*incColA]);
		}
	printf("\n");
	}
printf("\n");
}

int main() 
{
	printf(" M N t1 t2 t2/t1\n");
	printf(" col-maj row-maj\n");
	printf("=====================================\n");

	for (size_t m = MINDIM_M, n = MINDIM_N; m < MAXDIM_M && n < MAXDIM_N;
			m += INC_M, n += INC_N) {
		size_t runs = 0;
		double t1 = 0;
		do {
			time_start();
			initMatrix(m, n, buffer1, 1, m);
			t1 += time_stop();
			++runs;
		} while (t1 < MIN_T);
		t1 /= runs;

		runs = 0;
		double t2 = 0;
		do {
			time_start();
			initMatrix(m, n, buffer2, n, 1);
			t2 += time_stop();
			++runs;
		} while (t2 < MIN_T);
		t2 /= runs;

		printf("%4ld %4ld %7.2lf %7.2lf %7.2lf\n",
				m, n, t1, t2, t2/t1);
	}
}
