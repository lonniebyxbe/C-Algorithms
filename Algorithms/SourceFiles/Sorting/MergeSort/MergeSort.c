#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Random/Random.h"
#include "Sorting/SortUtils.h"
#include "Sorting/MergeSort.h"

#define PRINTCOUNT 500
//#define _MERGEDEBUG_ 1

void mergesort(unsigned long* arr, unsigned long lower, unsigned long upper);
void merge(unsigned long* arr, unsigned long lower, unsigned long mid, unsigned long upper);

void merge_sort(void)
{
	unsigned long ran_count = 0;
	unsigned long* count = &ran_count;
	unsigned long* longarray = NULL;

	printf("\n\nMerge Sort!!\n\n");

#ifdef _MERGEDEBUG_
	longarray = (unsigned long*)malloc(5 * sizeof(unsigned long));
	//longarray[0] = 14;
	//longarray[1] = 1;
	//longarray[2] = 13;
	//longarray[3] = 8;
	//longarray[4] = 19;
	longarray[0] = 17;
	longarray[1] = 4;
	longarray[2] = 8;
	longarray[3] = 5;
	longarray[4] = 7;
	//17 4 8 5 7
	ran_count = 5;
#else
	longarray = get_unsigned_long_array(count);
#endif
	printf("\n\n");

	if (longarray != NULL)
	{
		if (ran_count < PRINTCOUNT)
		{
			printf("Printing array\n");
			printarray(longarray, ran_count);
		}

		printf("\n\nSorting array\n\n");
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

#ifdef _MERGEDEBUG_
	printf("Entering mergesort. lower is %lu , upper is %lu\n", lower, upper);
	printf("MergeSort called %lu times.\n", sortcount);
	printf("Array is: \n");
	printarrayrange(arr, lower, upper);
	printf("\n\n\n");
#endif

	if (lower < upper)
	{
		mid = (lower + upper) / 2;
		sortcount++;
		mergesort(arr, lower, mid);
		sortcount++;
		mergesort(arr, mid + 1, upper);
		merge(arr, lower, mid, upper);

#ifdef _MERGEDEBUG_
		printf("\nmerged array is: \n");
		printarrayrange(arr, lower, upper);
		printf("\n\n\n");
#endif
	}
	else 
	{
		printf("End of mergesort leg: MergeSort called %lu times.\n\n", sortcount);
	}
}

void merge(unsigned long* arr, unsigned long lower, unsigned long mid, unsigned long upper)
{
	unsigned long* lowarr;
	unsigned long* higharr;
	unsigned long lowsize = mid - lower + 1;
	unsigned long highsize = upper - mid;
	unsigned long i = 0, j = 0;
	short lowoverflow = 0, highoverflow = 0;
	
	lowarr = (unsigned long*)malloc(lowsize * sizeof(unsigned long));
	higharr = (unsigned long*)malloc(highsize * sizeof(unsigned long));

	if (lowarr != NULL && higharr != NULL)
	{
#ifdef _MERGEDEBUG_
		printf("\n\nMerging:\n");
		printf("lower: %lu , mid: %lu , upper: %lu\n", lower, mid, upper);
#endif
		for (unsigned long i = 0; i < lowsize; i++)
		{
			lowarr[i] = arr[lower + i];
		}
		for (unsigned long j = 0; j < highsize; j++)
		{
			higharr[j] = arr[mid + j + 1];
		}

		i = 0;
		j = 0;

#ifdef _MERGEDEBUG_
		printf("lowarr\n");
		printarray(lowarr, lowsize);
		printf("\nhigharr\n");
		printarray(higharr, highsize);
#endif
		for (unsigned long k = lower; k <= upper; k++)
		{
			if (lowoverflow)
			{
				arr[k] = higharr[j];
				j++;
			}
			else if(highoverflow)
			{
				arr[k] = lowarr[i];
				i++;
			}
			else if (lowarr[i] <= higharr[j])
			{
#ifdef _MERGEDEBUG_
				printf("\n\nla: %lu -- ha: %lu\nls: %lu, hs: %lu\n\n", lowarr[i], higharr[j], lowsize, highsize);
#endif

				arr[k] = lowarr[i];
				i++; 
				if (i >= lowsize)
				{
					lowoverflow = 1;
				}
			}
			else
			{
#ifdef _MERGEDEBUG_
				printf("\n\nla: %lu -- ha: %lu\nls: %lu, hs: %lu\n\n", lowarr[i], higharr[j], lowsize, highsize);
#endif

				arr[k] = higharr[j];
				j++;
				if (j >= highsize)
				{
					highoverflow = 1;
				}
			}
		}

#ifdef _MERGEDEBUG_
		printarrayrange(arr, lower, upper);
		printf("\n");
#endif

		free((void*)lowarr);
		free((void*)higharr);
	}
	else 
	{
		printf("Could not allocate space for a merge array.");
	}
}
