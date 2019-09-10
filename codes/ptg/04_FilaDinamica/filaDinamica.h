#ifndef filaDinamica_h
#define filaDinamica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chave;
  /* outros componentes */
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
  Objeto obj;
  PtrNoFila proximo;
} NoFila;

typedef struct {
  PtrNoFila inicio;
  PtrNoFila fim;
  int tamanho;
} FilaDinamica;

void iniciaFila(FilaDinamica *fila);
void imprimeFila(FilaDinamica *fila);
void enfileira(Objeto x, FilaDinamica *fila);
void desenfileira(FilaDinamica *fila, Objeto *x);
//Objeto desenfileira(FilaDinamica *fila);
int estaVazia(FilaDinamica *fila);
int tamanhoFila(FilaDinamica *fila);
Objeto inicioFila(FilaDinamica *fila);
Objeto fimFila(FilaDinamica *fila);

#endif /* filaDinamica_h */
