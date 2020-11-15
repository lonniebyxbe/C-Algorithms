#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Random/Random.h"
#include "Sorting/SortUtils.h"
#include "Sorting/MergeSort.h"

#define PRINTCOUNT 500

void merge_sort(void)
{
	unsigned long ran_count = 0;
	unsigned long* count = &ran_count;
	unsigned long* longarray = NULL;

	printf("\n\nMerge Sort!!\n\n");

	longarray = get_unsigned_long_array(count);

	printf("\n\n");

	if (longarray != NULL)
	{
		if (ran_count < PRINTCOUNT)
		{
			printf("Printing array\n");
			printarray(longarray, ran_count);
		}

		printf("\n\nSorting array\n");
		do_merge_sort(longarray, ran_count);
		printf("\nSorting finished!\n");

		if (ran_count < PRINTCOUNT)
		{
			printarray(longarray, ran_count);
			printf("\n\n\n\n");
		}

		free((void*)longarray);
	}
	else
	{
		printf("No numbers were generated.\n\n");
	}
}

void do_merge_sort(unsigned long* longarray, unsigned long count)
{
}