#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Size of char %ld\n",sizeof(char));
	printf("Size of int %ld\n",sizeof(int));
	printf("Size of float %ld\n",sizeof(float));
	printf("Size of double %ld\n",sizeof(double));
	printf("Size of FILE %ld\n",sizeof(FILE));
	return 0;
}