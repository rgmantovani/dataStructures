//
//  pilhaDinamica.h
//  DynamicStack
//
//  Created by Rafael Gomes Mantovani on 28/03/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef pilhaDinamica_h
#define pilhaDinamica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    /* outros componentes */
} Item;

typedef struct NoPilha *Ponteiro;

typedef struct NoPilha{
    Item item;
    Ponteiro proximo;
} NoPilha;

typedef struct {
    Ponteiro topo;
    int tamanho;
} pilhaDinamica;

void iniciaPilha(pilhaDinamica *pilha);
int estaVazia(pilhaDinamica *pilha);
void empilha(Item item, pilhaDinamica *pilha);
void desempilha(pilhaDinamica *pilha, Item *item);
int tamanhoPilha(pilhaDinamica *pilha);
void topo(pilhaDinamica *pilha, Item *item);
void imprimePilha(pilhaDinamica *pilha);

#endif /* pilhaDinamica_h */
