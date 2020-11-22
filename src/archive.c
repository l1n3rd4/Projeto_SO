/*
 * MIT License
 *
 * Copyright(c) 2020 Leonardo Henrique Guimaraes <leonardo.guimaraeslhg@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

const char *DELIMITER = ",";
ssize_t array_size;

int *readLine(FILE *input, long int position){
	char *line = NULL;
	char *token = NULL;
	size_t initial_size = 0;
	int counter = 0;
	int *sequence;
	fseek(input, position, SEEK_SET);

	array_size = getline(&line, &initial_size, input);
	line[array_size - 1] = '\0';

	sequence = calloc(array_size, sizeof(*sequence));
	token = strtok(line, DELIMITER);

	while(token != NULL){
		sequence[counter] = atoi(token);
		token = strtok(NULL, DELIMITER);
		counter++;
	}

	array_size = array_size / 2;
	return sequence;
}

int getColumnSize(void){
	return array_size;
}


int readSizeMemory(FILE *input, long int position){
	int size;

	fseek(input, position, SEEK_SET);
	fscanf(input, "%d", &size);

	return (size);
}

void saveHistoric(page **historic, FILE *output){
	fprintf(output, "EVOLUCAO\n");

	for(int i = 0; i < getLineSize(); i++){
		for(int j = 0; j < getColumnSize(); j++){
			if(i < getLineSize() && (*(historic + i) + j)->numberPage == 0){
				fprintf(output, "  ");
			} else {
				fprintf(output, "%d ", (*(historic + i) + j)->numberPage);
			}
		}

		fprintf(output, "\n");
	}
}

void saveFinalReport(FILE *output){
	fprintf(output, "ACERTOS \n%d\n", getHits());
	fprintf(output, "ERROS \n%d\n" , getMisses());
	fprintf(output, "TOTAL REQUISICOES \n%d\n", getColumnSize());
	fprintf(output, "TAXA DE ERRO \n%.2f\n", getErrorRate());
}
