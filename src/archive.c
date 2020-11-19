#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

const char *DELIMITER = ",";
ssize_t array_size;
//colocar caractere de nova linha

int *readLine(FILE *input, long int position){
	char *line = NULL;
	char *token = NULL;
	size_t initial_size = 0;
	int counter = 0;
	fseek(input, position, SEEK_SET);

	array_size = getline(&line, &initial_size, input);

	line[array_size - 1] = '\0';
	int *sequence = (int*) calloc(array_size, sizeof(*sequence));
	token = strtok(line, DELIMITER);


	while(token != NULL){
		sequence[counter] = atoi(token);
		token = strtok(NULL, DELIMITER);
		counter++;
	}

	return sequence;
}

int getLineSize(void){
	return array_size;
}

void saveHistoric(int **historic, FILE *output){
	fprintf(output, "EVOLUCAO");

	for(int i = 0; i < getLineSize() - 1; i++){
		for(int j = 0; j < getColumnSize() - 1; j++){
			fprintf(output, "%d ", historic[i][j]);
		}

		fprintf(output, "\n");
	}
}

void saveFinalReport(FILE *output, int hits, int misses, int totalRequisitions, float errorRate){
	fprintf(output, "ACERTOS \n%d", hits);
	fprintf(output, "ERROS \n%d" , misses);
	fprintf(output, "TOTAL REQUISICOES \n%d", totalRequisitions);
	fprintf(output, "TAXA DE ERRO \n%f", errorRate);
}
