#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include "../utils/menu_controller.h"

static void MainMenuMethod() {
    while (true) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        int choice;

        // Configura o programa para usar a localidade do sistema
        setlocale(LC_ALL, "pt_BR");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf(
            "-------------------------------------------------------\n"
            "# Trabalho de Algoritimo I \n"
            "# Professor: Alex Adrihel Barreira De Souza\n"
            "# Grupo 2\n"
            "-------------------------------------------------------\n\n"
        );

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		printf("> MENU PRINCIPAL\n\n");

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for (int i = 0; i < menuArrayCount; i++) {
            if (menuArray[i].choice > 0) {
                printf("[%d] - %s\n", menuArray[i].choice, menuArray[i].name);
            }
        }

        printf("[0] - Sair\n\n");
        printf("Escolha uma opção: \n");
        scanf_s("%d", &choice);

        if (choice == 0){
            // close window
			exit(0);
            break;
        }

        bool found = 0;
        for (int i = 0; i < menuArrayCount; i++) {
            if (menuArray[i].choice == choice) {
                system("clear||cls");
                menuArray[i].method();
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Opção inválida!\n");
        }

        break;
    }
}


void RegisterMainMenu() {
    struct MenuStruct menu = {
		.name = "Menu Principal",
        .method = MainMenuMethod,
		.choice = -1
    };

    RegisterMenu(menu);
}