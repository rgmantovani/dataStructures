#ifndef GraphLists_h
#define GraphLists_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//we will need our previous implementations of ordered lists
#include "OrderedList.h"

//---------------------------------------------------------
// Types
//---------------------------------------------------------

typedef struct
  int vertices;
  OrderedList *array;
  bool isDirected;
} GraphLists;


//---------------------------------------------------------
// Functions
//---------------------------------------------------------

void initGraphLists(GraphLists *graph, int V, bool isDirected);
void printGraphLists(GraphLists *graph);
bool insertEdgeGraphLists(GraphLists *graph, int v1, int v2);
bool removeEdgeGraphLists(GraphLists *graph, int v1, int v2);
bool isAdjacentGraphLists(GraphLists *graph, int v1, int v2);
OrderedList* getAdjacentsGraphLists(GraphLists *graph, int v);
void destroyGraphLists(GraphLists *graph);

#endif /* GraphLists_h */

//---------------------------------------------------------
//---------------------------------------------------------
