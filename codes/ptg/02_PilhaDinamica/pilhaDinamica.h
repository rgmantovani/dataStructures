
#ifndef pilhaDinamica_h
#define pilhaDinamica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha{
  Objeto obj;
  PtrNoPilha proximo;
} NoPilha;

typedef struct {
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica;

void iniciaPilha(PilhaDinamica *p);
bool estaVazia(PilhaDinamica *p);
void empilha(Objeto obj, PilhaDinamica *p);
void desempilha(PilhaDinamica *p, Objeto *obj);
int tamanhoPilha(PilhaDinamica *p);
void topo(PilhaDinamica *p, Objeto *obj);
void imprimePilha(PilhaDinamica *p);

#endif /* pilhaDinamica_h */
