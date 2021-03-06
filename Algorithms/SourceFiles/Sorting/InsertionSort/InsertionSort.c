#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Sorting/InsertionSort.h"
#include "Random/Random.h"
#include "Sorting/SortUtils.h"

#define PRINTCOUNT 500

void insertion_sort(void)
{
	unsigned long ran_count = 0;
	unsigned long* count = &ran_count;
	unsigned long* longarray = NULL;

	printf("\n\nInsertion Sort!!\n\n");
	
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
		do_sort(longarray, ran_count);
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


void do_sort(unsigned long* longarray, unsigned long count)
{
	unsigned long i,key = 0;
	int overflow = 0;
	unsigned int comp_count = 0;

	if (count > 1)
	{  
		for (unsigned long j = 1; j < count; j++)
		{
			key = longarray[j];
			i = j - 1;
			overflow = 0;
			while (key < longarray[i] && i >= 0 && !overflow)
			{
				comp_count++;
				longarray[i + 1] = longarray[i];
				// longarray[i] = key;
				if (i == 0)
				{
					// we are decrementing an unsigned long, -1 does not exist
					overflow = 1;
				}
				i--;
			}

			if (overflow && key < longarray[0])
			{
				// we went all the way to the beginning
				longarray[0] = key;
				i = 0;
			}
			else
			{
				longarray[i + 1] = key;
			}
			
			/*printf("Pass: j=> %lu : i=> %lu : key=> %lu \n", j, i, key);
			printarray(longarray, count);
			printf("\n");*/
		}
		printf("%lu comparisons made, for a ratio of %lf\n", comp_count, (float)(comp_count / count));
	}
}