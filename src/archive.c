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
	ssize_t bufferSize = 0;
	int *sequence;
	fseek(input, position, SEEK_SET);

	bufferSize = getline(&line, &initial_size, input);
	printf("buffer antes do getline %d\n", bufferSize);
	printf("Tamanho %d\n", array_size);

	line[array_size - 1] = '\0';

	sequence = calloc(array_size, sizeof(*sequence));
	token = strtok(line, DELIMITER);

	while(token != NULL){
		sequence[counter] = atoi(token);
		printf("readLine: %d\n", sequence[counter]);
		token = strtok(NULL, DELIMITER);
		counter++;
	}

	if(position == 0){
		array_size = bufferSize;
		array_size = array_size / 2;
	}

	printf("buffer %d\n", bufferSize);
	printf("array_size %d\n", array_size);
	printf("gugu %d\n", sequence[0]);
	return sequence;
}

int getLineSize(void){
	return array_size;
}


int readSizeMemory(FILE *input, long int position){
	int size;

	fseek(input, position, SEEK_SET);
	fscanf(input, "%d", &size);

	return (size);
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
