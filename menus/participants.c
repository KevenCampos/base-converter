#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../utils/menu_controller.h"

static void ParticipantsMethod() {
    while (1) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Vamos utilizar a variavel userInput para armazenar a entrada do usuário como uma string de até 99 caracteres
        char userInput[100] = "";

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf(
            "---------------------------------------\n"
            "# Participantes do Grupo 2:\n"
            "# - Keven Xavier Campos\n"
            "# - Elton Reami\n"
            "# - Luana Alves Camilo\n"
            "# - Maisa Gomes Beatto\n"
            "# - Kauan De Freitas Neves\n"
            "# - Maria Eduarda Chaves Vieira\n"
            "---------------------------------------\n\n"
        );

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("Digite 'back' para voltar ao menu principal:\n");
        scanf_s("%99s", userInput, (unsigned)_countof(userInput));

        if (strcmp(userInput, "back") == 0) {
            InvokeMenu(-1);
            return;
        }
        else 
        {
            system("clear||cls");
        }
    }
}

void RegisterParticipantsMenu() {
    struct MenuStruct participantsMenu = {
        .name = "Lista de Participantes",
        .method = ParticipantsMethod,
        .choice = 3,
    };

    RegisterMenu(participantsMenu);
}
