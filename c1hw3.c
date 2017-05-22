/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 22.05.17.
 */
#include <stdio.h>
#include <time.h>

#define D int

struct SFraction {
	int whole,
		numerator, 
		denominator;
};

typedef struct SFraction SFraction;

clock_t start, stop;

long toPow(int a, int b);
bool checkSimple(long a);
int toDecimal(long a);
bool checkGoodNum(unsigned a);
SFraction sumFrac(SFraction *frac1, SFraction *frac2);
SFraction subFrac(SFraction *frac1, SFraction *frac2);
SFraction divFrac(SFraction *frac1, SFraction *frac2);
SFraction mulFrac(SFraction *frac1, SFraction *frac2);
SFraction toSimplifyF(SFraction *frac);
SFraction getWhole(SFraction *frac);
void toSwap(D *a, D *b, D *c);
int doMenu();
void doSolution1();
void doSolution2();
void doSolution3();
void doSolution4();
void doSolution5();
void doSolution6();
void pause();
long time_stop();
void time_start();

int main(int argc, char const *argv[])
{
	int isOk = doMenu();

	printf("\nExit status: %d\n", isOk);
	return isOk;
}

	/* Menu */
int doMenu() {

	int number_of_task;

	printf("\nЗадайте значение задачи:\n");
	printf("\n\t1 - задача #1 (возведение в степень)\n");
	printf("\t2 - задача #2 (является ли простым)\n");
	printf("\t3 - задача #3 (из 2-чной в 10-чную)\n");
	printf("\t4 - задача #4 (подсчет ""хороших"" чисел)\n");
	printf("\t5 - задача #5 (простые дроби)\n");
	printf("\t6 - задача #6 (обмен 3-х переменных)\n");
	printf("\t0 - exit\n");
	printf("\nВыбор: ");

	scanf("%d", &number_of_task);

	switch (number_of_task) {
		case 1: 
			doSolution1();
			return 0;
		case 2: 
			doSolution2();
			return 0;
		case 3: 
			doSolution3();
			return 0;
		case 4: 
			doSolution4();
			return 0;
		case 5: 
			doSolution5();
			return 0;
		case 6: 
			doSolution6();
			return 0;
		case 0: 
			printf("Goodbye!\n");
			return 0;
		default: {
			return -1;
		}
	}
}

void doSolution1() {
	
	int a, b;

	printf("Введите число для возведения в степень: ");
	scanf("%d", &a);
	printf("Введите показатель степени: ");
	scanf("%d", &b);
	printf("Результат: ");
	printf("%ld\n", toPow(a, b));

	pause();
	doMenu();
}

void doSolution2() {
	
	int a;

	printf("Введите число для определения простоты: ");
	scanf("%d", &a);
	if (a == 1 || a == 0) 
		printf("1 и 0 не являются ни простыми ни составными числами.\n\n");
	else if (checkSimple(a)) 
		printf("Число простое.\n\n");
	else
		printf("Число составное.\n\n");

	printf("Если хотите вывести все простые числа до заданного, нажмите (1): \n");
	char doWeGo;
	scanf("%s", &doWeGo);
	if (doWeGo == '1') {
		printf("Задайте максимальное число для поиска: ");
		scanf("%d", &a);
		for (int i = 2; i < a + 1; ++i)
		{
			if (checkSimple(i)) 
				printf("\n%d - простое число", i);
		}
		
		printf("\n\n");
		pause();
		doMenu();
	} else 
		doMenu();
}

void doSolution3() {

	long a;

	printf("Введите число в двоичном виде: ");
	scanf("%ld", &a);
	printf("Ваше число в десятичном виде: ");
	printf("%d\n", toDecimal(a)); 

	pause();
	doMenu();
}

void doSolution4() {
	
	unsigned i = 1;
	int count = 0;

	printf("Подсчитать все ""хорошие"" числа от 1 до 1 000 000 (1):\n");
	time_start();
	while (i <= 1000000) {
		if (checkGoodNum(i)) {
			count++;
		}
		i++;
	}
	printf("Кол-во чисел: %d\n", count);
	printf("Time: %ld millisecond\n", time_stop());

	pause();
	doMenu();

}

void doSolution5() {

	SFraction frac1;
	SFraction frac2;

	frac1.numerator = 3;		// 3/2
	frac1.denominator = 2;		
	printf("Дробь 1: %d/%d\n", frac1.numerator, frac1.denominator);
	frac2.numerator = 5;		// 5/4
	frac2.denominator = 4;
	printf("Дробь 2: %d/%d\n", frac2.numerator, frac2.denominator);
	printf("Сумма: ");
	frac1 = sumFrac(&frac1, &frac2);
	toSimplifyF(&frac1);
	printf("%d/%d\n\n", frac1.numerator, frac1.denominator);

	frac1.numerator = 55;		// 55/3
	frac1.denominator = 3;		
	printf("Дробь 1: %d/%d\n", frac1.numerator, frac1.denominator);
	frac2.numerator = 45;		// 45/4
	frac2.denominator = 4;
	printf("Дробь 2: %d/%d\n", frac2.numerator, frac2.denominator);
	printf("Разность: ");
	frac1 = subFrac(&frac1, &frac2);
	toSimplifyF(&frac1);
	printf("%d/%d\n\n", frac1.numerator, frac1.denominator);


	frac1.numerator = 55;		// 55/3
	frac1.denominator = 3;		
	printf("Дробь 1: %d/%d\n", frac1.numerator, frac1.denominator);
	frac2.numerator = 45;		// 45/4
	frac2.denominator = 4;
	printf("Дробь 2: %d/%d\n", frac2.numerator, frac2.denominator);
	printf("Деление: ");
	frac1 = divFrac(&frac1, &frac2);
	toSimplifyF(&frac1);
	printf("%d/%d\n\n", frac1.numerator, frac1.denominator);


	frac1.numerator = 55;		// 55/3
	frac1.denominator = 3;		
	printf("Дробь 1: %d/%d\n", frac1.numerator, frac1.denominator);
	frac2.numerator = 45;		// 45/4
	frac2.denominator = 4;
	printf("Дробь 2: %d/%d\n", frac2.numerator, frac2.denominator);
	printf("Умножение: ");
	frac1 = mulFrac(&frac1, &frac2);
	toSimplifyF(&frac1);
	printf("%d/%d\n\n", frac1.numerator, frac1.denominator);

	printf("Дробь: %d/%d\n", frac1.numerator, frac1.denominator);
	printf("Упрощение: ");
	toSimplifyF(&frac1);
	getWhole(&frac1);
	printf("%d %d/%d\n\n",frac1.whole, frac1.numerator, frac1.denominator);

	pause();
	doMenu();
}

void doSolution6() {

	int a, b, c;

	printf("Введите три переменные: \n");
	printf("введите а: \n");
	scanf("%d", &a);
	printf("введите b: \n");
	scanf("%d", &b);
	printf("введите c: \n");
	scanf("%d", &c);
	printf("Ваши переменные а:%d, b:%d, c:%d\n", a, b, c);

	toSwap(&a, &b, &c);

	printf("Переменные после обмена а:%d, b:%d, c:%d\n", a, b, c);

	pause();
	doMenu();
}

long toPow(int a, int b) {

	long n = 1;

	while (b != 0) {
		if (b % 2 == 0){
			a = a * a; 
			b /= 2;
		} else {
			b--;
			n = n * a;
		}
	}

	return n;
}

bool checkSimple(long a) {

	long mod;
	long den = 2;
	while (den < (a / 2 + 1)) {
		mod = a % den;
		if (mod == 0) return false;
		den++;
	}

	return true;
}

int toDecimal(long a) {

	int dec = 0;
	int count = 0;
	while (a > 0) {
		if (a % 2 == 1)
			dec = dec + toPow(2, count);
		a /= 10;
		count++;
	}

	return dec;
}

bool checkGoodNum(unsigned a) {

	unsigned aa = a;
	unsigned num = 0;
	while (aa > 0) {
		num += aa % 10;
		aa /= 10;
	}

	if (a % num == 0) return true;

	return false;
}

SFraction sumFrac(SFraction *frac1, SFraction *frac2) {

	int b = frac1->denominator;
	int d = frac2->denominator;

	frac1->numerator *= d;
	frac1->denominator *= d;
	frac2->numerator *= b;
	frac2->denominator *= b;

	frac1->numerator += frac2->numerator;

	return *frac1;
}

SFraction subFrac(SFraction *frac1, SFraction *frac2) {

	int b = frac1->denominator;
	int d = frac2->denominator;

	frac1->numerator *= d;
	frac1->denominator *= d;
	frac2->numerator *= b;
	frac2->denominator *= b;

	frac1->numerator -= frac2->numerator;

	return *frac1;
}

SFraction mulFrac(SFraction *frac1, SFraction *frac2) {

	frac1->numerator *= frac2->numerator;
	frac1->denominator *= frac2->denominator;

	return *frac1;
}

SFraction divFrac(SFraction *frac1, SFraction *frac2) {

	frac1->numerator *= frac2->denominator;
	frac1->denominator *= frac2->numerator;

	return *frac1;
}

SFraction toSimplifyF(SFraction *frac) {

	int a = frac->numerator;
	int b = frac->denominator;

	while(a != b)
	if (a > b) {
		a -= b;
	} else {
		b -= a;
	}

	if (a != 1) {
		frac->numerator /= a;
		frac->denominator /= a;
	}

	return *frac;
}

SFraction getWhole(SFraction *frac) {
	
	int a = frac->numerator;
	int b = frac->denominator;

	if (a > b) {
		frac->whole = a / b;
		a = a % b;
		frac->numerator = a;
	}
	return *frac;
}

void toSwap(D *a, D *b, D *c) {
	int buf1 = *a;
	int buf2 = *b;

	*a = *c; 
	*b = buf1; 
	*c = buf2;
}

void pause() {
	char null;
	scanf("%s", &null);
}

long time_stop() {
	stop = clock();
	return stop - start;
}

void time_start() {
	start = clock(); 
}