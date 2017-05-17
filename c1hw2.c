/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 14.05.17.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void doSolution1();
void doSolution2();
void doSolution3();
void doSolution4();
void doSolution5();
void doSolution6();
int doMenu();

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
	printf("\n\t1 - задача #1\n");
	printf("\t2 - задача #2\n");
	printf("\t3 - задача #3\n");
	printf("\t4 - задача #4\n");
	printf("\t5 - задача #5\n");
	printf("\t6 - задача #6\n");
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
			//Как нибудь обрабатываем исключение тут
			//или в main()
			return -1;
		}
	}
}


	/*	Task 1
	*	Ввести a и b и вывести квадраты 
	*	и кубы чисел от a до b. 
	*/
void doSolution1() {

	int a, b;

	printf("\n1. Ввести a и b и вывести квадраты и кубы чисел от a до b.\n\n");

	start:
	printf("Введите разные значения a и b.\n");
	printf("Введите a: ");
	scanf("%d", &a);

	printf("Введите b: ");
	scanf("%d", &b);

	if (a < b) {
		printf("Квадраты и кубы всех чисел между a и b:\n");
		printf("|Число:\t| Квадрат\t| Куб\t|\n");
		while (a != b + 1) {
			int num2 = a;
			int num3 = a;
			num2 = pow(num2,2);
			num3 = pow(num3,3);
			printf("| %d\t| %d\t\t| %d\t|\n", a, num2, num3);
			a++;
		}
	} else if (a > b) {
		printf("Квадраты и кубы всех чисел между a и b:\n");
		printf("|Число:\t| Квадрат\t| Куб\t|\n");
			while (a + 1 != b) {
			int num2 = b;
			int num3 = b;
			num2 = pow(num2,2);
			num3 = pow(num3,3);
			printf("| %d\t| %d\t\t| %d\t|\n", b, num2, num3);
			b++;
		}
	} else goto start;
}

	/*	Task 2
	*	Даны целые положительные числа N и K. Используя только
	* 	операции сложения и вычитания, найти частное от деления 
	* 	нацело N на K, а также остаток от этого деления.
	*/
void doSolution2() {

	int n, k;
	int ostatok(int a, int b); 		// Реализация в конце файла
	int chastnoe(int a, int b);		// <-----------------------

	printf("\n\t2. Даны целые положительные числа N и K. Используя только\n");
	printf("операции сложения и вычитания, найти частное от деления нацело\n");
	printf("N на K, а также остаток от этого деления.\n\n");

	start:
	printf("Введите разные положительные значения N и K.\n");
	printf("Введите N: ");
	scanf("%d", &n);

	printf("Введите K: ");
	scanf("%d", &k);

	if (n > k && n > 0 && k > 0) {
		printf("Деление N на K:\n");
		int ost = ostatok(n, k);
		int chast = chastnoe(n, k);
		printf("Частное: %d\nОстаток: %d\n", chast, ost);
	} else if (n < k && n > 0 && k > 0) {
		printf("\n\tДеление нацело невозможно, N меньше K,\n");
		printf("результат - десятичная дробь.\n");
	} 
	else goto start;
}

	/* 	Task 3
	*	Дано целое число N (> 0). С помощью операций деления нацело 
	*	и взятия остатка от деления определить, имеются ли в записи 
	*	числа N нечетные цифры. Если имеются, то вывести True, если 
	*	нет — вывести False. 
	*/
void doSolution3() {

	int n;
	bool answer = false;
	int ostatok(int a, int b);

	printf("\n\t3. Дано целое число N (> 0). С помощью операций деления нацело\n");
	printf("и взятия остатка от деления определить, имеются ли в записи\n");
	printf("числа N нечетные цифры. Если имеются, то вывести True, если\n");
	printf("нет — вывести False.\n\n");

	start:
	printf("Введите положительное значение N.\n");
	printf("Введите N: ");
	scanf("%d", &n);

	if (n >= 1) {
		while (n >= 1) {
			int a = ostatok(n, 2);
			if (a != 0) {answer = true;}
			n = n / 10;
		}
			printf(answer ? "true" : "false");
	}
	else goto start;
}

	/* 	Task 4 
	*	С клавиатуры вводятся числа, пока не будет введен 0. 
	*	Подсчитать среднее арифметическое всех положительных 
	*	четных чисел, оканчивающихся на 8.
	*/
void doSolution4() {

	float sum = 0;
	int count = -1;
	int number;

	printf("\n\t4. С клавиатуры вводятся числа, пока не будет введен 0.\n");
	printf("Подсчитать среднее арифметическое всех положительных\n");
	printf("четных чисел, оканчивающихся на 8.\n\n");

	printf("Начинайте вводить числа:\n");
	do {
		scanf("%d", &number);
		sum += number;
		count++;
	} while (number != 0);

	float average_rating = sum / count;

	printf("Среднее арифметическое равно %f\n", average_rating);
}

	/* 	Task 5 
	*	Написать функцию нахождения максимального из трех чисел.
	*/
void doSolution5() {

	void showMax(int range);	// Реализация в конце файла

	printf("\n\t5. Написать функцию нахождения максимального из трех чисел.\n\n");

	showMax(3);		// Сейчас из 3-х чисел, но можно и больше

}

	/* 	Task 6 
	*	Написать функцию, генерирующую случайное число от 1 до 100.
	*	а) с использованием стандартной функции rand()
	*	б) без использования стандартной функции rand()
	*/
void doSolution6() {

	int random;

	printf("\n\t6. Написать функцию, генерирующую случайное число от 1 до 100.\n");
	printf("а) с использованием стандартной функции rand()\n");
	printf("б) без использования стандартной функции rand()\n\n");

	srand(time(NULL));
	random = rand() % 100 + 1;

	printf("Сгенерировали число методом а: %d\n", random);

	random = (2 * 1 + 3) % 100;

	printf("Сгенерировали число методом б: %d\n", random);

}

	/*
	*	Реализация алгоритмов деления и взятия остатка
	*/
int ostatok(int a, int b) {
		
	while (a >= b) {
		if (a < 0) {
			a += b;
			break;
		}
		a -= b;
	}
	return a;
}

int chastnoe(int a, int b) {

	int count = 0;
		
	while (a >= b) {
		if (a < 0) {
			a += b;
			break;
		}
		a -= b;
		count++;
	}
	return count;
}

	/*
	*	Реализация алгоритма нахождения максимального числа
	*/
void showMax(int range) {

	float max, input;

	printf("Введите числа:\n");
	scanf("%f", &input);
		
	max = input;
	for (int i = 0; i < range - 1; ++i)
	{
		scanf("%f", &input);
		if (max < input) max = input;

	}

	printf("Максимальное: %f\n", max);
}














