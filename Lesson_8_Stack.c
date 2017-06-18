#include <stdio.h> 

#define T char
#define MaxN 1000 

T Stack[MaxN];
int N = -1;

void push(T i){
	if (N < MaxN){
		N++;
		Stack[N] = i;
	} else 
		printf("Stack overflow");
}

T pop(){
	if   (N != -1)
		return Stack[N--];
	else { 
		printf("Stack is empty");
		return -1;
	}
}

int main(int argc,char *argv[]){
	T c;
	push('a');
	push('b');
	push('c');
	push('d');
	push('e');
	push('f');
	while (N != -1) 
		printf("%c",pop());
	return 0;
}