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

if ( Stack . size >= Stack . maxSize )  { 
	printf ( "Error stack size" );
	 return;
} 

Node   * tmp;

tmp =( Node *) malloc ( sizeof ( Node ));

tmp -> value = value ;  // записываем данные 
tmp -> next = Stack . head ; // записываем предыдущее значение главы

