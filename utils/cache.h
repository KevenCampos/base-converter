#ifndef CACHE_H
#define CACHE_H

#define MAX_PROCESSING_CICLE 40
#define MAX_PROCESSING_HISTORY_BY_CICLE 20
#define MAX_STRING_LENGTH 64

typedef enum { BINARY, HEXADECIMAL, OCTAL } ConversionType;

typedef struct {
    int inputVectorLength;
    unsigned int vectorDecimalInputs[MAX_PROCESSING_HISTORY_BY_CICLE];
	char vectorConvertedInputs[MAX_PROCESSING_HISTORY_BY_CICLE][MAX_STRING_LENGTH];
    ConversionType conversionType;
} ProcessingData;

// Variáveis globais
extern ProcessingData numberProcessingHistory[MAX_PROCESSING_CICLE];
extern int processingCount;

// Funções globais
void AddHistoryEntry(unsigned int number);
void InitializeNewProcessing(void);
ProcessingData* GetCurrentProcessingData(void);

#endif // CACHE_H
