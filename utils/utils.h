
#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool isValidPositiveNumber(const char* str);
char* ConvertDecimalToBinary(unsigned int decimalNumber);
char* ConvertDecimalToOctal(unsigned int decimalNumber);
char* ConvertDecimalToHex(unsigned int decimalNumber);

#endif