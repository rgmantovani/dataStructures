#ifndef TabelaHashArray_h
#define TabelaHashArray_h

# include <stdbool.h>
# include <stdio.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

#define M 7 //23

typedef struct {
  int chave;
  char info[100];
} ItemTabelaHash;

typedef struct {
  ItemTabelaHash* vetor[M];
  int quantidadeElementos;
} TabelaHashArray;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaTabelaHahsArray(TabelaHashArray *tabela);
int funcaoHash(int chave);
int incrementaIndice(int i);
int tamanhoTabelaHashArray(TabelaHashArray *tabela);
bool estaVaziaTabelaHashArray(TabelaHashArray *tabela);
bool estaCheiaTabelaHashArray(TabelaHashArray *tabela);
bool insereTabelaHashArray(TabelaHashArray *tabela, ItemTabelaHash *item);
bool removeTabelaHashArray(TabelaHashArray *tabela, int chave);
bool pesquisaTabelaHashArray(TabelaHashArray *tabela, int chave, ItemTabelaHash *item);
void imprimeTabelaHashArray(TabelaHashArray *tabela);
void destroiTabelaHashArray(TabelaHashArray *tabela);

#endif /* TabelaHashArray_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
