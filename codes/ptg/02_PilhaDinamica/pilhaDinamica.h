#ifndef PilhaDinamica_h
#define PilhaDinamica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha{
    int x;
    PtrNoPilha proximo;
} NoPilha;

typedef struct {
    PtrNoPilha topo;
    int tamanho;
} PilhaDinamica;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaPilhaDinamica(PilhaDinamica *pilha);
bool estaVaziaPilhaDinamica(PilhaDinamica *pilha);
void empilhaPilhaDinamica(PilhaDinamica *pilha, int x);
void desempilhaPilhaDinamica(PilhaDinamica *pilha, int *x);
int tamanhoPilhaDinamica(PilhaDinamica *pilha);
void topoPilhaDinamica(PilhaDinamica *pilha, int *x);
void imprimePilhaDinamica(PilhaDinamica *pilha);
void destroiPilhaDinamica(PilhaDinamica *pilha);
void destroiPilhaDinamica2(PilhaDinamica *pilha);

#endif /* PilhaDinamica_h */
