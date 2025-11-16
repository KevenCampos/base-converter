#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include "../utils/menu_controller.h"
#include "../utils/cache.h"

static void HistoryMethod() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Vamos utilizar a variavel userInput para armazenar a entrada do usuário como uma string de até 99 caracteres
    char userInput[100] = "";

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf(
        "---------------------------------------\n"
        "# Histórico de processamentos\n"
        "# Quantidade de ciclos: %i\n"
        "---------------------------------------\n\n",
        processingCount
    );
      

    for (int i = 1; i <= processingCount; i++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        ProcessingData current = numberProcessingHistory[i];
        printf("# Processamento %d (%i entradas):\n", i, current.inputVectorLength);

        for (int j = 0; j < current.inputVectorLength; j++) {
            switch (current.conversionType) {
                case BINARY:
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("Decimal %u -> Numero em Binario: %s\n", (unsigned int)current.vectorDecimalInputs[j], current.vectorConvertedInputs[j]);                    break;
                case OCTAL:
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                    printf("Decimal %u -> Numero em Octal: %s\n", (unsigned int)current.vectorDecimalInputs[j], current.vectorConvertedInputs[j]);                    break;
                    break;
				case HEXADECIMAL:
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    printf("Decimal %u -> Numero em Hexadecimal: %s\n", (unsigned int)current.vectorDecimalInputs[j], current.vectorConvertedInputs[j]);                    break;
                    break;
                default:
                    printf("Tipo de conversao desconhecido para a entrada %d\n", j + 1);
					break;
            }
        }
        printf("\n");
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\nDigite 'back' para voltar ao menu principal:\n");
    scanf_s("%99s", userInput, (unsigned)_countof(userInput));

    if (strcmp(userInput, "back") == 0) {
        InvokeMenu(-1);
        return;
    }
    else
    {
        system("clear||cls");
    }
    return;
}


void RegisterHistoryMenu() {
    struct MenuStruct menu = {
        .name = "Histórico",
        .method = HistoryMethod,
        .choice = 2,
    };

    RegisterMenu(menu);
}