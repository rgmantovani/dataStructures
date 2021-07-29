#include <stdio.h>
#include "HashTableArray.h"

int main(int argc, const char * argv[]) {
  
  HashTableArray table;
  initHashTableArray(&table);
  printfHashTableArray(&table);
  
  HashTableItem obj1 = {5, "Batima"};
  insertHashTableArray(&table, &obj1);
  printfHashTableArray(&table);

  HashTableItem obj2 = {0, "Doente verde"};
  insertHashTableArray(&table, &obj2);
  printfHashTableArray(&table);

  HashTableItem obj3 = {03, "Aranha-aranha"};
  insertHashTableArray(&table, &obj3);
  printfHashTableArray(&table);

  HashTableItem obj4 = {14, "Formiga-homem"};
  insertHashTableArray(&table, &obj4);
  printfHashTableArray(&table);

  HashTableItem obj5 = {21, "Felix-gato"};
  insertHashTableArray(&table, &obj5);
  printfHashTableArray(&table);
  
  printf("Tamanho da Tabela = %d\n", sizeOfHashTableArray(&table));
  
  HashTableItem query;
  int values[] = {0, 3, 2};
  
  for(int i = 0; i < 3; i++) {
    if(searchHashTableArray(&table, values[i], &query)) {
      printf(" [?](%d,%s)\n", query.key, query.info);
    } else {
      printf("Element was not found\n");
    }
  }

  removeHashTableArray(&table, 2);
  removeHashTableArray(&table, 3);
  removeHashTableArray(&table, 14);
  printfHashTableArray(&table);

  destroyHashTableArray(&table);
  if(isEmptyHashTableArray(&table)) {
    printf("Table was destroyed\n");
  }
  printf("=============================\n");
  
  return 0;
}
