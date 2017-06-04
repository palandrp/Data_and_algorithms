#include   <stdio.h> 

int long Fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return Fib(n - 1)+Fib(n - 2);
}

int main (int argc, char *argv[])
{
	int i,count = 0;  
	for (i = 0; i < 50; i++){
		count++;
		printf ("%d: %ld\n", count, Fib(i)); 
	}
	return 0;
}