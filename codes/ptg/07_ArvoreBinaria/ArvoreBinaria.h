
#ifndef ArvoreBinaria_h
#define ArvoreBinaria_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoArvoreBinaria *PtrNoArvoreBinaria;

typedef struct NoArvoreBinaria {
  int x;
  PtrNoArvoreBinaria filhoEsquerda;
  PtrNoArvoreBinaria filhoDireita;
} NoArvoreBinaria;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

int tamanhoArvoreBinaria(PtrNoArvoreBinaria *node);
int profundidadeArvoreBinaria(PtrNoArvoreBinaria *node);
void iniciaArvoreBinaria(PtrNoArvoreBinaria *node);
void destroiArvoreBinaria(PtrNoArvoreBinaria *node);
void preOrdemArvoreBinaria(PtrNoArvoreBinaria *node);
void posOrdemArvoreBinaria(PtrNoArvoreBinaria *node);
void EmOrdemArvoreBinaria(PtrNoArvoreBinaria *node);
bool insereArvoreBinaria(PtrNoArvoreBinaria *node, int x);
bool pesquisaArvoreBinaria(PtrNoArvoreBinaria *node, int x);
bool estaVaziaArvoreBinaria(PtrNoArvoreBinaria *node);
bool removeArvoreBinaria(PtrNoArvoreBinaria *node, int key);
PtrNoArvoreBinaria maximoArvoreBinaria(PtrNoArvoreBinaria *node);
PtrNoArvoreBinaria maximoArvoreBinariaIterativo(PtrNoArvoreBinaria *node);
PtrNoArvoreBinaria minimoArvoreBinaria(PtrNoArvoreBinaria *node);
PtrNoArvoreBinaria minimoArvoreBinariaIterativo(PtrNoArvoreBinaria *node);
PtrNoArvoreBinaria getMinAuxArvoreBinaria(PtrNoArvoreBinaria *node);
PtrNoArvoreBinaria getMaxAuxArvoreBinaria(PtrNoArvoreBinaria *node);

#endif /* ArvoreBinaria_h */
