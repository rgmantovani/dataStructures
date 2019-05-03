//  pilhaEstatica.h
//  Stacks


#ifndef pilhaEstatica_h
#define pilhaEstatica_h

#include <stdio.h>

#define MAXTAM 100

/* tipo abstrato para item, que será inserido na pilha */
typedef struct {
  int chave;
  /* podemos adicionar mais coisas aqui */
} Item;

/* tipo abstrato de pilha */
typedef struct {
  Item array[MAXTAM];
  int topo;
} pilhaEstatica;


/* funções de manipulação */
void iniciaPilha(pilhaEstatica *pilha);
int estaVazia(pilhaEstatica *pilha);
int estaCheia(pilhaEstatica *pilha) ;
void empilha(Item item, pilhaEstatica *pilha);
void desempilha(Item *item, pilhaEstatica *pilha);
int tamanhoPilha(pilhaEstatica *pilha);
Item topo(pilhaEstatica *pilha);
void imprimePilha(pilhaEstatica *pilha);

#endif /* pilhaEstatica_h */
