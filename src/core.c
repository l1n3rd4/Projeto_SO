#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

extern int* readLine(FILE *input, long int position);
extern void saveHistoric(int **historic, FILE *output, int line, int column);
extern void saveFinalReport(FILE *output, int hits, int misses, int totalRequisitions, float errorRate);
extern int getArraySize();
const int *pages;

void core_run(FILE *input, FILE *output){
	int option = 0;
	int **historic;

	load(input);
	option = menu();
	printf("%d\n", pages[1]);

	execute(option);
	flush(output);
}

static int** load(FILE *input){
	long int position = 0;
	int column_size;
	int line_size;
	int **historic;
	int *memory_size = NULL;

	pages = readLine(input, position);
	position = ftell(input);
	memory_size = readLine(input, position);
	line_size = memory_size[0];
	column_size = getArraySize();

	historic = (int**) calloc(line_size, sizeof(**historic));

	for(int i = 0; i < column_size - 1; i++)
		historic[i] = (int*) calloc(column_size, sizeof(**historic));

	return (historic);
}

static int menu(){
	int option = 0;

	printf("\n\n");
	printf("\t\t\t ________________________________ \n");
	printf("\t\t\t|Choose from the options below:  |\n");
	printf("\t\t\t|0 - Exit -----------------------|\n");
	printf("\t\t\t|1 - OPT ------------------------|\n");
	printf("\t\t\t|2 - FIFO -----------------------|\n");
	printf("\t\t\t -------------------------------- \n");

	printf("Answer: ");
	scanf("%d", &option);

	return (option);
}

static void execute(int option){
	switch (option) {
		case 0:
			exit(EXIT_SUCCESS);
		case 1:
//			OPT();
			break;
		case 2:
//			FIFO();
			break;
		default:
			printf("Invalid option! \n");
			exit(EXIT_FAILURE);
	}

}

static void flush(FILE *output){
//      saveHistoric(output);
//	saveFinalReport(output);
}
