//
//  ArvoreBinaria.h

#ifndef ArvoreBinaria_h
#define ArvoreBinaria_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Objeto;

typedef struct NodeTree *PtrArvore;

typedef struct NoArvore {
    Objeto elemento;
    PtrArvore left;
    PtrArvore right;
} NoArvore;

int numeroNosArvore(PtrArvore *node);
int alturaArvore(PtrArvore *node);
void iniciaArvore(PtrArvore *node);
void destroiArvore(PtrArvore *node);
void preOrdem(PtrArvore *node);
void posOrdem(PtrArvore *node);
void EmOrdem(PtrArvore *node);
bool insereItem(PtrArvore *node, Objeto x);
bool procuraItem(PtrArvore *node, int key, Objeto *ret);
bool estaVazia(PtrArvore *node);
bool removeItem(PtrArvore *node, int key);
PtrArvore maximo(PtrArvore *node);
PtrArvore maximoIterativo(PtrArvore *node);
PtrArvore minimo(PtrArvore *node);
PtrArvore minimoIterativo(PtrArvore *node);
PtrArvore getMinAux(PtrArvore *node); //usado na remoção
PtrArvore getMaxAux(PtrArvore *node); //usado na remoção

#endif /* ArvoreBinaria_h */
