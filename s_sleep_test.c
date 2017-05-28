#include <stdio.h>
#include <time.h>

void s_sleep(unsigned long _time)
{
    clock_t ttime, ntime;
    ttime = clock();
    while (ntime < _time)
    {
        ntime = clock();
        printf("%ld ", ntime);
        ntime -= ttime;
        printf("- %ld (%ld)\n", ttime, _time);
    }
}

int main(int argc, char const *argv[])
{
	s_sleep(100);
	return 0;
}