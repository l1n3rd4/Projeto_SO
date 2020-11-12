#include <stdio.h>
#include "utils.h"

extern int* readLine(FILE *input, long int position);
static int *pages;

void core_run(FILE *input, FILE *output){		
	load(input);
	execute();
	flush();
}


static void load(FILE *input){
	long int position = 0;
        pages = readLine(input, position);
}


static void execute(){}

static void flush(){}
