#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERM_WORD "end"
#define SIZE_INCREMENT 10

int main()
{
	
	char **words; //Массив указателей на слова
	char buffer[128]; //Строка, которая используется для считывания введённого пользователем слова
	unsigned wordCounter = 0; //Счётчик слов
	unsigned length; //Длина введённого слова
	unsigned size = SIZE_INCREMENT; //Размер массива слов. Для уменьшения издержек на выделение памяти
	int i;							//каждый раз будем увеличивать массив слов не на одно значение, а на
									//SIZE_INCREMENT слов
	
	words = (char**) malloc(size*sizeof(char*)); //Выделяем память под массив из size указателей
	do {
		printf("%d: ", wordCounter);
		scanf("%127s", buffer);
		if (strcmp(TERM_WORD, buffer) == 0) { //Функция strcmp возвращает 0, если две строки равны
		break;
	}
	length = strlen(buffer); //Определяем длину слова
	if (wordCounter >= size) {  //В том случае, если введено слов больше, чем длина массива, то
		size += SIZE_INCREMENT; //увеличиваем массив слов
		words = (char**) realloc(words, size*sizeof(char*));
	}
	words[wordCounter] = (char*) malloc(length + 1); //Выделяем память непосредственно под слово
													//на 1 байт больше, так как необходимо хранить 
													//терминальный символ
	strcpy(words[wordCounter], buffer); //Копируем слово из буффера по адресу, который
	wordCounter++;						//хранится в массиве указателей на слова
	} while(1);
	for (i = 0; i < wordCounter; i++) {
		printf("%s\n", words[i]);
	}
	for (i = 0; i < wordCounter; i++) {
		free(words[i]);
	}
	free(words);
	return 0;
}