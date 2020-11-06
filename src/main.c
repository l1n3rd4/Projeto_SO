#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *input, *output;
	
	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");



	fclose(input);
	fclose(output);
}
