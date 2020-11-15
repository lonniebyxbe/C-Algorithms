#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu\menu.h"
#include "Menu\MenuItem.h"
#include "Sorting\InsertionSort.h"


//TODO: sorting menus should be arrays maybe(?)

void display_menu(void);
void print_header(void);   
void print_empty(void);
int get_input(void);
void create_sort_menu(menu_item* item);

void display_menu(void)
{
	printf("\n\n");
	print_header();
	print_empty();
	printf("*\t1) Sorting\t\t                        *\n");
	print_empty();
	printf("*\tQ) Quit   \t\t                        *\n");
	print_empty();
	print_header();
}

void display_sort_menu(void)
{
	printf("\n\n");
	print_header();
	print_empty();
	printf("*\t1) Insertion\t\t                      *\n");
	print_empty();
	printf("*\tQ) Quit   \t\t                        *\n");
	print_empty();
	print_header();
}


int process_menu(void)
{
	int c;

	clear_screen();
	display_menu();
	c = get_input();

	if (c == 1  || c == -1)
	{
		return c;
	}
	else
	{
		return process_menu();
	}
	
}

char process_sorting(void)
{
	int c;

	clear_screen();
	display_sort_menu();
	c = get_input();

	if (c == 1)
	{
		return c;
	}
	else if(c == -1)
	{
		return c;
	}
	else
	{
		return process_sorting();
	}
}

void print_header(void)
{
	printf("*********************************************************\n");
}

void print_empty(void)
{
	printf("*                                                       *\n");
}

int get_input(void)
{
	char c = 0;
	int intptr = 0;
	int digit_count = 0;

	printf("\nPlease enter a value.\n");

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (isdigit(c))
		{
			intptr = intptr * 10 + (c - '0');
			digit_count++;
		}
	}

	if (digit_count)
	{
		return intptr;
	}
	else 
	{
		return -1;
	}
	/*scanf_s("%c", &c, sizeof(char));

	return c;*/
}

void create_sort_menu(menu_item * item)
{
	menu_item children[2];

	children[0].description = "Insertion Sort";
	children[0].id = 1;
	children[0].id_alias = NULL;
	children[0].children = NULL;

	children[1].description = "Merge Sort";
	children[1].id = 2;
	children[1].id_alias = NULL;
	children[1].children = NULL;

	item->children = children;
}

void clear_screen(void)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}