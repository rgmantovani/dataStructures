#ifndef GrafoMatrizes_h
#define GrafoMatrizes_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------
// Tipos
//---------------------------------------------------------

typedef struct {
  int vertices;
  int **matriz;
  bool direcionado;
} GrafoMatriz;

//---------------------------------------------------------
// Funções
//---------------------------------------------------------

void iniciaGrafoMatriz(GrafoMatriz *grafo, int V, bool direcionado);
void imprimeGrafoMatriz(GrafoMatriz *grafo);
bool insereArestaGrafoMatriz(GrafoMatriz *grafo, int v1, int v2);
bool removeArestaGrafoMatriz(GrafoMatriz *grafo, int v1, int v2);
bool verificaAdjacencia(GrafoMatriz *grafo, int v1, int v2);
int* retornarAdjacentes(GrafoMatriz *grafo, int v, int* cont);
void destruirGrafoMatriz(GrafoMatriz *grafo);

#endif /* GrafoMatrizes_h */

//---------------------------------------------------------
//---------------------------------------------------------
