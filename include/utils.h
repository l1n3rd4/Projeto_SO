#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define ERROR_INPUT_MESSAGE "Error opening input file"
#define ERROR_OUTPUT_MESSAGE "Error opening output file"

/*Global Variables*/
static int *pages;

/*Functions Declarations*/
static void load(FILE *input);
static void execute();
static void flush(FILE *output);

#endif
