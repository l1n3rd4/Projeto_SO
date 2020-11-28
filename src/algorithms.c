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

#include "utils.h"

int hits = 0;
int misses = 0;
float errorRate = 0;

page** OPT(page *pages, page **historic){
  int address = 0;
  int lineDesired;

  for(int j = 0; j < getColumnSize(); j++){
    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (areThereEmptySpaces(j, historic) != -1){
      address = areThereEmptySpaces(j, historic);
      (*(historic + address) + j)->numberPage = pages[j].numberPage;
      (*(historic + address) + j)->firstInclude = j;
      misses++;
    }else {
      misses++;
      lineDesired = theLastPageRequisition(historic, pages, j);
      (*(historic + lineDesired) + j)->numberPage = pages[j].numberPage;
      (*(historic + lineDesired) + j)->firstInclude = j;
    }

    historic = copyLines(historic, (j + 1));
  }

  return (historic);
}

page** FIFO(page *pages, page **historic){
  int address = 0;
  int lineDesired;

  for(int j = 0; j < getColumnSize(); j++){
    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (areThereEmptySpaces(j, historic) != -1){
      address = areThereEmptySpaces(j, historic);
      (*(historic + address) + j)->numberPage = pages[j].numberPage;
      (*(historic + address) + j)->firstInclude = j;
      misses++;
    }else {
      misses++;
      lineDesired = indexFirstIncludedPage(historic, j);
      (*(historic + lineDesired) + j)->numberPage = pages[j].numberPage;
      (*(historic + lineDesired) + j)->firstInclude = j;
    }

    historic = copyLines(historic, (j + 1));
  }

  return (historic);
}

//Returns the number of hits
int getHits(void){
  return (hits);
}

// Returns the number of misses
int getMisses(void){
  return (misses);
}

// Returns error rate of executed algorithm
float getErrorRate(void){
  return ((1.0 * misses)/getColumnSize());
}
