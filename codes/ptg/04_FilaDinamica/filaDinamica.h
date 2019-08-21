//
//  filaDinamica.h
//  DynamicQueue
//
//  Created by Rafael Gomes Mantovani on 03/04/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef filaDinamica_h
#define filaDinamica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chave;
  /* outros componentes */
} Item;

typedef struct NoFila *Ponteiro;

typedef struct NoFila{
  Item item;
  Ponteiro proximo;
} NoFila;

typedef struct {
  Ponteiro inicio;
  Ponteiro fim;
  int tamanho;
} FilaDinamica;

void iniciaFila(FilaDinamica *fila);
void enfileira(Item x, FilaDinamica *fila);
void desenfileira(FilaDinamica *fila, Item *x);
void imprimeFila(FilaDinamica *fila);
int estaVazia(FilaDinamica *fila);
int tamanhoFila(FilaDinamica *fila);
Item inicioFila(FilaDinamica *fila);
Item fimFila(FilaDinamica *fila);

#endif /* filaDinamica_h */
