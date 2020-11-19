#include "utils.h"

int isThere(int columnNumber, int **historic, int item){
  printf("teste\n");
    for(int i = 0; i < getLineSize() - 1; i++){
      if(historic[i][columnNumber] == item)
        return (i);
    }

    return (-1);
}

int areThereEmptySpaces(int columnNumber, int **historic, int item){
  for(int i = 0; i < getLineSize() - 1; i++){
    if(historic[i][columnNumber] == 0)
      return (i);
  }

  return (-1);
}

int indexFirstIncludedPage(page *pages){
  int lineDesired = 0;
  int first = 0;

  for(int i = 0; i < getLineSize() - 1; i++){
      if(i == 0){
        first = pages[i].firstInclude;
      } else if (first < pages[i].firstInclude){
        first = pages[i].firstInclude;
        lineDesired = i;
      }
    }

    return lineDesired;
}

int** copyLines(int** historic, int column){
  printf("testecopylines\n");
  if(column == 0){
    return (historic);
  }

  for(int i = 0; i < getLineSize() - 1; i++){
    historic[i][column] = historic[i][column - 1];
  }

  return (historic);
}
