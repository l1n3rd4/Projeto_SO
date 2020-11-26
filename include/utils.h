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

/**
 * @brief String displayed when the memory available is smaller than what the program requisite
 */

#define ERROR_INSUFFICIENT_MEMORY_MESSAGE "Insufficient memory"

/**
 * @brief String displayed when the input file cannot be open
 */

#define ERROR_INPUT_MESSAGE "Error opening input file"

/**
 * @brief String displayed when the output file cannot be open
 */

#define ERROR_OUTPUT_MESSAGE "Error opening output file"

/**
 * @brief Default int returned in functions where the desired value is not found
 */

#define NOT_FOUND_CODE -1

/**
 * @brief The structure that holds all informations about pages in memory
 */

typedef struct PAGE{
  int numberPage;
  int firstInclude;
  int timeWaitingRequisition;
}page;

/*Functions Declarations*/

/**
 * @returns the size of memory pages array
 */

extern int getLineSize(void);

/**
 * @brief Apply the Optimal(OPT) algorithm to decide which page should be replace
 *
 * @params requisitions array and matrix historic
 *
 * @returns the matrix historic
 */

extern page** OPT(page *pages, page **historic);

/**
 * @brief Apply the FIFO(First-in First-out) algorithm to decide which page should be replace
 *
 * @params requisitions array and matrix historic
 *
 * @returns the matrix historic
 */

extern page** FIFO(page *pages, page **historic);

/**
 * @brief Read a line of a file and separate in tokens
 *
 * @params File pointer and position in the file
 *
 * @returns the requisitions array
 */

extern int* readLine(FILE *input, long int position);

/**
 * @brief Write the historic matrix in a file
 *
 * @params the historic matrix and file pointer
 */

extern void saveHistoric(page **historic, FILE *output);

/**
 * @brief Writes the final result of an algorithm in a file
 *
 * @params File pointer
 */

extern void saveFinalReport(FILE *output);

/**
 * @brief Control the execution of the entire application
 *
 * @params Input file pointer and output file pointer
 */

extern void core_run(FILE *input, FILE *output);

/**
 * @returns the size of requisitions array
 */

extern int getColumnSize(void);

/**
 * @brief Verify if the requisite page is on memory
 *
 * @params the index of the requisition, matrix historic and requisite page
 *
 * @returns the index of the line where the requisite page is
 */

extern int isThere(int column, page **historic, int item);

/**
 * @brief Verify if there's empty spaces on memory
 *
 * @params the index of requisition and the historic matrix
 *
 * @returns the index of the line where is the empty space
 */

extern int areThereEmptySpaces(int column, page **historic);

/**
 * @brief Verify what page is the first include in the historic
 *
 * @params Historic matrix and the index of the requisition
 *
 * @returns the index of the line where the first included page is
 */

extern int indexFirstIncludedPage(page **historic, int column);

/**
 * @brief Copy the previous page of the memory
 *
 * @params The historic matrix and the index of the requisition
 *
 * @returns the historic matrix
 */

extern page** copyLines(page** historic, int column);

/**
 * @brief Alloc the dinamic memory needed for the historic matrix
 *
 * @params The historic matrix
 *
 * @returns the historic matrix
 */

extern page** initHistoric(page** historic);

/**
 * @brief Print in stdout the historic matrix
 *
 * @params The historic matrix
 */

extern void printPages(page** historic);

/**
 * @brief Read the size of the virtual memory from a file
 *
 * @params File pointer and position on the file
 *
 * @returns the size of the virtual memory pages
 */

extern int readSizeMemory(FILE *input, long int position);

/**
 * @brief Verify what is the page that will wait for more time until being called
 *
 * @params The historic matrix, requisition array and index of the requisition
 *
 * @returns The index of the page where should be replace
 */

extern int theLastPageRequisition(page **historic, page *pages, int column);

/**
 * @returns the number of hits after the execution of the algorithm
 */

extern int getHits(void);

/**
 * @returns the number of misses after the execution of the algorithm
 */

extern int getMisses(void);

/**
 * @returns the error rate after the execution of the algorithm
 */

extern float getErrorRate(void);

#endif
