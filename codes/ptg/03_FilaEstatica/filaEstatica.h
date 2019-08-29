#ifndef filaEstatica_h
#define filaEstatica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 5

typedef struct {
  int chave;
    /* outros componentes */
} Objeto;

typedef struct {
  Objeto array[MAXTAM];
  int tamanho;
  int inicio;
  int fim;
} FilaEstatica;

void iniciaFila(FilaEstatica *fila);
bool estaVazia(FilaEstatica *fila);
bool estaCheia(FilaEstatica *fila);
int tamanhoFila(FilaEstatica *fila);
int incrementaIndice(int i);
void enfileira(Objeto x, FilaEstatica *fila);
void imprimeFila(FilaEstatica *fila);
Objeto desenfileira(FilaEstatica *fila);
Objeto inicioFila(FilaEstatica *fila);
Objeto fimFila(FilaEstatica *fila);

#endif /* filaEstatica_h */
