//
//  filaEstatica.h
//  staticQueue
//
//  Created by Rafael Gomes Mantovani on 28/03/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef filaEstatica_h
#define filaEstatica_h

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM  5

typedef struct {
  int chave;
    /* outros componentes */
} Item;

typedef struct {
  Item array[MAXTAM];
  int tamanho;
  int inicio;
  int fim;
} FilaEstatica;

void iniciaFila(FilaEstatica *fila);
int estaVazia(FilaEstatica *fila);
int estaCheia(FilaEstatica *fila);
int tamanhoFila(FilaEstatica *fila);
int incrementaIndice(int i);
void enfileira(Item x, FilaEstatica *fila);
void desenfileira(FilaEstatica *fila, Item *x);
void imprimeFila(FilaEstatica *fila);
Item inicioFila(FilaEstatica *fila);
Item fimFila(FilaEstatica *fila);

#endif /* filaEstatica_h */
