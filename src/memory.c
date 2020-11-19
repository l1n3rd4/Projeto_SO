#include <stdlib.h>
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
  for(int i = 0; i < getLineSize() - 1; i++){
    historic[i][column] = historic[i][column - 1];
  }

  printf("testecopylines\n");
  return (historic);
}

int** initHistoric(int** historic){

	historic = (int **) malloc(getLineSize() * sizeof(int*));
  printf("initHistoric \n");

	if (historic == NULL){
		printf("** Erro: Memoria Insuficiente **");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < getColumnSize(); i++ ){
		historic[i] = (int*) malloc(getColumnSize() * sizeof(int));

		if (historic[i] == NULL){
			printf("** Erro: Memoria Insuficiente **");
			exit(EXIT_FAILURE);
		}
	}

	printf("Alocado\n");

  for(int i = 0; i < getLineSize() - 1; i++){
    for(int j = 0; j < getColumnSize() - 1; j++){
      historic[i][j] = 0;
    }
  }

  return (historic);
}

void exibe(int** historic){
  for(int i = 0; i < getLineSize() - 1; i++){
    for(int j = 0; j < getColumnSize() - 1; j++){
      printf("%d\n", historic[i][j] = 0);
    }
  }
}
