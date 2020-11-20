#include "utils.h"

int hits = 0;
int misses = 0;
float errorRate = 0;

page** OPT(page *pages, page **historic){
  int address = 0;
  int lineDesired;

  for(int j = 0;j < getColumnSize(); j++){
    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (address = areThereEmptySpaces(j, historic, pages[j].numberPage) != -1){
      historic[address][j].numberPage = pages[j].numberPage;
      misses++;
    } else {
      misses++;
      lineDesired = theLastPageRequisition(historic, pages, j);
      historic[lineDesired][j].numberPage = pages[j].numberPage;
      historic[lineDesired][j].firstInclude = j;
    }
  }
  return (historic);
}

page** FIFO(page *pages, page **historic){
  int address = 0;
  int lineDesired;

  for(int j = 1; j < getColumnSize(); j++){

    if(j != 0){
      historic = copyLines(historic, j);
    }

    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (address = areThereEmptySpaces(j, historic, pages[j].numberPage) != -1){
      historic[address][j].numberPage = pages[j].numberPage;
      historic[address][j].firstInclude = j;
      misses++;
    } else {
      misses++;
      lineDesired = indexFirstIncludedPage(historic, j);
      historic[lineDesired][j].numberPage = pages[j].numberPage;
      historic[address][j].firstInclude = j;
    }
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
  return (misses/getColumnSize());
}
