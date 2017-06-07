/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 04.06.17.
 */

#include "c1hw6.h"
#include <stdio.h>
#include <string.h>

/** ----- №1 -----
* Реализовать функцию перевода из 10 системы в 
* двоичную используя рекурсию. 
*/
void toBinary(int X,int res,int binRes,int count){
	if (count%2 == 0){ 
		res += toPow(2,count);
		binRes += 1;
	}
	if (count%2 != 0){

	}
	if (X == res) printf("%d\n",binRes); 
		else {
			toBinary(X,res,binRes*10,count+1);
		}	
}

//----- №2а -----
//----- №2б -----

/** ------ №3 ------
* У исполнителя Калькулятор две команды, которым присвоены номера: 
* 1. прибавь 1
* 2. умножь на 2
* Сколько есть программ, которые число 3 преобразуют в число 20?
* а) с использованием массива;
* б) с использованием рекурсии.
*/
/** 3а */
/** 3b */
int rec(int N){
	if (N == 3) return 1;
	if (N == 4) return rec(N-1);
	if (N%2 != 0) return rec(N-1);
	else return rec(N-1)+rec(N/2);
}

/**
* Блок исполнения:
*/
void doSolution1(){
	toBinary(16,0,0,0);
}
void doSolution2(){
	
}
void doSolution3(){
	printf("%d\n", rec(20));
}
void doSolution4(){
	printf("Nothing to do.\n");
}
void doSolution5(){
	printf("Nothing to do.\n");
}
void doSolution6(){
	printf("Nothing to do.\n");
}

int main(int argc, char const *argv[])
{
	int isOk = doMenu();

	printf("\nExit status: %d\n", isOk);
	return isOk;
}