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
      printf("Page %d\n", (*(historic + address) + j)->numberPage);
      printf("teste first %d\n", (*(historic + address) + j)->firstInclude);
      misses++;
    }else {
      misses++;
      lineDesired = indexFirstIncludedPage(historic, j);
      (*(historic + lineDesired) + j)->numberPage = pages[j].numberPage;
      (*(historic + lineDesired) + j)->firstInclude = j;
    }

    printf("pre HIst\n");
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
      printf("Page %d\n", (*(historic + address) + j)->numberPage);
      printf("teste first %d\n", (*(historic + address) + j)->firstInclude);
      misses++;
    }else {
      misses++;
      lineDesired = indexFirstIncludedPage(historic, j);
      (*(historic + lineDesired) + j)->numberPage = pages[j].numberPage;
      (*(historic + lineDesired) + j)->firstInclude = j;
    }

    printf("pre HIst\n");
    historic = copyLines(historic, (j + 1));
  }

  return (historic);
}

int getHits(void){
  return (hits);
}

int getMisses(void){
  return (misses);
}

float getErrorRate(void){
  return ((1.0 * misses)/getColumnSize());
}
