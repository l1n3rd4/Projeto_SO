#include "utils.h"

int** OPT(page *pages, int **historic){
  int address = 0;
  int hits = 0;
  int misses = 0;
  int lineDesired;
  
  for(int j = 0;j < getColumnSize(); j++){
    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (address = areThereEmptySpaces(j, historic, pages[j].numberPage) != -1){
      historic[address][j] = pages[j].numberPage;
      misses++;
    } else {
      misses++;
    }
  }
  return (historic);
}
// ele está lá ?
//Se não, há espaços em brancos ?
//se não, Qual é o ?

int** FIFO(page *pages, int **historic){
  int address = 0;
  int hits = 0;
  int misses = 0;
  int lineDesired;

  for(int j = 0; j < getColumnSize(); j++){
    if(isThere(j, historic, pages[j].numberPage) != -1){
      hits++;
    } else if (address = areThereEmptySpaces(j, historic, pages[j].numberPage) != -1){
      historic[address][j] = pages[j].numberPage;
      misses++;
    } else {
      misses++;
      lineDesired = indexFirstIncludedPage(pages);
      historic[lineDesired][j] = pages[j].numberPage;
    }

  }

  return (historic);
}

// ele está lá ?
//Se não, há espaços em brancos ?
//se não, Qual é o primeiro elemento inserido ?
