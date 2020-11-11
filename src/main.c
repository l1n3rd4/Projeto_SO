#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

extern void core_run(FILE *input, FILE *output);

int main(int argc, char *argv[]){
	FILE *input, *output;

	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");

	if(input == NULL)
		goto error_input_file;

	if(output == NULL)
		goto error_output_file;

//	core_run(input, output);

	fclose(input);
	fclose(output);
	
	return(EXIT_SUCCESS);

error_input_file:
	printf("%s\n", ERROR_INPUT_MESSAGE);

error_output_file:
	printf("%s\n", ERROR_OUTPUT_MESSAGE);

	return (EXIT_FAILURE);
}
