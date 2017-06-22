#include <stdio.h> 
#define MaxN 1000 
#define T char 

struct TStack{
	int N; 			// Номер верхнего элемента
	T Data[MaxN]; 	// Данные
};
#define struct TStack TStack;

TStack Stack1;
TStack Stack2;
TStack Stack3;

void push(TStack *Stack,T data){
 	Stack->N++;
	(*Stack).Data[(*Stack).N] = data; // Или так Stack->Data[Stack->N]=data;
}
	
T pop(TStack *Stack){
	if(Stack->N != -1) 
		return Stack->Data[Stack->N--];
	return '0';
}

void init(TStack *Stack){
	Stack->N = -1;
} 

int main(int argc,char* argv[]){
	init(&Stack1);
	init(&Stack2);
	init(&Stack3);
	push(&Stack1,'a');
	push(&Stack1,'b');
	push(&Stack2,'c');
	push(&Stack3,'d');
	push(&Stack1,'e');
	push(&Stack1,'f');
 	while(Stack1.N != -1) printf("%c",pop(&Stack1));
 	return 0;
} 