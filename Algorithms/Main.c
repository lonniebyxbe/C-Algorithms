#include <stdio.h>

#include "Menu/menu.h"
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"

int main(void)
{
	int option = 0;
	option = process_menu();

	//while (option != 'q' && option != 'Q')
	//{
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
	//		else if (option != 'q' && option != 'Q')
	//		{
	//			option = process_sorting();
	//		}
	//	}

	//	option = process_menu();
	//}

	return 0;
}