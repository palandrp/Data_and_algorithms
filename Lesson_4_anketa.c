#include <stdio.h>

int main() {

	char fname[20];
	char lname[20];
	int age, height, weight;

	printf("Input first name:");
	scanf("%20s", fname);

	printf("Input last name:");
	scanf("%20s", &lname[0]); // lname

	printf("Input age:");
	scanf("%d", &age);

	printf("Input height:");
	scanf("%d", &height);

	printf("Input weight:");
	scanf("%d", &weight);

	printf("%s %s %d %d %d\n", fname, lname, age, height, weight);
 
	return 0;
}