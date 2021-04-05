//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <stdio.h>
#include "hashTable.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void initTable(HashTable* table) {
  for(int i = 0; i < SIZE; i++) {
    table->hashArray[i] = NULL;
  }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

int hashCode(int key) {
  return (key % SIZE);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

bool searchItem(HashTable *table, int key) {

  int hashIndex = hashCode(key);
  
  if(table->hashArray[hashIndex] == NULL)
    return false;
  return(table->hashArray[hashIndex]->key == key);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void insertItem(HashTable *table, int key, char* data) {
  
  Object *item = (Object*) malloc(sizeof(Object));
  item->data = data;
  item->key = key;
  
  //get the hash
  int hashIndex = hashCode(key);
  printf("hash index: %d\n", hashIndex);
  
  if(table->hashArray[hashIndex] == NULL) {
    table->hashArray[hashIndex] = item;
    table->count = table->count + 1;
  } else {
    printf("Posição já preenchida: %d\n", hashIndex);
  }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

Object* removeItem(HashTable *table, int key) {
  
  int hashIndex = hashCode(key);
  Object* temp;
  
  if(table->hashArray[hashIndex]->key == key) {
    temp = table->hashArray[hashIndex];
    table->hashArray[hashIndex] = NULL;
    table->count = table->count - 1;
  } else {
    temp = NULL;
  }
  return (temp);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void displayTable(HashTable *table) {
  
  int i;
  printf("=============================\n");
  printf("           Table            \n");
  printf("=============================\n");

  for(i = 0; i < SIZE; i++) {
    
    if(table->hashArray[i] != NULL) {
      printf(" [%d](%d,%s)\n", i, table->hashArray[i]->key, table->hashArray[i]->data);
    } else {
      printf(" [%d] ~~ \n", i);
    }
  }
  printf("=============================\n");
}
