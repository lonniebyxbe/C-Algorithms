#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Random/Random.h"
#include "Sorting/SortUtils.h"
#include "Sorting/MergeSort.h"

#define PRINTCOUNT 500

void mergesort(unsigned long* arr, unsigned long lower, unsigned long upper);
void merge(unsigned long* arr, unsigned long lower, unsigned long mid, unsigned long upper);

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
	mergesort(longarray, 0, count - 1);
}

void mergesort(unsigned long* arr, unsigned long lower, unsigned long upper)
{
	unsigned long mid = 0;
	static unsigned long sortcount = 0;

	if (lower < upper)
	{
		sortcount++;
		mid = (lower + upper) / 2;
		mergesort(arr, lower, mid);
		mergesort(arr, mid + 1, upper);
		merge(arr, lower, mid, upper);
	}
	else 
	{
		printf("\nMergeSort called %lu times.\n", sortcount);
	}
}

void merge(unsigned long* arr, unsigned long lower, unsigned long mid, unsigned long upper)
{
	unsigned long* lowarr;
	unsigned long* higharr;
	unsigned long lowsize = mid - lower + 1;
	unsigned long highsize = upper - mid;
	unsigned long i = 0, j = 0, k = 0;
	short lowoverflow = 0, highoverflow = 0;
	
	lowarr = (unsigned long*)malloc(lowsize * sizeof(unsigned long));
	higharr = (unsigned long*)malloc(highsize * sizeof(unsigned long));

	if (lowarr != NULL && higharr != NULL)
	{

		for (unsigned long i = 0; i < lowsize; i++)
		{
			lowarr[i] = arr[i];
		}
		for (unsigned long j = 0; j < highsize; j++)
		{
			higharr[j] = arr[mid + j + 1];
		}

		i = 0;
		j = 0;

		printf("lowarr\n");
		printarray(lowarr, lowsize);
		printf("\nhigharr\n");
		printarray(higharr, highsize);
		for (k = lower; k < upper; k++)
		{
			if (!(lowoverflow || highoverflow))
			{
				if (lowarr[i] <= higharr[j])
				{
					printf("\n\nla: %lu -- ha: %lu\nls: %lu, hs: %lu\n\n", lowarr[i], higharr[j], lowsize, highsize);

					arr[k] = lowarr[i];
					i++;
					if (i >= lowsize)
					{
						lowoverflow = 1;
					}
				}
				else
				{
					printf("\n\nla: %lu -- ha: %lu\nls: %lu, hs: %lu\n\n", lowarr[i], higharr[j], lowsize, highsize);

					arr[k] = higharr[j];
					j++;
					if (j >= highsize)
					{
						highoverflow = 1;
					}
				}
			}
		}
		if (lowoverflow)
		{
			arr[k] = higharr[j];
		}
		else 
		{
			arr[k] = lowarr[i];
		}

		free((void*)lowarr);
		free((void*)higharr);
	}
	else 
	{
		printf("Could not allocate space for a merge array.");
	}
}
