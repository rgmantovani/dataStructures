#ifndef GraphMatrix_h
#define GraphMatrix_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------
// Types
//---------------------------------------------------------

typedef struct {
  int vertices;
  int **matrix;
  bool isDirected;
} GraphMatrix;

//---------------------------------------------------------
// Functions
//---------------------------------------------------------

void initGraphMatrix(GraphMatrix *graph, int V, bool isDirected);
void printGraphMatrix(GraphMatrix *graph);
bool insertEdgeGraphMatrix(GraphMatrix *graph, int v1, int v2);
bool removeEdgeGraphMatrix(GraphMatrix *graph, int v1, int v2);
bool isAdjacent(GraphMatrix *graph, int v1, int v2);
int* getAdjacents(GraphMatrix *graph, int v, int* cont);
void destroyGraphMatrix(GraphMatrix *graph);

#endif /* GraphMatrix_h */

//---------------------------------------------------------
//---------------------------------------------------------
