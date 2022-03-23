//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "DoubleLinkedList.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
 
  DoubleLinkedList doublelist;
  
  initDoubleList(&doublelist);
  
  if(isEmptyDoubleList(&doublelist)) {
    printf("The double list is empty\n");
  }
  
  printf("\n---------------------------\n");
  printf(" *** Testing: inserting elements \n");
  printf("---------------------------\n");
  
  insertDoubleList(&doublelist, 1);
  insertDoubleList(&doublelist, 20);
  insertDoubleList(&doublelist, 33);
  insertDoubleList(&doublelist, 44);
  insertDoubleList(&doublelist, 57);
  insertDoubleList(&doublelist, 60);
  insertDoubleList(&doublelist, 2);
  insertDoubleList(&doublelist, -1);
  
  printf("\n---------------------------\n");
  printf(" *** Testing: printing \n");
  printf("---------------------------\n");
  
  printDoubleList(&doublelist);
  printReverseDoubleList(&doublelist);
  
  printf("\n---------------------------\n");
  printf(" *** Testing: searching elements \n");
  printf("---------------------------\n");

  int queries[] = {20, 3, 4, 56, 77};
  for(int i = 0; i < 5; i++) {
    printf("Value %d was ...", queries[i]);
    if(searchDoubleList(&doublelist, queries[i])) {
      printf(" found\n");
    } else {
      printf(" not found\n");
    }
  }
  
  printf("\n---------------------------\n");
  printf(" *** Testing: removing elements \n");
  printf("---------------------------\n");

  int toRemove[] = {57, 44, 29, 1, -1};
  int returned;
  
  for(int i = 0; i < 5; i++) {
    removeDoubleList(&doublelist, toRemove[i], &returned);
    printReverseDoubleList(&doublelist);
  }
  
  printf("\n---------------------------\n");
  destroyDoubleList(&doublelist);
  printf("---------------------------\n");
  
  return 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

