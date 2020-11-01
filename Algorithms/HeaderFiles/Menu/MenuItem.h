typedef struct menu_item menu_item;
typedef menu_item* menu_item_ptr;

struct menu_item
{
	char* description;
	char* id_alias;
	int id;
	menu_item_ptr children;
};

void initialize(void);
void add_main_menu_item(int id, char* description, char* alias);
void add_child(int id, char* description, char* alias, menu_item item);