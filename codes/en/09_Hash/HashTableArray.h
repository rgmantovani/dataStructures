#ifndef HashTableArray_h
#define HashTableArray_h

# include <stdbool.h>
# include <stdio.h>

//---------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------

#define M 7 //23

typedef struct {
  int key;
  char info[100];
} HashTableItem;

typedef struct {
  HashTableItem* array[M];
  int numberOfElements;
} HashTableArray;

//---------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------

void initHashTableArray(HashTableArray *table);
int hashFunction(int key);
int increaseIndex(int i);
int sizeOfHashTableArray(HashTableArray *table);
bool isEmptyHashTableArray(HashTableArray *table);
bool isFullHashTableArray(HashTableArray *table);
bool insertHashTableArray(HashTableArray *table, HashTableItem *item);
bool removeHashTableArray(HashTableArray *table, int key);
bool searchHashTableArray(HashTableArray *table, int key, HashTableItem *item);
void printfHashTableArray(HashTableArray *table);
void destroyHashTableArray(HashTableArray *table);

#endif /* HashTableArray_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
