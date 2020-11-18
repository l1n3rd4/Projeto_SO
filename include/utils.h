#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define ERROR_INPUT_MESSAGE "Error opening input file"
#define ERROR_OUTPUT_MESSAGE "Error opening output file"

typedef struct PAGE{
  int numberPage;
  int firstInclude;
}page;

/*Functions Declarations*/
extern int getLineSize(void);
extern int** OPT(page *pages, int **historic);
extern int** FIFO(page *pages, int **historic);
extern int* readLine(FILE *input, long int position);
extern void saveHistoric(int **historic, FILE *output, int line, int column);
extern void saveFinalReport(FILE *output, int hits, int misses, int totalRequisitions, float errorRate);
extern void core_run(FILE *input, FILE *output);
extern int getLineSize(void);
extern int getColumnSize(void);
extern int isThere(int columnNumber, int **historic, int item);
extern int areThereEmptySpaces(int columnNumber, int **historic, int item);
extern int indexFirstIncludedPage(page *pages);

#endif


// Perguntas
// variáveis globais
// exit ?
// erros main
