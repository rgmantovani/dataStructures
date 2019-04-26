#ifndef ArvoreBinaria_h
#define ArvoreBinaria_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Item;

typedef struct NoArvore *Ponteiro;

typedef struct NoArvore {
    Item elemento;
    Ponteiro esquerda;
    Ponteiro direita;
} NoArvore;

void iniciaArvore(Ponteiro *tree);
void destroiArvore(Ponteiro *tree);
void percursoPreOrdem(Ponteiro *tree);
void percursoPosOrdem(Ponteiro *tree);
void percursoEmOrdem(Ponteiro *tree);
bool insereItem(Ponteiro *tree, Item x);
bool procuraItem(Ponteiro *tree, int key, Item *ret);
bool estaVazia(Ponteiro *tree);
bool removeItem(Ponteiro *tree, int key, Item *ret);
Ponteiro maiorElemento(Ponteiro *tree);
Ponteiro menorElement(Ponteiro *tree);

#endif /* ArvoreBinaria_h */
