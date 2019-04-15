//
//  ListaDupla.h
//  DoubleLinkageList
//
//  Created by Rafael Gomes Mantovani on 15/04/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

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

void iniciaLista(DoubleLinkedList *list);
void imprimeLista(DoubleLinkedList *list);
void imprimeListaReversa(DoubleLinkedList *list);
void destroiLista(DoubleLinkedList *list);
bool insere(DoubleLinkedList *list, Item x);
bool estaVazia(DoubleLinkedList *list);
bool pesquisa(DoubleLinkedList *list, int key);
bool removeElemento(DoubleLinkedList *list, int key, Item *item);
bool removePrimeiro(DoubleLinkedList *list, Item *item);
bool removeUltimo(DoubleLinkedList *list, Item *item);
int tamanhoLista(DoubleLinkedList *list);
Item primeiro(DoubleLinkedList *list);
Item ultimo(DoubleLinkedList *list);

#endif /* ListaDupla_h */
