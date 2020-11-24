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

/**
 * @returns the size of requisitions of array
 */

extern int getLineSize(void);

/**
 * @brief Apply the Optimal algorithm to decide which page should be replace
 *
 * @params requisitions array and matrix historic
 *
 * @returns the matrix historic
 */

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
