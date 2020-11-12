#include <cstddef>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void readLine(FILE *input, long int position){
	char *line = NULL;
	char *token = NULL;
	size_t initial_size = 0;
	ssize_t array_size;
	fseek(input, position, SEEK_SET);
	
	array_size = getline(line, initial_size, input);
	line[array_size - 1] = '\0';
	int pages[array_size];	

	for(int i = 0; i < (array_size - 1); i++){
		pages[i] = (line[i] - '0');
		printf("%d", pages[i]);
	}

}
