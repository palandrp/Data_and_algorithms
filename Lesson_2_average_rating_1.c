#include <stdio.h>

// Вычисление средней оценки инструкцией повторения, управляемой счетчиком
int main(int argc, char *argv[]) {
	
	unsigned int counter; // количество оценок
	int grade; // значение оценки
	int sum; // сумма оценок
	double average; // средняя оценка
	
	// Фаза инициализации
	sum = 0;
	counter = 1;
	
	while (counter <= 10) {
		printf("Enter grade: ");
		scanf("%d", &grade);
		sum = sum + grade;
		counter++;
	}

	average = (double) sum / 10;
	printf("Class average is %g\n",average);

	return 0;
}