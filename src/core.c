#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// libncurses

static void load(FILE *input);
static int menu(void);
static void execute(int option, page **historic);
static void flush(FILE *output, page **historic);

page *pages;
int line_size;
int column_size;
page **historic;

void core_run(FILE *input, FILE *output){
	line_size = 0;
	column_size = 0;
	int option = 0;

	load(input);
	initHistoric(historic);

	option = menu();

	execute(option, historic);
	flush(output, historic);

	for(int i = 0; i < line_size; i++)
		free(historic[i]);

	free(historic);
}

int getLineSize(void){
	return (line_size);
}

static void load(FILE *input){

	long int position = 0;
	int memory_size;
	int *IntPages;

	pages = calloc(getLineSize(), sizeof(*pages));
	IntPages = readLine(input, position);

	position = ftell(input);
	memory_size = readSizeMemory(input, position);

	line_size = memory_size;
	column_size = getColumnSize();

	for(int i = 0; i < getColumnSize(); i++){
		pages[i].numberPage = IntPages[i];
	}

	free(IntPages);
}

static int menu(void){
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

static void execute(int option, page **historic){
	switch (option) {
		case 0:
			exit(EXIT_SUCCESS);
		case 1:
			historic = OPT(pages, historic);
			break;
		case 2:
			historic = FIFO(pages, historic);
			break;
		default:
			printf("Invalid option! \n");
			exit(EXIT_FAILURE);
	}
}

static void flush(FILE *output, page** historic){
	saveHistoric(historic, output);
	saveFinalReport(output);
}
