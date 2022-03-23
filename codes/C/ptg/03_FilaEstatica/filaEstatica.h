#ifndef FilaEstatica_h
#define FilaEstatica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

#define MAXTAM  5

typedef struct {
  int vetor[MAXTAM];
  int tamanho;
  int inicio;
  int fim;
} FilaEstatica;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaFilaEstatica(FilaEstatica *fila);
void enfileiraFilaEstatica(FilaEstatica *fila, int x);
void imprimeFilaEstatica(FilaEstatica *fila);
bool estaVaziaFilaEstatica(FilaEstatica *fila);
bool estaCheiaFilaEstatica(FilaEstatica *fila);
int tamanhoFilaEstatica(FilaEstatica *fila);
int incrementaIndice(int i);
int desenfileiraFilaEstatica(FilaEstatica *fila);
int primeiroFilaEstatica(FilaEstatica *fila);
int ultimoFilaEstatica(FilaEstatica *fila);

#endif /* FilaEstatica_h */
