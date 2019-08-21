
#ifndef pilhaDinamica_h
#define pilhaDinamica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoPilha *Ponteiro;

typedef struct NoPilha{
  Objeto obj;
  Ponteiro proximo;
} NoPilha;

typedef struct {
  Ponteiro topo;
  int tamanho;
} pilhaDinamica;

void iniciaPilha(pilhaDinamica *pilha);
int estaVazia(pilhaDinamica *pilha);
void empilha(Objeto obj, pilhaDinamica *pilha);
void desempilha(pilhaDinamica *pilha, Objeto *obj);
int tamanhoPilha(pilhaDinamica *pilha);
void topo(pilhaDinamica *pilha, Objeto *obj);
void imprimePilha(pilhaDinamica *pilha);

#endif /* pilhaDinamica_h */
