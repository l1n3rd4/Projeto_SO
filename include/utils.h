#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define ERROR_INPUT_MESSAGE "Error opening input file"
#define ERROR_OUTPUT_MESSAGE "Error opening output file"

/*Functions Declarations*/
extern int getLineSize(void);
extern int** OPT(int *pages, int **historic);
extern int** FIFO(int *pages, int **historic);
extern int* readLine(FILE *input, long int position);
extern void saveHistoric(int **historic, FILE *output, int line, int column);
extern void saveFinalReport(FILE *output, int hits, int misses, int totalRequisitions, float errorRate);
extern void core_run(FILE *input, FILE *output);
extern int getLineSize(void);
extern int getColumnSize(void);

#endif


// Perguntas
// variáveis globais
// exit ?
// erros main
