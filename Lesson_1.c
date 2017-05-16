#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* Sample 1 */
	int a, b;
	printf("Input a: ");
	scanf("%d",&a);
	printf("Input b: ");
	scanf("%d",&b);
	if (a > b){
		printf("max = %d\n", a);
	} else {
		printf("max = %d\n", b);
	}

	/* Sample 2 */
	int age;
	printf("Input employee age: ");
	scanf("%d",&age);
	if (age >= 25){
		if (age <= 50){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		printf("NO\n");
	}

	/* Sample 3 */
	if (age >= 25 && age <= 50){
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	/* Sample 4 */
	// metka;
	// printf("Endless cycle!\n");
	// goto metka;

	/* Sample 5 */
	

	return 0;
}







