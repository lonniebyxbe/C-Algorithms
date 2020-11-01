#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Sorting/InsertionSort.h"
#include "Random/Random.h"

#define PRINTCOUNT 500


void printarray(unsigned long* longarray, unsigned long count);
void do_sort(unsigned long* longarray, unsigned long count);

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

void printarray(unsigned long* longarray, unsigned long count)
{
	if (count > 0)
	{
		printf("0: %lu ",longarray[0]);
		for (unsigned long i = 1; i < count; i++)
		{
			printf(" |  %lu: %lu ", i, longarray[i]);
		}
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
					overflow = 1;
				}
				i--;
			}

			if (overflow && key < longarray[0])
			{
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