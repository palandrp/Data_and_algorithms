struct TNode {
	int value;  // Данные
	struct TNode * next; // Указатель на следующий элемент списка
};

typedef struct TNode Node;

struct Stack {
	Node * head;
	int size;
	int maxSize;
}; 

struct Stack Stack;

Stack.maxSize = 100;
Stack.head = NULL;