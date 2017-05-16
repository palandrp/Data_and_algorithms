#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int number;
	
	printf("Input number:");
	scanf("%i",&number);
	
	int d = 0, i = 2;
	
	while (i<number) {
		if (number % i == 0) d++;
		i++;
	}
	
	if (d == 0) 
		printf("Number is simple");
	else 
		printf("Number is not simple");
	
	return 0;
}