//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "HashTableArray.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initHashTableArray(HashTableArray *table) {
  for(int i = 0; i < M; i++) {
    table->array[i] = NULL;
  }
  table->numberOfElements = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int hashFunction(int key) {
  return(key % M);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyHashTableArray(HashTableArray *table) {
  return(table->numberOfElements == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isFullHashTableArray(HashTableArray *table){
  return(table->numberOfElements == M);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfHashTableArray(HashTableArray *table) {
  return(table->numberOfElements);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int increaseIndex(int i) {
  int newValue = (i+1) % M;
  return newValue;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insertHashTableArray(HashTableArray *table, HashTableItem *item){
  
  if(!isFullHashTableArray(table)) {
    
    // finding the position to insert
    int pos = hashFunction(item->key);
      
    // look for a new position to keep inserting the element
    while(true) {
      if(table->array[pos] != NULL) {
        printf(" - Colision. Position %d is already occupied.\n", pos);
        pos = increaseIndex(pos);
      } else {
        table->array[pos] = item;
        table->numberOfElements++;
        return true;
      }
    }
  } else {
    printf(" - Warning: Table is full \n");
    return false;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeHashTableArray(HashTableArray *table, int key){
 
  if(isEmptyHashTableArray(table)) return false;
  
  // finding the position to remove
  int pos = hashFunction(key);
  if(table->array[pos] == NULL) return false;
  
  int counter = 1;
  
  // searching for the element in the table (colisions)
  while(counter <= M) {
    if(table->array[pos]!= NULL && table->array[pos]->key == key) {
      table->array[pos] = NULL;
      table->numberOfElements--;
      return true;
    } else {
      pos = increaseIndex(pos);
      counter++;
    }
  }
  return false;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool searchHashTableArray(HashTableArray *table, int key, HashTableItem *item) {

  if(isEmptyHashTableArray(table)) return false;
  
  // finding the position
  int pos = hashFunction(key);
  if(table->array[pos] == NULL) return false;

  int counter = 1;
  // searching for the element in the table (colisions)
  while(counter <= M) {
    if(table->array[pos]!= NULL && table->array[pos]->key == key) {
      *item = *(table->array[pos]);
      return true;
    } else {
      pos = increaseIndex(pos);
      counter++;
    }
  }
  return false;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printfHashTableArray(HashTableArray *table) {

  printf("=============================\n");
  printf("            Table            \n");
  printf("=============================\n");

  for(int i = 0; i < M; i++) {
      
  if(table->array[i] != NULL) {
    printf(" [%d](%d,%s)\n", i, table->array[i]->key, table->array[i]->info);
    } else {
      printf(" [%d] ~~ \n", i);
    }
  }
  printf("=============================\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyHashTableArray(HashTableArray *table) {
  for(int i = 0; i < M; i++) {
    table->array[i] = NULL;
  }
  table->numberOfElements = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
