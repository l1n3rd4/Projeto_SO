/*
 * MIT License
 *
 * Copyright(c) 2020 Leonardo Henrique Guimaraes <leonardo.guimaraeslhg@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// libncurses

static void load(FILE *input);
static int menu(void);
static void execute(int option, page **historic);
static void flush(FILE *output, page **historic);

page *pages = NULL;
int line_size;
int column_size;
page **historic = NULL;

// controls the execution flow of the entire application
void core_run(FILE *input, FILE *output){
	line_size = 0;
	column_size = 0;
	int option = 0;

	load(input);
	historic = initHistoric(historic);

	option = menu();

	execute(option, historic);
	flush(output, historic);

	// for(int i = 0; i < line_size; i++)
	// 	free(historic + i);
	//
	// free(historic);
}

// Returns the size of requisitions array
int getLineSize(void){
	return (line_size);
}

// Loads the requisition array
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
		(pages + i) -> numberPage = IntPages[i];
	}

	free(IntPages);
}

// Display a simple message to choose the page replacement algorithm
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

// calls the chosen page replacement algorithm
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

// Calls functions that save the final data in a file
static void flush(FILE *output, page** historic){
	saveHistoric(historic, output);
	saveFinalReport(output);
}
