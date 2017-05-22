#include <stdio.h>

long Pow(int a, int b);

int main(int argc, char const *argv[])
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);
	printf("%ld\n", Pow(a, b));

	return 0;
}


long Pow(int a, int b) {
	
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