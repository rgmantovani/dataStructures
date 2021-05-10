#include "GrafoMatrizes.h"

//---------------------------------------------------------
//---------------------------------------------------------

void iniciaGrafoMatriz(GrafoMatriz *grafo, int V, bool direcionado){
  
  int i, j;
  grafo->direcionado = direcionado;
  grafo->vertices = V;

  // matrix memmory allocation
  grafo->matriz = malloc (grafo->vertices * sizeof (int*)) ;
  for (i=0; i < grafo->vertices; i++) {
    grafo->matriz[i] = malloc(grafo->vertices * sizeof (int)) ;
  }

  // initialize matrix with 0s
  for(i = 0; i < grafo->vertices; i++) {
    for(j = 0; j < grafo->vertices; j++) {
      grafo->matriz[i][j] = 0;
    }
  }
}

//---------------------------------------------------------
//---------------------------------------------------------
void imprimeGrafoMatriz(GrafoMatriz *grafo) {
  
  printf("---------------\n");
  printf(" *** grafo *** \n");
  printf("---------------\n");
  
  printf("\t ");
  for(int k = 0; k < grafo->vertices; k++) {
    printf("%d ", k);
  }
  printf("\n");
  
  for(int i =0; i < grafo->vertices; i++) {
    printf("%d: | ", i);
    for(int j = 0; j < grafo->vertices; j++) {
      printf("%d ", grafo->matriz[i][j]);
    }
    printf("\n");
  }
  printf("---------------\n");
}

//---------------------------------------------------------
//---------------------------------------------------------
bool insereArestaGrafoMatriz(GrafoMatriz *grafo, int v1, int v2) {
  
  if(v1 >= 0 && v1 < grafo->vertices &&
     v2 >= 0 && v2 < grafo->vertices) {
    grafo->matriz[v1][v2] = 1;
    if(!grafo->direcionado) {
      grafo->matriz[v2][v1] = 1;
    }
    return true;
  }
  return false;
}

//---------------------------------------------------------
//---------------------------------------------------------

bool removeArestaGrafoMatriz(GrafoMatriz *grafo, int v1, int v2) {
  if(v1 >= 0 && v1 < grafo->vertices &&
     v2 >= 0 && v2 < grafo->vertices) {
    grafo->matriz[v1][v2] = 0;
    if(!grafo->direcionado) {
      grafo->matriz[v2][v1] = 0;
    }
    return true;
  }
  return false;
}

//---------------------------------------------------------
//---------------------------------------------------------

bool verificaAdjacencia(GrafoMatriz *grafo, int v1, int v2) {
    return (v1 >= 0 && v1 < grafo->vertices &&
     v2 >= 0 && v2 < grafo->vertices &&
     grafo->matriz[v1][v2] == 1);
}

//---------------------------------------------------------
//---------------------------------------------------------

int* retornarAdjacentes(GrafoMatriz *grafo, int v, int* cont) {
  
  int *array = NULL;
  int i;

  (*cont) = 0;
  if(v >=0 && v < grafo->vertices) {
  
    for(i = 0; i < grafo->vertices; i++) {
      if(grafo->matriz[v][i] == 1) {
        (*cont)++;
      }
    }
    
    if(*cont > 0) {
      array = (int*) malloc ((*cont) * sizeof (int));
    }
    
    (*cont) = 0;
    for(i = 0; i < grafo->vertices; i++) {
      if(grafo->matriz[v][i] == 1) {
        array[(*cont)] = i;
        (*cont)++;
      }
    }
  }
  return(array);
}

//---------------------------------------------------------
//---------------------------------------------------------

void destruirGrafoMatriz(GrafoMatriz *grafo) {
  for (int i = 0; i < grafo->vertices; i++) {
     free(grafo->matriz[i]) ;
  }
  free(grafo->matriz);
}

//---------------------------------------------------------
//---------------------------------------------------------
