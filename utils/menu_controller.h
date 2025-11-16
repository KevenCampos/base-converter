#ifndef MENU_REGISTRY_H
#define MENU_REGISTRY_H

struct MenuStruct {
	const char* name; // O Nome do menu
	void (*method)(); // O Metodo que será invocado quando o usuário escolher esse menu
	int choice; // A escolha do menu
};

void InvokeMenu(int choice);
void RegisterMenu(struct MenuStruct menu);
extern struct MenuStruct menuArray[];
extern int menuArrayCount;

#endif