#include   <stdio.h>

void TowerOfHanoi(int from,int to,int other,int n)
{
 	if (n>1) TowerOfHanoi(from,other,to,n-1);
 		printf("%d %d\n",from,to);
 	if (n>1) TowerOfHanoi(other,to,from,n-1);
}  
int main()
{
	TowerOfHanoi(1,2,3,9);
	return 0;
}  