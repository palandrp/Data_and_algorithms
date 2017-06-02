#include <stdio.h>
#include <malloc.h>
int main(void)
{
		FILE *in;
		in=fopen("d:\\temp\\data.txt","r");
		if (in==NULL) {
		printf("Can't open file!");
		return 1;
	}
	int size=0,num;
		// Подсчитываем количество чисел в файле
	while (!feof(in)) // пока не конец файла
	{
		if (fscanf(in,"%d",&num)>0)
		{
			size++;
		}
	}
	fseek(in,0,SEEK_SET); // устанавливаем указатель файла на начало
		// SEEK_SET – смещение отсчитывается от начала файла
		// SEEK_CUR – смещение отсчитывается от текущей позиции
		// SEEK_END – смещение отсчитывается от конца файла
	int *a=NULL;
	a=(int *)malloc(size*sizeof(int));// это что-то типа этого int a[size];
		// a=(int *)calloc(size,sizeof(int)); // можно было ещё вот так
	if (a==NULL)
	{
		puts("Can't allocated memory");
		return 2;
	}
	int i=0;
	while (!feof(in))
	{
		if (fscanf(in,"%d",&num)>0)
		{
			a[i]=num;
			i++;
		}
	}
	fclose(in);
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	return 0;
}