#include "utils.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/**
    Função para verificar se uma determinada string representa um número válido.
*/
bool isValidPositiveNumber(const char* str) {

    // Caso a variavel seja nula, retorna falso
    if (!str) return false;

    // Caso a string esteja vazia, retorna falso
    if (*str == '\0') return false;

    /**
        Aqui vamos iterar sobre cada caractere da string "str" para verificar se todos são dígitos.
        Se encontrarmos algum caractere que não seja um dígito, retornamos falso.

        O Loop será encerrado quando encontrarmos o caractere nulo '\0', que indica o fim da string.
    */
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return false;
        }
    }

    // All characters were digits and string wasn't empty
    return true;
}

char* ConvertDecimalToBinary(unsigned int decimalNumber) {
    static char buffer[64]; // buffer temporário
    int i = 0;

    if (decimalNumber == 0) {
        strcpy(buffer, "0");
        return buffer;
    }

    while (decimalNumber > 0 && i < 63) {
        buffer[i++] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
    }

    buffer[i] = '\0'; // finaliza string

    // inverter string (porque o binário sai de trás pra frente)
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return buffer;
}

char* ConvertDecimalToOctal(unsigned int decimalNumber) {
    static char buffer[64]; // buffer temporário
    int i = 0;

    if (decimalNumber == 0) {
        strcpy(buffer, "0");
        return buffer;
    }

    while (decimalNumber > 0 && i < 63) {
        buffer[i++] = (decimalNumber % 8) + '0';
        decimalNumber /= 8;
    }

    buffer[i] = '\0';

    // inverter string
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return buffer;
}

char* ConvertDecimalToHex(unsigned int decimalNumber) {
    static char buffer[64]; // buffer temporário
    int i = 0;
    char hexDigits[] = "0123456789ABCDEF";

    if (decimalNumber == 0) {
        strcpy(buffer, "0");
        return buffer;
    }

    while (decimalNumber > 0 && i < 63) {
        buffer[i++] = hexDigits[decimalNumber % 16];
        decimalNumber /= 16;
    }

    buffer[i] = '\0';

    // inverter string
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return buffer;
}
