/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 01.06.17.
 */

#include "c1hw6.h"

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
*4)	*Реализовать функцию void shift(char *str), которая будет циклически сдвигать 
*	строку вправо.
*5) *Даны два целочисленных массива, упорядоченных по возрастанию: А[n] и B[m]. 
*	Сформируйте массив C[n+m], состоящий из элементов массивов А и В, упорядоченный 
*	по возрастанию. Массивы A и B считать из файлов A.TXT и B.TXT.
*6)	На вход программе подается математическое выражение. Проверить правильность 
*	расстановки скобок
*	а) только для скобок ( и )
*	б) *для различных скобок (,{,[,],},).
*/
int length(char buffer[]){
	int count = 0;
	while (buffer[count] != '\0'){
		count++;
	}
	return count;
}
int findSymbol(char buffer[], char ch){
	int count = 0;
    for (int i = 0; i < length(buffer); i++){
        if (buffer[i] == ch) count++;
    }
    return count;
}
bool findO(char buffer[]){
	char arreyO[] = {'a','e','i','o','u','y'};
	for(int i = 0; i < length(arreyO); i++)
		for (int j = 0; j < length(buffer); j++)
			if (buffer[j] == arreyO[i])
				return true;
	return false;
}
void findOn(char buffer[]){
	int count;
	char arreyO[] = {'a','e','i','o','u','y'};
	int arreyNum[] = {-2,-2,-2,-2,-2,-2};
	for(int i = 0; i < length(arreyO); i++){
		count = 0;
		for (int j = 0; j < length(buffer); j++)
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


int main(int argc, char const *argv[])
{
	int isOk = doMenu();

	printf("\nExit status: %d\n", isOk);
	return isOk;
}