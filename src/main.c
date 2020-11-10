#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *DELIMITADOR = ",";
int readFile(FILE *input);

int main(int argc, char *argv[]){
	FILE *input, *output;


	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");

	readFile(input);

	fclose(input);
	fclose(output);

	return (0);
}


int readFile(FILE *input, long int position){
	char *linha = NULL;
	size_t inicio = 0;
	ssize_t tamanho = 0;
	char *token = NULL;

	while((tamanho = getline(&linha, &inicio, input)) != -1){
		linha[tamanho - 1] = '\0';
		token = strtok(linha, DELIMITADOR);

			while(token != NULL){
					token = strtok(NULL, DELIMITADOR);
					printf("%s", token);
			}

	}
}
