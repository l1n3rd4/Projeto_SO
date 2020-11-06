#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *DELIMITADOR = ",";

int main(int argc, char *argv[]){
	FILE *input, *output;
	char *linha = NULL;
	size_t inicio = 0;
	ssize_t tamanho = 0;
	char *token = NULL;
	int count = 0;

	input = fopen(argv[1], "r");
	output = fopen("saida.txt", "w");

	while((tamanho = getline(&linha, &inicio, input)) != -1){
		linha[tamanho - 1] = '\0';
		token = strtok(linha, DELIMITADOR);
		
		if(count == 0){
			while(token != NULL){
				fprintf(output, "%s", token);
                                token = strtok(NULL, DELIMITADOR);
			}
			count++;
		} else if(count == 1){
			fprintf(output, "\n%s", linha);
			count = 0;
		}
	}


	fclose(input);
	fclose(output);

	return (0);
}
