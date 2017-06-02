/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 01.06.17.
 */

#include "c1hw6.h"
#include <string.h>

/**
*1) С клавиатуры вводится строка символов:
*	а) Написать собственную функцию аналог strlen.
*	б) Вводится символ. Написать функцию, которая подсчитывает сколько раз символ 
*	входит в строку;
*	в) Написать программу, которая определяет, есть ли в строке гласные буквы;
*	г) *Написать программу, которая определяет, какая гласная буква встречается 
*	чаще всего;
*	д) **Предусмотреть, что некоторые гласные могут встречаться одинаково часто. 
*	В этом случае вывести сообщение, что нет наиболее часто встречающейся гласной.
*2) a. **Для двух строк напишите функцию, определяющую, является ли одна строка 
*	перестановкой другой. “МИРА=ИРМА”
*	b. **напишите утилиту, которая решает задачу принимая две строки в качестве 
*	параметров командной строки
*3)	**Реализовать функцию, осуществляющую сжатие строки, на основе счётчика 
*	повторяющихся символов. Например, строка aabcccccaaa должна превратиться в 
*	a2b1c5a3. Если “сжатая” строка оказывается длиннее исходной, функция должна 
*	вернуть исходную строку.
*/

//###### Задание№1 #######
//######## Begin #########
int lengthLocal(char buffer[]){
	int count = 0;
	while (buffer[count] != '\0'){
		count++;
	}
	return count;
}
int findSymbol(char buffer[], char ch){
	int count = 0;
    for (int i = 0; i < lengthLocal(buffer); i++){
        if (buffer[i] == ch) count++;
    }
    return count;
}
bool findO(char buffer[]){
	char arreyO[] = {'a','e','i','o','u','y'};
	for(int i = 0; i < lengthLocal(arreyO); i++)
		for (int j = 0; j < lengthLocal(buffer); j++)
			if (buffer[j] == arreyO[i])
				return true;
	return false;
}
void findOn(char buffer[]){
	int count;
	char arreyO[] = {'a','e','i','o','u','y'};
	int arreyNum[] = {-2,-2,-2,-2,-2,-2};
	for(int i = 0; i < lengthLocal(arreyO); i++){
		count = 0;
		for (int j = 0; j < lengthLocal(buffer); j++)
			if (buffer[j] == arreyO[i]){
				count++;
			}
		arreyNum[i] = count;
	}
	int max = 0;
	int num = -1;
	for (int i = 0; i < 6; i++)
		if (arreyNum[i] > max){
			max = arreyNum[i];
			num = i;
		}
	if (max != 0)
		for (int i = 0; i < 6; i++)
			if (max == arreyNum[i] && i != num) {
				printf("Нет конкретной максимально часто встречающейся гласной!\n");
				return;
			}
	if (num == 0) printf("Max -> a\n");
	if (num == 1) printf("Max -> e\n");
	if (num == 2) printf("Max -> i\n");
	if (num == 3) printf("Max -> i\n");
	if (num == 4) printf("Max -> u\n");
	if (num == 5) printf("Max -> y\n");
}
//###### Задание№1 #####
//######## END #########
//==============================
//###### Задание№2 #######
//######## Begin #########
bool compare(char** words){
	int i=0,j=lengthLocal(words[1])-1;
    while (i < lengthLocal(words[0])){
        if (words[0][i] != words[1][j]) return false;
        i++;
        j--;
    }
	return true;
}
// int main(int argc, char const *argv[]){
// 	if (compare(argv[])) printf("true\n");
// 	else printf("false\n");
// 	return 0;
// }
//###### Задание№2 #####
//######## END #########
//==============================
//###### Задание№3 #######
//######## Begin #########


//###### Задание№3 #####
//######## END #########
//==============================

//#########################
//#### Блок исполнения ####
//#########################
void doSolution1(){
	char buffer[128];
	char ch = 'f';
	scanf("%127s", buffer);
	printf("%d\n", lengthLocal(buffer));
	printf("%d\n", findSymbol(buffer,ch));
	if(findO(buffer)) printf("true\n");
	else printf("false\n");
	findOn(buffer);
}
void doSolution2(){
	char **words;
	char buffer[128];
	int length;
	words = (char**) malloc(2*sizeof(char*));
	for (int i = 0; i < 2; i++){
		scanf("%127s", buffer);
		length = lengthLocal(buffer);
		words[i] = (char*) malloc((length + 1)*sizeof(char*));
		strcpy(words[i], buffer);
	}
	if (compare(words)) printf("true\n");
	else printf("false\n");
}
void doSolution3(){

}
void doSolution4(){

}
void doSolution5(){

}
void doSolution6(){
	
}

int main(int argc, char const *argv[])
{
	int isOk = doMenu();

	printf("\nExit status: %d\n", isOk);
	return isOk;
}