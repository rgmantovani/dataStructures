#ifndef hashTable_h
#define hashTable_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 23

typedef struct {
    char* data;
    int key;
} Item;

typedef struct {
  Item* hashArray[SIZE];
  int count;
} HashTable;

int hashCode(int key);
void initTable(HashTable* table);
void insertItem(HashTable *table, int key, char *data);
bool searchItem(HashTable *table, int key);
Item* removeItem(HashTable *table, int key);
void displayTable(HashTable *table);

#endif /* hashTable_h */
