#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

extern int* readLine(FILE *input, long int position);
extern void saveHistoric(int **historic, FILE *output, int line, int column);
extern void saveFinalReport(FILE *output, int hits, int misses, int totalRequisitions, float errorRate);

void core_run(FILE *input, FILE *output){
	load(input);
	execute();
	flush(output);
}

static void load(FILE *input){
	long int position = 0;
        pages = readLine(input, position);
}

static void execute(){
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

static void flush(FILE *output){}
