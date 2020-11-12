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
