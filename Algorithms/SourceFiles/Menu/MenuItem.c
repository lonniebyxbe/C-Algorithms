#include <stdio.h>

#include "Menu/MenuItem.h"

menu_item root;

void initialize(void)
{
	root.id = -1;
	root.description = "NULL";
	root.id_alias = "ROOT";
}

void add_main_menu_item(int id, char* description, char* alias)
{
	if (root.children == NULL)
	{

	}
	//root.children 
}

void add_child(int id, char* description, char* alias, menu_item item)
{

}