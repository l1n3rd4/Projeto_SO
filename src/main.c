#include <stdio.h>
#include <stdlib.h>

extern void core_run(FILE *input, FILE *output);

int main(int argc, char *argv[]){
	FILE *input, *output;

	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");

	if(input == NULL)
		goto error_input_file;

	if(output == NULL)
		goto error_output_file;

	core_run(input, output);

	fclose(input);
	fclose(output);

error_input_file:
	printf("e");

error_output_file:
	printf("2");

	return (0);
}
