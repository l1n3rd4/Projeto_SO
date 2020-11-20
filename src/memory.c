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
