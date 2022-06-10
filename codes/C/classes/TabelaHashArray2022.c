#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 11

//---------------
// TAD
// 1. Item de Hash (Heroi)
// chave, nome, poder
typedef struct {
  int chave;
  char nome[20];
  char poder[50];
} ItemHash;

// 2. Tabela Hash com Endereçamento Direto
// vetor M, onde cada posicao é um heroi
typedef struct {
  ItemHash* vetor[TAMANHO];
  int contador;
} TabelaHashArray;

//---------------
//---------------

int hash(int chave) {
  // UM logica p retornar outro int (id)
  int id = chave % TAMANHO;
  printf(" - Indice computado: %d\n", id);
  return id;
}

//---------------
//---------------

int sondagemLinear(TabelaHashArray *tabela, int id) {
  int posicao = id;
  while(tabela->vetor[posicao] != NULL) {
    if(posicao == (TAMANHO-1)) {
      posicao = 0;
    } else {
      posicao ++;
    }
  } // tem a [posicao] == NULL
  return(posicao);
}

int sondagemQuadratica(TabelaHashArray *tabela, int id) {
  // se tiver a posição: id da posição
  int iteracoes, np1, np2, i, newId1, newId2;
  iteracoes = (TAMANHO-1/2);
  for(i = 1; i <= iteracoes; i++) {
    np1 = id + (i*i);
    newId1 = np1 % TAMANHO;
    if(tabela->vetor[newId1] == NULL) {
      return newId1; // aqui
    }
    np2 = id - (i*i);
    newId2 = np2 % TAMANHO;
    if(tabela->vetor[newId2] == NULL) {
      return newId2; // aqui
    }
  }
  return -1;
}
//---------------
//---------------
// inicializada
void iniciaTabelaHashArray(TabelaHashArray *tabela) {
  // percorrer o vetor, atribuir NULL
  // contador = 0
  for(int i = 0; i < TAMANHO; i++) {
    tabela->vetor[i] = NULL;
  }
  tabela->contador = 0;
}

// tamanho (elementos)
int tamanhoTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->contador);
}
// vazia ou nao
bool estaVaziaTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->contador == 0);
}

// cheia ou nao
bool estaCheiaTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->contador == TAMANHO);
}

//---------------
// Impressao
//---------------
void imprimirItemHash(ItemHash *item) {
  if(item == NULL) {
    printf(" ~~ NULL |\n");
  } else {
    printf(" %s | %s |\n", item->nome, item->poder);
  }
}

void imprimirTabelaHashArray(TabelaHashArray *tabela) {
  printf("-----------\n");
  printf("    Hash   \n");
  printf("-----------\n");
  for(int i=0; i < TAMANHO; i++) {
    printf(" %d |", i);
    imprimirItemHash(tabela->vetor[i]);
  }
  printf("-----------\n");
}

//---------------
//---------------

// destruir
void destruirTabelaHashArray(TabelaHashArray *tabela) {
  iniciaTabelaHashArray(tabela);
}

// inserir
void inserirTabelaHashArray(TabelaHashArray *tabela, ItemHash *item){

  if(estaCheiaTabelaHashArray(tabela)) {
    printf("Warning: estrutura está cheia!\n");
    return;
  }

  if(item == NULL || item->chave < 0) {
    printf("Warning: item vazio ou chave inválida!\n");
    return;
  }

  // acesso indireto via função hash
  int id = hash(item->chave);

  if(tabela->vetor[id] == NULL) {
    tabela->vetor [id] = item;
    tabela->contador++;
  } else {
    printf("Warning: posição já ocupada. Realizando sondagem!\n");
//    int novaPosicao = sondagemLinear(tabela, id);
    int novaPosicao = sondagemQuadratica(tabela, id);
    tabela->vetor[novaPosicao] = item;
    tabela->contador++;
  }
}

// consultar
ItemHash* consultarTabelaHashArray(TabelaHashArray *tabela, int chave) {
  // >= tamanho e < 0
  int id = hash(chave);
  if(chave < 0 || tabela->vetor[id] == NULL) {
    return NULL;
  }
  return(tabela->vetor[id]);
}

// remocao
void removerTabelaHashArray(TabelaHashArray *tabela, int chave) {
  // >= tamanho e < 0
  if(chave < 0) {
    printf("Warning: chave inválida!\n");
    return;
  }
  int id = hash(chave);
  if(tabela->vetor[id] != NULL) {
    tabela->vetor[id] = NULL;
    tabela->contador--;
  }
}

//---------------
//---------------

int main(int argc, char *argv[]) {
  TabelaHashArray table;
  iniciaTabelaHashArray(&table);

  printf("======\n");
  ItemHash h1 = {0,"gabriel", "trancar chave dentro do carro"};
  inserirTabelaHashArray(&table, &h1);
  imprimirTabelaHashArray(&table);
  ItemHash h2 = {8,"matheus", "estudar e não aprender nada"};
  inserirTabelaHashArray(&table, &h2);
  imprimirTabelaHashArray(&table);
  ItemHash h3 = {5,"mantova", "sono e cansaço infinito"};
  inserirTabelaHashArray(&table, &h3);
  imprimirTabelaHashArray(&table);
  ItemHash h4 = {50,"madu", "fazer e não fazer nada BEM"};
  inserirTabelaHashArray(&table, &h4);
  imprimirTabelaHashArray(&table);
  ItemHash h5 = {22,"Plinio", "bater pratão no RU"};
  inserirTabelaHashArray(&table, &h5);
  imprimirTabelaHashArray(&table);
  ItemHash h6 = {21,"Andrezao", "piada fraca"};
  inserirTabelaHashArray(&table, &h6);
  imprimirTabelaHashArray(&table);
  ItemHash h7 = {32,"Luizao", "dedo podre para esportes"};
  inserirTabelaHashArray(&table, &h7);
  imprimirTabelaHashArray(&table);
  ItemHash h8 = {9,"Tamara", "hot dog com agua de salsicha"};
  inserirTabelaHashArray(&table, &h8);
  imprimirTabelaHashArray(&table);
  ItemHash h9 = {20,"Muriel", "murieeeeeeelllllllll"};
  inserirTabelaHashArray(&table, &h9);
  imprimirTabelaHashArray(&table);

//  removerTabelaHashArray(&table, 50);
//  removerTabelaHashArray(&table, -50);
//  ItemHash *retorno = consultarTabelaHashArray(&table, 5);
//  removerTabelaHashArray(&table, 5);
//  imprimirTabelaHashArray(&table);
//  imprimirItemHash(retorno);
//  destruirTabelaHashArray(&table);
//  imprimirTabelaHashArray(&table);

  return 0;
}
