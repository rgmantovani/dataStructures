#ifndef ListaOrdenada_h
#define ListaOrdenada_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
  int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Item elemento;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int tamanho;
} Lista;

void iniciaLista(Lista *list);
void inserir(Lista *list, Objeto x);
void imprimirLista(Lista *list);
void destruirLista(Lista *list);
bool estaVazia(Lista *list);
bool pesquisar(Lista *list, int key);
int tamanhoLista(Lista *list);
void removeElemento(Lista *list, int chave, Objeto *item);
void removePrimeiro(Lista *list, Objeto *item);
void removeUltimo(Lista *list, Objeto *item);
Objeto primeiro(Lista *list);
Objeto ultimo(Lista *list);

#endif /* ListaOrdenada_h */
