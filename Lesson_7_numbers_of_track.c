#include <stdio.h>

#define N 3
#define M 3

void Print2(int n, int m, int a [N][M]){
	int i,j; 
	for (i = 0; i < n; i++){
 		for (j = 0; j < m; j++) 
 			printf ("%4d", a[i][j]);
			printf ("\n"); 
		}
	}
	
int main (int argc, char *argv[]){
 	int A[N][M];
 	int i,j;
 		for (j = 0; j < M; j++)  
 			A[0][j] = 1; // Первая строка заполнена единицами  for (i = 1; i < N; i++)
 			A[i][0] = 1;  
 			for (j = 1; j < M; j++){
				A[i][j] = A[i][j - 1] + A[i - 1][j]; 
			}
 		Print2(N,M,A); 
 	return 0;
 }  