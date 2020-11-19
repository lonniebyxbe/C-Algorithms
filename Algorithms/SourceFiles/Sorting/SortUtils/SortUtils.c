#include <stdio.h>

void printarray(unsigned long* longarray, unsigned long count)
{
	if (count > 0)
	{
		printf("0: %lu ", longarray[0]);
		for (unsigned long i = 1; i < count; i++)
		{
			printf(" |  %lu: %lu ", i, longarray[i]);
		}
	}
}

void printarrayrange(unsigned long* longarray, unsigned long begin, unsigned long end)
{
	if (end - begin >= 0)
	{
		printf("0: %lu ", longarray[begin]);
		for (unsigned long i = begin + 1; i <= end; i++)
		{
			printf(" |  %lu: %lu ", i, longarray[i]);
		}
	}
}