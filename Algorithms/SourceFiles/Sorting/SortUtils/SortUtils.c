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