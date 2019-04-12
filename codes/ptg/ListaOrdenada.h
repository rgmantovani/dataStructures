//
//  ListaOrdenada.h
//  Lists
//
//  Created by Rafael Gomes Mantovani on 12/04/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef ListaOrdenada_h
#define ListaOrdenada_h

#include <stdio.h>
#include <stdlib.h>

typedef struct  {
  int chave;
} Item;

typedef struct NoLista *Ponteiro;

typedef struct NoLista {
    Item elemento;
    Ponteiro proximo;
} NoLista;

typedef struct {
    Ponteiro primeiro;
    int tamanho;
} Lista;

void iniciaLista(Lista *list);
void inserir(Lista *list, Item x);
void imprimirLista(Lista *list);
void destruirLista(Lista *list);
int estaVazia(Lista *list);
int pesquisar(Lista *list, int key);
int tamanhoLista(Lista *list);
void removeElemento(Lista *list, int chave, Item *item);
void removePrimeiro(Lista *list, Item *item);
void removeUltimo(Lista *list, Item *item);
Item primeiro(Lista *list);
Item ultimo(Lista *list);

#endif /* ListaOrdenada_h */
