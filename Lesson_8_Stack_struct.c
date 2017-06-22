#include <stdio.h>
#include <malloc.h>
#define T char

// Опишем структуру узла списка 
struct TNode {
	T value;
	struct TNode* next;
}; 
// Чтобы не писать везде struct TNode дадим этой структуре имя Node
typedef struct TNode Node; 
struct Stack {
 	Node* head;
 	int size;
}; 
int maxSize;
struct Stack Stack;

void push(T value){
 	if(Stack.size >= Stack.maxSize){
 		printf("Error stack size");
		return;
	}
	Node* tmp = (Node*) malloc(sizeof(Node)); 
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

// Выталкиваем из списка
T pop(){
 	if(Stack.size == 0){
 		printf("Stack is empty");
 		return;
	}
	// Временный указатель
 	Node* next = NULL;
	// Значение "наверху" списка
	T value; 
	value = Stack.head->value; 
	next = Stack.head; 
	Stack.head = Stack.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
 	Stack.size--; 
 	return value;
}

void PrintStack(){
 	Node* current = Stack.head; 
 	while(current != NULL){
		printf("%c " , current->value);
		current = current->next; 
	}
}

int main(int argc,char* argv[]){
 	Stack.maxSize = 100; 
 	Stack.head = NULL; 
 	push('a');
	push('b');
	push('c'); 
	push('d'); 
	push('e'); 
	push('f'); 
	PrintStack();
	return 0;
}
