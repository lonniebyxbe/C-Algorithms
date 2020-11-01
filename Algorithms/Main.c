#include <stdio.h>

#include "Menu/menu.h"
#include "Sorting/InsertionSort.h"

int main(void)
{
	int option;
	option = process_menu();

	if (option == 1)
	{
		option = process_sorting();
		if (option == '1')
		{
			clear_screen();
			insertion_sort();
		}
	}

	return 0;
}