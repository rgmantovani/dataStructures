#ifndef ListaOrdenada_h
#define ListaOrdenada_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
  int x;
  PtrNoLista proximo;
} NoLista;

typedef struct {
  PtrNoLista inicio;
  int tamanho;
} ListaOrdenada;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaListaOrdenada(ListaOrdenada *lista);
void insereListaOrdenada(ListaOrdenada *lista, int x);
void imprimeListaOrdenada(ListaOrdenada *lista);
void destroiListaOrdenada(ListaOrdenada *lista);
bool estaVaziaListaOrdenada(ListaOrdenada *lista);
bool pesquisaListaOrdenada(ListaOrdenada *lista, int x);
bool pesquisaOtimizadaListaOrdenada(ListaOrdenada *lista, int x);
int tamanhoListaOrdenada(ListaOrdenada *lista);
void removeListaOrdenada(ListaOrdenada *lista, int key, int *x);
void removePrimeiroListaOrdenada(ListaOrdenada *lista, int *x);
void removeUltimoListaOrdenada(ListaOrdenada *lista, int *x);
int primeiroListaOrdenada(ListaOrdenada *lista);
int ultimoListaOrdenada(ListaOrdenada *lista);

#endif /* ListaOrdenada_h */
