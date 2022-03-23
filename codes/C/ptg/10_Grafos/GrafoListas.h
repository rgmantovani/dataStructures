#ifndef GrafoListas_h
#define GrafoListas_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//precisaremos da nossa implementação de lista ordenada
#include "ListaOrdenada.h"


//---------------------------------------------------------
// Tipos
//---------------------------------------------------------

typedef struct
  int vertices;
  ListaOrdenada *array;
  bool direcionado;
} GrafoListas;


//---------------------------------------------------------
// Funcoes
//---------------------------------------------------------

void iniciaGrafoListas(GrafoListas *grafo, int V, bool direcionado);
void imprimeGrafoListas(GrafoListas *grafo);
bool insereArestaGrafoListas(GrafoListas *grafo, int v1, int v2);
bool removeArestaGrafoListas(GrafoListas *grafo, int v1, int v2);
bool verificaAdjacenciaGrafoListas(GrafoListas *grafo, int v1, int v2);
ListaOrdenada* retornarAdjacentesGrafoListas(GrafoListas *grafo, int v);
void destroiGrafoListas(GrafoListas *grafo);

#endif /* GrafoListas_h */

//---------------------------------------------------------
//---------------------------------------------------------
