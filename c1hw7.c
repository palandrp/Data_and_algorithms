/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 04.06.17.
 */

//#include "c1hw6.h"
#include <stdio.h>
#include <string.h>

/**
* У исполнителя Калькулятор две команды, которым присвоены номера: 
* 1. прибавь 1
* 2. умножь на 2
* Сколько есть программ, которые число 3 преобразуют в число 20?
*/

//###### Задание№3 #######
//######## Begin #########
int rec(int N){
	if (N == 3) return 1;
	if (N == 4) return rec(N-1);
	if (N%2 != 0) return rec(N-1);
	else return rec(N-1)+rec(N/2);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", rec(20));
	return 0;
}