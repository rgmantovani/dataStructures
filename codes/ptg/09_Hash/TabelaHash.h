#ifndef TabelaHash_h
#define TabelaHash_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 23

typedef struct {
    char* info;
    int chave;
} Objeto;

typedef struct {
  Objeto* hashArray[TAMANHO];
  int contador;
} TabelaHash;

int funcaoHash(int key);
void iniciaHash(TabelaHash *tabela);
void insereHash(TabelaHash *tabela, int chave, char *info);
bool procuraHash(TabelaHash *tabela, int chave);
Objeto* removeHash(TabelaHash *tabela, int chave);
void imprimeHash(TabelaHash *tabela);

#endif /* TabelaHash_h */
