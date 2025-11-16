#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/menu_controller.h"
#include "../utils/cache.h"
#include "../utils/utils.h"

int max_input_numbers;

static void ProcessingMethod() {
	// Vamos utilizar avariavel userInput para armazenar a entrada do usuário como uma string de até 99 caracteres
    char userInput[100] = "";

    printf("Quantos numeros voce deseja inserir? ('back' para voltar)\n");
    while (1)
    {

	    // Lê a entrada do usuário como uma string e armazena em userInput
        scanf_s("%99s", userInput, (unsigned)_countof(userInput));

        if (strcmp(userInput, "back") == 0) {
            InvokeMenu(-1);
            return;
        }

        // Vamos validar se o usuário digitou um numero válido
        if (!isValidPositiveNumber(userInput)) {
            printf("Quantidade invalida. Utilize apenas numeros positivos\n");
            continue;
        }

        // Converte a string validada para um número inteiro
        max_input_numbers = atoi(userInput);

        if (max_input_numbers <= 0 || max_input_numbers > MAX_PROCESSING_HISTORY_BY_CICLE) {
            printf("Quantidade invalida. Utilize um numero entre 1 e %d\n", MAX_PROCESSING_HISTORY_BY_CICLE);
            continue;
        }

        break;
    }

    // Vamos inicializar um novo ciclo de processamento, para armazenar no historico de forma organizada.
    InitializeNewProcessing();
    system("clear||cls");

    for (int i = 0; i < max_input_numbers; i++) {
        printf("Digite um numero ou escreva 'back' para voltar [%d/%d]: ", i + 1, max_input_numbers);
        scanf_s("%99s", userInput, (unsigned)_countof(userInput));

        if (strcmp(userInput, "back") == 0) {
            InvokeMenu(-1);
            break;
        }

        if (!isValidPositiveNumber(userInput)) {
            printf("Entrada invalida. Digite um numero positivo valido.\n");
            i--;
            continue;
        }

        unsigned int number = (unsigned int)strtoul(userInput, NULL, 10);
        if (number == ULONG_MAX) {
            printf("Numero muito grande. Tente novamente.\n");
            i--;
            continue;
		}

        AddHistoryEntry(number);
        printf("Numero valido: %d\n", number);
    }

    ProcessingData* currentProcessing = GetCurrentProcessingData();

    while (1) {
        system("clear||cls");
        printf("# Para qual unidade você deseja converter ?\n");
        printf("[1] Binario\n");
        printf("[2] Octal\n");
        printf("[3] Hexadecimal\n");

        printf("Digite um numero ou escreva 'back' para voltar: ");
        scanf_s("%99s", userInput, (unsigned)_countof(userInput));

        // verifica se digitou "back"
        if (strcmp(userInput, "back") == 0) {
            InvokeMenu(-1);
            return;
        }

        int option = atoi(userInput);

        switch (option) {
        case 1:
            currentProcessing->conversionType = BINARY;
            break;
        case 2:
            currentProcessing->conversionType = OCTAL;
            break;
        case 3:
            currentProcessing->conversionType = HEXADECIMAL;
            break;
        default:
            continue; 
        }

        break;
    }

    for (int i = 0; i < currentProcessing->inputVectorLength; i++) {

        int decimalNumber = currentProcessing->vectorDecimalInputs[i];
        char* convertString;

        if (currentProcessing->conversionType == BINARY)
            convertString = ConvertDecimalToBinary(decimalNumber);
        else if (currentProcessing->conversionType == OCTAL)
            convertString = ConvertDecimalToOctal(decimalNumber);
        else
            convertString = ConvertDecimalToHex(decimalNumber);

        if (convertString != NULL) {
            strcpy_s(currentProcessing->vectorConvertedInputs[i],
                sizeof(currentProcessing->vectorConvertedInputs[i]),
                convertString);
        }
        else {
            printf("Erro ao converter número %d\n", decimalNumber);
        }
    }

    const char* typeStr = (currentProcessing->conversionType == BINARY) ? "Binario" :
        (currentProcessing->conversionType == OCTAL) ? "Octal" : "Hexadecimal";


    while (1) {
		system("clear||cls");
        printf("# Resultados da conversao para %s:\n", typeStr);
        printf("tamanho do vetor: %d\n", currentProcessing->inputVectorLength);
        for (int i = 0; i < currentProcessing->inputVectorLength; i++) {
            printf("Decimal: %d -> %s: %s\n",
                currentProcessing->vectorDecimalInputs[i],
                typeStr,
                currentProcessing->vectorConvertedInputs[i]);
        }

        printf("\nConversao concluida. Digite 'back' para voltar\n");
        scanf_s("%99s", userInput, (unsigned)_countof(userInput));

        if (strcmp(userInput, "back") == 0) {
            InvokeMenu(-1);
            return;
        }
    }
}

void RegisterProcessingMenu() {
    struct MenuStruct menu = {
        .name = "Processamento",
        .method = ProcessingMethod,
        .choice = 1,
    };

    RegisterMenu(menu);
}
