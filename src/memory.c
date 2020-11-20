#include <stdlib.h>
#include "utils.h"

int isThere(int columnNumber, int **historic, int item){
    for(int i = 0; i < getLineSize(); i++){
      printf("columnNumber %d\n", columnNumber);
      printf("%d\n", historic);
      if(historic[i][columnNumber] == item)
        return (i);
    }

    return (-1);
}

int areThereEmptySpaces(int columnNumber, int **historic, int item){
  for(int i = 0; i < getLineSize(); i++){
    if(historic[i][columnNumber] == 0)
      return (i);
  }

  return (-1);
}

int indexFirstIncludedPage(page *pages){
  int lineDesired = 0;
  int first = 0;

  for(int i = 0; i < getLineSize(); i++){
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
  for(int i = 0; i < getLineSize(); i++){
    historic[i][column] = historic[i][column - 1];
  }

  return (historic);
}

int** initHistoric(int** historic){
	historic = (int **) calloc(getLineSize(), sizeof(int*));

	if (historic == NULL){
		printf("** Erro: Memoria Insuficiente **");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < getColumnSize(); i++ ){
		historic[i] = (int*) calloc(getColumnSize(), sizeof(int));

		if (historic[i] == NULL){
			printf("** Erro: Memoria Insuficiente **");
			exit(EXIT_FAILURE);
		}
	}

  return (historic);
}

void exibe(int **historic){
  printf("exibe line %d\n", getLineSize());
  printf("exibe coluna %d\n", getColumnSize());

  for(int i = 0; i < getLineSize(); i++){
    for(int j = 0; j < getColumnSize(); j++){
       printf("%d ", historic[i][j]);
    }

    //*(*(historic + i) + j)
    printf("\n");
  }
}
