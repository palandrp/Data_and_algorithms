#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	const char *string = "36.6% is normal";
	double d;
	char *stringPtr;
		// string - адрес строки для преобразования
		// stringPtr - передаём внутрь функции адрес строки через 
		// операцию взятия адреса, чтобы внутри функции можно было изменить этот адрес
		// и вернуть первое вхождение символа, на котором преобразование остановилось
	d = strtod( string, &stringPtr );
	printf( "The string \"%s\" is converted to the\n", string);
	printf( "double value %.2f and the string \"%s\"\n", d, stringPtr );
	return 0;
}