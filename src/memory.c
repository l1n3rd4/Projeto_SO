extern int getLineSize(void);
extern int getColumnSize(void);

int isThere(int columnNumber, int **historic, int item){
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
