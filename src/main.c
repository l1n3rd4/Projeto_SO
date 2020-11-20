#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[]){
	FILE *input, *output;

	input = fopen(argv[1], "r");

	if(input == NULL)
		goto error_input_file;

	output = fopen("saida.txt", "w");

	if(output == NULL)
		goto error_output_file;

	core_run(input, output);

	// fclose(input);
	fclose(output);

	return(EXIT_SUCCESS);

error_output_file:
	printf("%s\n", ERROR_OUTPUT_MESSAGE);
	// fclose(input);
	return (EXIT_FAILURE);

error_input_file:
	printf("%s\n", ERROR_INPUT_MESSAGE);
	return (EXIT_FAILURE);
}
