#include <stdio.h>

void function0_1000();

int main(int argc, char const *argv[])
{
	
	function0_1000();

	return 0;
}

void function0_1000() {
	int a = 1000;
	int sum;
	while (a > 0) {
		int aa = a;
		sum = 0;
		while (aa > 0) {
			sum = sum + aa % 10;
			aa /= 10;
		}
		if (a % 3 == 0 && a % 5 != 0 && sum < 10)
			printf("%d\n", a);
		a--;
	}
}