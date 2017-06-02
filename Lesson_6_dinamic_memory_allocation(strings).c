#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int strMaxSize=100;
	char *string=(char *)malloc(strMaxSize*sizeof(char)+10);
	if(string==NULL)
	{
		puts("Can't allocated memory");
		return 2;
	}
	puts("Input string:");
	gets(string);
	int len=strlen(string); // Текущая длина(до '\0')
	printf("strlen %d\n",len);
	string[len]='!'; // Заменяем последний символ
	string[len+1]='\0'; // Добавляем признак конца строки
	puts("New string:");
	puts(string);
	printf("String address %p, value is %s\n",&string,string);
	free(string);
	puts("Memory free");
	printf("String address %p, value is %s",&string,string);
	return 0;
}