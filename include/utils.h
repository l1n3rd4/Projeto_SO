#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define ERROR_INSUFFICIENT_MEMORY_MESSAGE "Insufficient memory"
#define ERROR_INPUT_MESSAGE "Error opening input file"
#define ERROR_OUTPUT_MESSAGE "Error opening output file"
#define NOT_FOUND_CODE -1

typedef struct PAGE{
  int numberPage;
  int firstInclude;
  int timeWaitingRequisition;
}page;

/*Functions Declarations*/
extern int getLineSize(void);
extern page** OPT(page *pages, page **historic);
extern page** FIFO(page *pages, page **historic);
extern int* readLine(FILE *input, long int position);
extern void saveHistoric(page **historic, FILE *output);
extern void saveFinalReport(FILE *output);
extern void core_run(FILE *input, FILE *output);
extern int getLineSize(void);
extern int getColumnSize(void);
extern int isThere(int column, page **historic, int item);
extern int areThereEmptySpaces(int column, page **historic);
extern int indexFirstIncludedPage(page **historic, int column);
extern page** copyLines(page** historic, int column);
extern page** initHistoric(page** historic);
extern void printPages(page** historic);
extern int readSizeMemory(FILE *input, long int position);
extern int theLastPageRequisition(page **historic, page *pages, int column);
extern int getHits(void);
extern int getMisses(void);
extern float getErrorRate(void);

#endif
