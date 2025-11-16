#include "./cache.h"

ProcessingData numberProcessingHistory[MAX_PROCESSING_CICLE];
int processingCount = 0;

/*
	Essa função uma entrada (decimal) e adiciona essa entrada no histórico do processamento atual
	Quando trocamos o ciclo de processamento, um novo histórico é iniciado através do "InitializeNewProcessing" e as entradas passam a ser armazenadas nesse novo ciclo
*/
void AddHistoryEntry(unsigned int number) {
    ProcessingData* current = &numberProcessingHistory[processingCount];
    int index = current->inputVectorLength;

    if (index >= MAX_PROCESSING_HISTORY_BY_CICLE) {
        printf("Histórico cheio!\n");
        return;
    }

    current->vectorDecimalInputs[index] = number;
    current->inputVectorLength++;
}

/*
	Aqui nós definimos o início de um novo ciclo de processamento, criando um novo histórico para armazenar as entradas convertidas
    Dessa forma conseguimos diferenciar os ciclos no histórico
*/
void InitializeNewProcessing() {
    
    if (processingCount + 1 >= MAX_PROCESSING_CICLE) {
		printf("Número máximo de ciclos de processamento atingi do!\n");
		return;
	}

	processingCount++;
    numberProcessingHistory[processingCount].inputVectorLength = 0;
}

/*
	GetCurrentProcessingData retorna um ponteiro para o histórico de processamento atual
	O Ponteiro foi feito para permitir a modificação direta dos dados do histórico atual
*/
ProcessingData* GetCurrentProcessingData(void) {
	return &numberProcessingHistory[processingCount];
}