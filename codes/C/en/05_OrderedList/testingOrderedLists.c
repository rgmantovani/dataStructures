//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "OrderedList.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int main(int argc, const char * argv[]) {

  OrderedList list;

  initOrderedList(&list);

  if(isEmptyOrderedList(&list)) {
    printf("The ordered list is empty\n");
  }

  printf("\n---------------------------\n");
  printf(" *** Testing: inserting elements \n");
  printf("---------------------------\n");

  insertOrderedList(&list, 1);
  printOrderedList(&list);
  insertOrderedList(&list, 20);
  printOrderedList(&list);
  insertOrderedList(&list, 33);
  printOrderedList(&list);
  insertOrderedList(&list, 44);
  printOrderedList(&list);
  insertOrderedList(&list, 57);
  printOrderedList(&list);
  insertOrderedList(&list, 60);
  printOrderedList(&list);
  insertOrderedList(&list, 2);
  printOrderedList(&list);
  insertOrderedList(&list, -1);
  printOrderedList(&list);

  printf("\n---------------------------\n");
  printf(" *** Testing: printing \n");
  printf("---------------------------\n");

  printOrderedList(&list);

  int tam = sizeOfOrderedList(&list);
  printf("Size of List: %d\n", tam);
  int first = firstOrderedList(&list);
  printf("First: %d\n", first);
  int last = lastOrderedList(&list);
  printf("Last: %d\n", last);

  printf("\n---------------------------\n");
  printf(" *** Testing: searching elements \n");
  printf("---------------------------\n");

  int queries[] = {20, 3, 4, 56, 77};
  for(int i = 0; i < 5; i++) {
    printf("Value %d was ...", queries[i]);
    if(searchOrderedList(&list, queries[i])) {
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
    removeOrderedList(&list, toRemove[i], &returned);
    printOrderedList(&list);
  }

  printf("\n---------------------------\n");
  destroyOrderedList(&list);
  printf("---------------------------\n");

  return 0;
}
