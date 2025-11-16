#include "menu_controller.h"
#include <stdio.h> 
#include <stdbool.h>

/*
	Esse arquivo é responsável por controlar os menus registrados no sistema.
	Através dele poderemos registrar novos menus e caminhar entre eles
*/

// Aqui vamos criar o "menuArray" que é o vetor que vai armazenar todos os menus registrados.
#define MAX_MENUS 100
struct MenuStruct menuArray[MAX_MENUS];

// Essa variavel é para ter controle de quantos menus já foram registrados, ela será util no for para saber quantas vezes iterar
int menuArrayCount = 0;

/*
      Essa é uma das funções principais, ela vai registrar o menu passado por parametro dentro do menuArray
      Esse menu registrado poderá ser invocado depois através da função InvokeMenu
*/
void RegisterMenu(struct MenuStruct menu) {
	if (menuArrayCount >= MAX_MENUS){
		printf("LIMITE DE MENU ATINGIDO! O MÁXIMO É %i", MAX_MENUS);
		return;
	}

	menuArray[menuArrayCount++] = menu;

	// Vamos fazer uma ordenação para colocar em ordem crescente a partir do "choice" do menu.
	int i = menuArrayCount - 1;
	while (i > 0 && menuArray[i - 1].choice > menuArray[i].choice) {
		struct MenuStruct temp = menuArray[i];
		menuArray[i] = menuArray[i - 1];
		menuArray[i - 1] = temp;
		i--;
	}
}

/*
	Esse menu será usado para caminhar entre os menus registrados e invocar o menu que o usuário escolheu
    Ou voltar quando ele digitar "back"
*/
void InvokeMenu(int choice) {
    struct MenuStruct menuItem;
    bool foundedMenu = false;

    for (int i = 0; i < menuArrayCount; i++) {

        struct MenuStruct currentMenu = menuArray[i];
        if (currentMenu.choice == choice) {
            menuItem = currentMenu;
            foundedMenu = true;
            break;
        }
    }

    if (!foundedMenu) {
        printf("Menu %i não encontrado\n", choice);
        return;
    }

    system("clear||cls");
    menuItem.method();
}
