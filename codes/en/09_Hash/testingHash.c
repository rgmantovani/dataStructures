
#include <stdio.h>
#include "hashTable.h"

int main(int argc, const char * argv[]) {
  
  HashTable table;
  initTable(&table);

  insertItem(&table, 1, "andre");
  insertItem(&table, 2, "rafael");
  insertItem(&table, 42, "luiz");
  insertItem(&table, 567, "tamara");
  insertItem(&table, 12, "barreto");
  insertItem(&table, 14, "lucio");
  insertItem(&table, 17, "erinaldo");
  insertItem(&table, 26, "muriel");
  insertItem(&table, 13, "éeeeeee");
//
  displayTable(&table);

  int tofind[] = {2,26,13,14,17,4,5,50,60,70};
//
  for(int i = 0; i < 10; i++) {
    if(searchItem(&table, tofind[i])) {
      printf("Element found: %d\n", tofind[i]);
    } else {
      printf("Element not found: %d\n", tofind[i]);
    }
  }

  removeItem(&table, 42);
  removeItem(&table, 17);

  displayTable(&table);

}
