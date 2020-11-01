#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Random/Random.h"


unsigned long* get_unsigned_long_array(unsigned long* count)
{
	unsigned long value;
	time_t t;
	unsigned long* longarray = NULL;

	// printf("RAND_MAX is %u\n", RAND_MAX);
	// printf("Size of RAND_MAX is %d\n", sizeof(RAND_MAX));

	*count = get_random_count();

	longarray = (unsigned long*)malloc(*count * sizeof(unsigned long));

	if (longarray == NULL)
	{
		printf("Unable to allocate enough memory for %lu numbers.\n", *count);
	}
	else if (*count < 1)
	{
		printf("Unable to generate so few numbers!!\n");
		free((void*)longarray);
		longarray = NULL;
	}
	else
	{
		printf("\n\n\n\n");
		printf("Generating %d random numbers.\n", *count);

		srand((unsigned)time(&t));

		value = random_long() % (*count * 4);
		longarray[0] = value;
		// printf("%lu", value);
		for (unsigned long i = 1; i < *count; i++)
		{
			value = random_long() % (*count * 4);
			longarray[i] = value;
			// printf(", %lu", value);
		}
	}

	return longarray;
}

unsigned long random_long(void)
{
	unsigned long ran = 0;

	for (int i = 0; i <= 2; i++)
	{
		ran = (ran << 15) | (rand() & 0x7FFF);
	}

	return ran;
}

unsigned long get_random_count(void)
{
	unsigned long count = 0;

	printf("How many numbers would you like to generate?\n");

	scanf_s("%lu", &count);

	return count;
}