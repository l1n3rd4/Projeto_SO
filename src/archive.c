#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

const char *DELIMITER = ",";

int *readLine(FILE *input, long int position){
	char *line = NULL;
	char *token = NULL;
	size_t initial_size = 0;
	ssize_t array_size;
	int counter = 0;
	fseek(input, position, SEEK_SET);

	array_size = getline(&line, &initial_size, input);


	line[array_size - 1] = '\0';
	int *pages = (int*) calloc(array_size, sizeof(*pages));
	token = strtok(line, DELIMITER);


	while(token != NULL){
		pages[counter] = atoi(token);
		token = strtok(NULL, DELIMITER);
		counter++;
	}

	return pages;
}

void saveHistoric(int **historic, FILE *output, int column, int line){
	fprintf(output, "EVOLUCAO");

	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
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
