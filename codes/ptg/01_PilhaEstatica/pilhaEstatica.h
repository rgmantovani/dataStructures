#ifndef PilhaEstatica_h
#define PilhaEstatica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

#define MAXTAM 100

typedef struct {
    int vetor[MAXTAM];
    int topo;
} PilhaEstatica;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaPilhaEstatica(PilhaEstatica *pilha);
bool estaVaziaPilhaEstatica(PilhaEstatica *pilha);
bool estaCheiaPilhaEstatica(PilhaEstatica *pilha);
void empilhaPilhaEstatica(PilhaEstatica *pilha, int x);
void desempilhaPilhaEstatica(PilhaEstatica *pilha, int *x);
int tamanhoPilhaEstatica(PilhaEstatica *pilha);
int topoPilhaEstatica(PilhaEstatica *pilha);
void imprimePilhaEstatica(PilhaEstatica *pilha);

#endif /* PilhaEstatica_h */
