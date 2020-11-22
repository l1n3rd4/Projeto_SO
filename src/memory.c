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

#include <stdlib.h>
#include "utils.h"

int isThere(int column, page **historic, int item){
    for(int i = 0; i < getLineSize(); i++){
      if((*(historic + i) + column)->numberPage == item)
        return (i);
    }

    return (NOT_FOUND_CODE);
}

int areThereEmptySpaces(int column, page **historic){
  for(int i = 0; i < getLineSize(); i++){
    if((*(historic + i) + column)->numberPage == 0)
      return (i);
  }

  return (NOT_FOUND_CODE);
}

int indexFirstIncludedPage(page **historic, int column){
  int lineDesired = 0;
  int first = 0;

  for(int i = 0; i < getLineSize(); i++){
      if(i == 0 || first > ((*(historic + i) + column)->firstInclude)){
        first = (*(historic + i) + column)->firstInclude;
        lineDesired = i;
      }
    }

    return lineDesired;
}

page** copyLines(page** historic, int column){
  for(int i = 0; i <= getLineSize(); i++){
    (*(historic + i) + column)->numberPage  = (*(historic + i) + (column - 1))->numberPage;
    (*(historic + i) + column)->firstInclude = (*(historic + i) + (column - 1))->firstInclude;
    (*(historic + i) + column)->timeWaitingRequisition = (*(historic + i) + (column - 1))->timeWaitingRequisition;
  }
  return (historic);
}

page** initHistoric(page** historic){
	historic = (page **) calloc(getLineSize(), sizeof(page*));

	if (historic == NULL){
		printf("%s\n", ERROR_INSUFFICIENT_MEMORY_MESSAGE);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < getColumnSize(); i++){
		historic[i] = (page *) calloc(getColumnSize(), sizeof(page));

		if ((historic + i) == NULL){
			printf("%s\n", ERROR_INSUFFICIENT_MEMORY_MESSAGE);
			exit(EXIT_FAILURE);
		}
	}

  for(int i = 0; i < getLineSize(); i++){
    for(int j = 0; j < getColumnSize(); j++){
       (*(historic + i) + j)->numberPage = 0;
    }
  }

  return (historic);
}

void printPages(page **historic){
  for(int i = 0; i < getLineSize(); i++){
    for(int j = 0; j < getColumnSize(); j++){
       printf("%d ", (*(historic + i) + j)->numberPage);
    }

    printf("\n");
  }
}

int theLastPageRequisition(page **historic, page *pages, int column){
  int count = column;
  int major = 0;
  int lineDesired = 0;

  for(int i = 0; i < getLineSize(); i++){
    while(pages[count].numberPage != (*(historic + i) + column)->numberPage && count < getColumnSize()){
      count++;
    }

    (*(historic + i) + column)->timeWaitingRequisition = count;
    count = column;
  }

  for(int i = 0; i < getLineSize(); i++){
    if(i == 0){
      major = (*(historic + i) + column)->timeWaitingRequisition;
    } else if(major < (*(historic + i) + column)->timeWaitingRequisition){
      major = (*(historic + i) + column)->timeWaitingRequisition;
      lineDesired = i;
    }
  }


  return (lineDesired);
}
