#include <stdio.h>

long sumDigit(long a);

int main(int argc, char *argv[]) {
	long n;

	printf("Input number: ");
	scanf("%ld", &n);

	printf("Sum digit: %ld\n", sumDigit(n));

	return 0;
}

long sumDigit(long a) {
	long s = 0;

	while (a > 0) {
		s = s + a % 10;
		a = a / 10;
	}

	return s;
}