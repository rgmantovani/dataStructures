//
//  ListaDupla.h
//  Created by Rafael Gomes Mantovani on 15/04/19.

#ifndef ListaDupla_h
#define ListaDupla_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct  {
    int chave;
} Item;

typedef struct NoLista *Ponteiro;

typedef struct NoLista {
    Item elemento;
    Ponteiro proximo;
    Ponteito anterior;
} NoLista;

typedef struct {
    Ponteiro primeiro;
    int tamanho;
} ListaDupla;

void iniciaLista(ListaDupla *list);
void imprimeLista(ListaDupla *list);
void imprimeListaReversa(ListaDupla *list);
void destroiLista(ListaDupla *list);
bool insere(ListaDupla *list, Item x);
bool estaVazia(ListaDupla *list);
bool pesquisa(ListaDupla *list, int key);
bool removeElemento(ListaDupla *list, int key, Item *item);
bool removePrimeiro(ListaDupla *list, Item *item);
bool removeUltimo(ListaDupla *list, Item *item);
int tamanhoLista(ListaDupla *list);
Item primeiro(ListaDupla *list);
Item ultimo(ListaDupla *list);

#endif /* ListaDupla_h */
