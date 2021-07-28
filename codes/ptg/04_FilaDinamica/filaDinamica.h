#ifndef FilaDinamica_h
#define FilaDinamica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
  int x;
  PtrNoFila proximo;
} NoFila;

typedef struct {
  PtrNoFila inicio;
  PtrNoFila fim;
  int tamanho;
} FilaDinamica;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaFilaDinamica(FilaDinamica *fila);
void enfileiraFilaDinamica(FilaDinamica *fila, int x);
void desenfileiraFilaDinamica(FilaDinamica *fila, int *x);
void imprimeFilaDinamica(FilaDinamica *fila);
void destroiFilaDinamica(FilaDinamica *fila);
bool estaVaziaFilaDinamica(FilaDinamica *fila);
int tamanhoFilaDinamica(FilaDinamica *fila);
int primeiroFilaDinamica(FilaDinamica *fila);
int ultimoFilaDinamica(FilaDinamica *fila);

#endif /* FilaDinamica_h */
