#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>

/*Написать программу, загружающую из файла последовательность символьных
строк ограниченной д лины и располагающая их элементы в динамически создаваемом
двусвязном списке. Отсортировать список и вывести его на экран.*/

struct TDblNode {
 	char string[256];
 	struct TDblNode *next;
 	struct TDblNode *prev;
};
typedef struct TDblNode Node;
struct DblList {
 Node *head,*tail,*current;
};
struct DblList List;

/*Основные действия, производимые над узлами ДС: 
Инициализация списка
Добавление узла в список
Удаление узла из списка
Удаление корня списка
Вывод элементов списка
Вывод элементов списка в обратном порядке 
Взаимообмен двух узлов списка*/

// Инициализация ДЛС
Node* init(char *a){
 	Node *temp;
	// Выделение памяти под корень списка
	temp = (Node*) malloc(sizeof(Node));
  	// Перенос строки
	strcpy(temp->string,a);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
} 

/*Добавление узла в ДС
Функция добавления узла в список принимает два аргумента:
Указатель на узел, после которого п роисходит добавление
Данные для добавляемого узла.*/

/*Добавление узла в ДС включает в себя следующие этапы:
создание узла добавляемого элемента и заполнение его поля данных;
переустановка указателя "следующий" узла, предшествующего добавленному, на 
добавляемый
узел; переустановка указателя "предыдущий" узла, следующего за добавляемым, на 
добавляемый узел; установка указателя "следующий" добавляемого узла на следующий 
узел(тот, на который указывал предшествующий узел); установка указателя 
"предыдущий" добавляемого узла на узел, предшествующий добавляемому
(узел, переданный в функцию).*/

Node* addElem(Node *current,char *a){
 	Node *temp,*p;
 	temp =(Node*) malloc(sizeof(Node));
 	p = current->next;
	current->next = temp;
	strcpy(temp->string,a);
	// Перенос строки 
	temp->next = p;
	temp->prev = current;
 	if(p != NULL) p->prev = temp;
 		current = temp;
 	return current;
} 

/*Удаление узла ДС включает в себя следующие этапы:
установка указателя "следующий" предыдущего узла на узел, следующий за удаляемым;
установка указателя "предыдущий" с ледующего узла на узел, предшествующий удаляемому;
освобождение памяти удаляемого узла.*/

// Вывод элементов ДС
void listPrint(){
 	Node *p = List.head;
 	do {
 		if(p == List.current) printf("*");
 		printf("%s ",p->string);
 		p = p->next;
	}
	while(p != NULL); // Условие окончание обхода
} 

int main(void){
 	char buf[256];
	FILE *file;
	file = fopen("str.txt","r");
	fscanf(file,"%s",buf);
	List.head = init(buf);
	List.current = List.head;
	List.tail = List.head;
 	while (fscanf(file,"%s",buf)!= EOF) {
		List.current = addElem(List.current,buf);
	} 
 	listPrint();
	printf("\n");
	return 0;
} 