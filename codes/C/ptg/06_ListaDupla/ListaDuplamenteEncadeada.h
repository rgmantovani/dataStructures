#ifndef ListaDuplamenteEncadeada_h
#define ListaDuplamenteEncadeada_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    int elemento;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int tamanho;
} ListaDupla;

//---------------------------------------------------------------------------------
// Funções
//---------------------------------------------------------------------------------

void iniciaListaDupla(ListaDupla *lista);
void imprimeListaDupla(ListaDupla *lista);
void imprimeListaDuplaReverso(ListaDupla *lista);
void destroiListaDupla(ListaDupla *lista);
bool insereListaDupla(ListaDupla *lista, int x);
bool estaVaziaListaDupla(ListaDupla *lista);
bool procuraListaDupla(ListaDupla *lista, int x);
bool removeListaDupla(ListaDupla *lista, int x, int *item);
bool removePrimeiroListaDupla(ListaDupla *lista, int *item);
bool removeUltimoListaDupla(ListaDupla *lista, int *item);
int tamanhoListaDupla(ListaDupla *lista);
int primeiroListaDupla(ListaDupla *lista);
int ultimoListaDupla(ListaDupla *lista);

#endif /* ListaDuplamenteEncadeada_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
