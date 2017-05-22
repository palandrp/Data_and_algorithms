#include <stdio.h>

long reverse(long n);

int main(int argc, char *argv[]) {
	long n;

	printf("Input number: ");
	scanf("%ld", &n);

	printf("%ld %ld\n", n, reverse(n));

	return 0;
}

long reverse(long n) {
	long newN = 0;

	while(n > 0) {
		newN = newN * 10 + n % 10;
		n /= 10;
	}

	return newN;
}