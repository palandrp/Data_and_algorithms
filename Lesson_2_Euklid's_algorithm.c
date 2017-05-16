#include <stdio.h>

// Определение наибольшего общего делителя. Алгоритм Эвклида
int main(int argc, char *argv[]) {
	
	int a, b;

	printf("%s","Input a:");
	scanf("%d",&a);
	printf("%s","Input b:");
	scanf("%d",&b);

	while(a != b)
	if (a > b) {
		a = a - b;
	} else {
		b = b - a;
	}
	
	printf("GCD: %i",a);
	
	return 0;
}