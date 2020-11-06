#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *input, *output;
	char *linha = NULL;
	size_t inicio = 0;
	ssize_t tamanho = 0;

	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");
	
	while((tamanho = getline(&linha, &inicio, input)) != -1){
		linha[tamanho - 1] = '\0';
		fprintf(output, "%s\n", linha);
	}
	

	fclose(input);
	fclose(output);

	return (0);
}
