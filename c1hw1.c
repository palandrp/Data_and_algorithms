#include <stdio.h>
#include <math.h>

// @author Павел Петриковский
// @version 14.05.2017

int main(int argc, char const *argv[])
{	
	{
		int task;
		start:
		printf("Выберите задачу: 1, 2, 3, 4, 5, 6, 7, (8 - для выхода)\n");
		scanf("%d", &task);
		switch (task){
			case 1: goto task1;
			case 2: goto task2;
			case 3: goto task3;
			case 4: goto task4;
			case 5: goto task5;
			case 6: goto task6;
			case 7: goto task7;
			case 8: goto exit;
			default: goto start;
		}
	}
	/* task 1 */
	// Ввести вес и рост человека. Рассчитать и 
	// вывести индекс массы тела по формуле I=m/(h*h);
	// где m-масса тела в килограммах, h - рост в метрах.
	task1: {
		float m, h, i;
		printf("\n\n\nЗадача 1:\n");
		printf("weight: \n");
		scanf("%f", &m);
		ERR:
		printf("height: \n");
		scanf("%f", &h);
		if (h == 0){
	        fflush(stdin);
	        goto ERR;
	    }
		i = m / (h * h);
		printf("Index: %f\n\n\n", i);
	}
	goto start;

	/* task 2 */
	// Найти максимальное из четырех чисел. Массивы не 
	// использовать.
	task2: {
		float m, h, i, n;
		printf("\n\n\nЗадача 2:\n");
		printf("Укажите четыре числа: \n");
		scanf("%f", &m);
		scanf("%f", &h);
		scanf("%f", &i);
		scanf("%f", &n);
		if (m > h){
			if ( m > i){
				if (m > n) printf("Max = %f\n\n\n", m);
				else printf("Max = %f\n\n\n", n);
			} else { 
				if (i > n) printf("Max = %f\n\n\n", i);
				else printf("Max = %f\n\n\n", n);
			}
		} else {
			if (h > i){
				if (h > n) printf("Max = %f\n\n\n", h);
				else printf("Max = %f\n\n\n", n);
			} else {
				if (i > n) printf("Max = %f\n\n\n", i);
				else printf("Max = %f\n\n\n", n);
			}
		} 
	}
	goto start;

	/* task 3 */
	// Написать программу обмена значениями двух 
	// целочисленных переменных:
	// 1) с использованием третьей переменной;
	// 2) *без использования третьей переменной
	task3: {
		printf("\n\n\nЗадача 3:\n");
		int a, b;
		printf("Введите a и b соответственно:\n");
		scanf("%d", &a);
		scanf("%d", &b);
		printf("Изначально а = %d, b = %d \n", a, b);	
		/* var 1 */
		int buffer;
		buffer = b;
		b = a;
		a = buffer;
		printf("Первый обмен по Var 1: а = %d, b = %d \n", a, b);	
		/* var 2 */
		a = a + b;
		b = a - b;
		a = a - b;
		printf("Второй обмен по Var 2: а = %d, b = %d \n\n\n", a, b);
	}
	goto start;

	/* task 4 */
	//Написать программу нахождения корней заданного
	//квадратного уравнения.
	//ax^2+bx+c=0
	//x^2+px+q=0, p=b/a, q=c/a
	task4: {
		float m, h, i;
		printf("\n\n\nЗадача 4:\n");
		printf("Введите коэффициенты a, b, c:");
		printf("\na = ");
		scanf("%f", &m);
		printf("\nb = ");
		scanf("%f", &h);
		printf("\nc = ");
		scanf("%f", &i);

		if (m == 0) {
			if (h == 0) {
				printf("\nОтвет: %f\n\n\n", i);
			} else {
				float x = -i/h;
				printf("\nОтвет: %f\n\n\n", x);
			}
		}
		if (h == 0) {
			float x = sqrt(-i/m);
			printf("\nОтвет: %f\n\n\n", x);
		} else {
			float D = pow(h,2) - (4 * m * i);
			float x1;
			float x2;
			if (D >= 0) {
				x1 = (-h + sqrt(D))/(2 * m);
				x2 = (-h - sqrt(D))/(2 * m);
				printf("\nОтвет: х1 = %f, х2 = %f\n\n\n", x1, x2);
			} else {
				D = D * -1;
				float komplex = sqrt(D) / (2 * m);
				x1 = (-h / 2 * m);
				printf("\nОтвет: х1 = %f+%fi, x2 = %f-%fi\n\n\n", x1, komplex, x1, komplex);
			}
		}
	}
	goto start;

	/* task 5 */
	//С клавиатуры вводится номер месяца. Требуется определить,
	//к какому времени года он относится.
	task5: {
		int month;
		abc1:
		printf("\n\n\nВведите номер месяца:\n");
		scanf("%d", &month);
		switch (month) {
			case 1:
			case 2:
			case 12: printf("Зима\n\n\n"); goto start;
			case 3:
			case 4:
			case 5: printf("Весна\n\n\n");  goto start;
			case 6:
			case 7:
			case 8: printf("Лето\n\n\n"); goto start;
			case 9:
			case 10:
			case 11: printf("Осень\n\n\n"); goto start;
			default: goto abc1;
		}
	}
	goto start;

	/* task 6 */
	//Ввести возраст человека (от 1 до 150 лет) и вывести 
	//его вместе с последующим словом «год», «года» или «лет».
	task6: {
		int age = 0;
		while (age < 1 || age > 150) {
			printf("\n\n\nВведите возраст человека от 1 до 150:\n");
			scanf("%d", &age);
		}
		if (age % 10 == 1 && age != 11) {
			printf("%d год\n\n\n", age);
		} else if ((age % 10 == 2 && age != 12) || (age % 10 == 3 && age != 13)
												 || (age % 10 == 4 && age != 14)) {
			printf("%d года\n\n\n", age);
		} else {
			printf("%d лет\n\n\n", age);
		}
	}
	goto start;

	/* task 7 */
	//С клавиатуры вводятся числовые координаты двух полей шахматной 
	//доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля 
	//к одному цвету или нет.
	task7: {
		int x1 = -1, 
		x2 = -1, 
		y1 = -1, 
		y2 = -1;
		int fild_1 = -1,
		fild_2 = -1;
		printf("\n\n\nВведите координаты от 1 до 8 для первого и второго поля:");
		while (x1 < 1 || x1 > 8) {
			printf("\nх1: ");
			scanf("%d", &x1);
		}
		while (y1 < 1 || y1 > 8) {
			printf("\ny1: ");
			scanf("%d", &y1);
		}
		while (x2 < 1 || x2 > 8) {
			printf("\nх2: ");
			scanf("%d", &x2);
		}
		while (y2 < 1 || y2 > 8) {
			printf("\ny2: ");
			scanf("%d", &y2);
		}
		if (((x1+2) % 2 == 1 && (y1+2) % 2 == 1) || ((x1+2) % 2 == 0 && (y1+2) % 2 == 0)) {
			// printf("Var 1\n");
			fild_1 = 2;		// Черное
		} else {
			// printf("Var 2\n");
			fild_1 = 1;		// Белое
		}
		if (((x2+2) % 2 == 1 && (y2+2) % 2 == 1) || ((x2+2) % 2 == 0 && (y2+2) % 2 == 0)) {
			// printf("Var 3\n");
			fild_2 = 2;		// Черное
		} else {
			// printf("Var 4\n");
			fild_2 = 1;		// Белое
		}
		if ((fild_1 == 2 && fild_2 == 2) || (fild_1 == 1 && fild_2 == 1)) {
			printf("Поля одного цвета.\n\n\n");
		} else {
			printf("Поля разного цвета.\n\n\n");
		}
	}
	goto start;

	exit:
	return 0;
}















