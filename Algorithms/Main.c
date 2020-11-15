#include <stdio.h>

#include "Menu/menu.h"
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"

int main(void)
{
	int option;
	option = process_menu();

	if (option == 1)
	{
		option = process_sorting();
		if (option == 1)
		{
			clear_screen();
			insertion_sort();
		}
		else if (option == 2)
		{
			clear_screen();
			merge_sort();
		}
	}

	return 0;
}