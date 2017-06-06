/**
 * Algorithms and data structure
 *
 * @author Pavel Petrikovskiy
 * @version 06.06.17.
 */

#include <stdio.h>

// У исполнителя Калькулятор две команды, которым присвоены номера: 
// 1. прибавь 1
// 2. умножь на 4
// Сколько есть программ, которые число 1 преобразуют в число 32?

int rec(int N){
	if (N == 1) return 1;
	if (N%4 != 0) return rec(N-1);
	else return rec(N-1)+rec(N/4);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", rec(42));
	return 0;
}