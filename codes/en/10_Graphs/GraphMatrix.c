
#include "GraphMatrix.h"

//---------------------------------------------------------
//---------------------------------------------------------

void initGraphMatrix(GraphMatrix *graph, int V, bool isDirected) {
  
  int i, j;
  
  graph->isDirected = isDirected;
  graph->vertices = V;

  // matrix memmory allocation
  graph->matrix = malloc (graph->vertices * sizeof (int*)) ;
  for (i=0; i < graph->vertices; i++) {
    graph->matrix[i] = malloc (graph->vertices * sizeof (int)) ;
  }

  // initialize matrix with 0s
  for(i = 0; i < graph->vertices; i++) {
    for(j = 0; j < graph->vertices; j++) {
      graph->matrix[i][j] = 0;
    }
  }
}

//---------------------------------------------------------
// imprime
//---------------------------------------------------------
void printGraphMatrix(GraphMatrix *graph) {
  
  printf("---------------\n");
  printf(" *** graph *** \n");
  printf("---------------\n");
  
  printf("\t ");
  for(int k = 0; k < graph->vertices; k++) {
    printf("%d ", k);
  }
  printf("\n");
  
  for(int i =0; i < graph->vertices; i++) {
    printf("%d: | ", i);
    for(int j = 0; j < graph->vertices; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
  printf("---------------\n");
}

//---------------------------------------------------------
//---------------------------------------------------------

bool insertEdgeGraphMatrix(GraphMatrix *graph, int v1, int v2) {\
  
  if(v1 >= 0 && v1 < graph->vertices &&
     v2 >= 0 && v2 < graph->vertices) {
    graph->matrix[v1][v2] = 1;
    if(!graph->isDirected) {
      graph->matrix[v2][v1] = 1;
    }
    return true;
  }
  return false;
}

//---------------------------------------------------------
//---------------------------------------------------------
bool removeEdgeGraphMatrix(GraphMatrix *graph, int v1, int v2) {

  if(v1 >= 0 && v1 < graph->vertices &&
     v2 >= 0 && v2 < graph->vertices) {
    graph->matrix[v1][v2] = 0;
    if(!graph->isDirected) {
      graph->matrix[v2][v1] = 0;
    }
    return true;
  }
  return false;
}

//---------------------------------------------------------
//---------------------------------------------------------

bool isAdjacent(GraphMatrix *graph, int v1, int v2) {
    return (v1 >= 0 && v1 < graph->vertices &&
     v2 >= 0 && v2 < graph->vertices &&
     graph->matrix[v1][v2] == 1);
}

//---------------------------------------------------------
//---------------------------------------------------------

int* getAdjacents(GraphMatrix *graph, int v, int* cont) {
  
  int *array = NULL;
  int i;

  (*cont) = 0;
  if(v >=0 && v < graph->vertices) {
  
    for(i = 0; i < graph->vertices; i++) {
      if(graph->matrix[v][i] == 1) {
        (*cont)++;
      }
    }
    
    if(*cont > 0) {
      array = (int*) malloc ((*cont) * sizeof (int));
    }
    
    (*cont) = 0;
    for(i = 0; i < graph->vertices; i++) {
      if(graph->matrix[v][i] == 1) {
        array[(*cont)] = i;
        (*cont)++;
      }
    }
  }
  return(array);
}

//---------------------------------------------------------
//---------------------------------------------------------

void destroyGraphMatrix(GraphMatrix *graph) {
  for (int i = 0; i < graph->vertices; i++) {
     free(graph->matrix[i]) ;
  }
  free(graph->matrix);
}

//---------------------------------------------
//---------------------------------------------
