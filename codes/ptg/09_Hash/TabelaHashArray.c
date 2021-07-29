//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "TabelaHashArray.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaTabelaHahsArray(TabelaHashArray *tabela) {
  for(int i = 0; i < M; i++) {
    tabela->vetor[i] = NULL;
  }
  tabela->quantidadeElementos = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int funcaoHash(int chave) {
  return(chave % M);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->quantidadeElementos == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaCheiaTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->quantidadeElementos == M);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoTabelaHashArray(TabelaHashArray *tabela) {
  return(tabela->quantidadeElementos);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int incrementaIndice(int i) {
  int novoValor = (i+1) % M;
  return novoValor;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insereTabelaHashArray(TabelaHashArray *tabela, ItemTabelaHash *item){
  
  if(!estaCheiaTabelaHashArray(tabela)) {
    
    // posicao para inserção
    int pos = funcaoHash(item->chave);
    
    //sondagem linear - executa até achar uma posição para inserir
    while(true) {
      if(tabela->vetor[pos] != NULL) {
        printf(" - Colisão. Já existe elemento na posição %d.\n", pos);
        pos = incrementaIndice(pos);
      } else {
        tabela->vetor[pos] = item;
        tabela->quantidadeElementos++;
        return true;
      }
    }
  } else {
    printf(" - Warning: tabela está cheia\n");
    return false;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeTabelaHashArray(TabelaHashArray *tabela, int chave){
 
  if(estaVaziaTabelaHashArray(tabela)) return false;
  
  // posicao onde existira o elemento
  int pos = funcaoHash(chave);
  if(tabela->vetor[pos] == NULL) return false;
  
  int contador = 0;
  
  // procurar realizando a sondagem linear
  while(contador < M) {
    if(tabela->vetor[pos]!= NULL && tabela->vetor[pos]->chave == chave) {
      tabela->vetor[pos] = NULL;
      tabela->quantidadeElementos--;
      return true;
    } else {
      pos = incrementaIndice(pos);
      contador++;
    }
  }
  return false;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool pesquisaTabelaHashArray(TabelaHashArray *tabela, int chave,
                             ItemTabelaHash *item) {

  if(estaVaziaTabelaHashArray(tabela)) return false;
  
  // posicao onde existira o elemento
  int pos = funcaoHash(chave);
  if(tabela->vetor[pos] == NULL) return false;

  int contador = 1;
  // procurar realizando a sondagem linear
  while(contador <= M) {
    if(tabela->vetor[pos]!= NULL && tabela->vetor[pos]->chave == chave) {
      *item = *(tabela->vetor[pos]);
      return true;
    } else {
      pos = incrementaIndice(pos);
      contador++;
    }
  }
  return false;
}


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeTabelaHashArray(TabelaHashArray *tabela) {

  printf("=============================\n");
  printf("           Tabela            \n");
  printf("=============================\n");

  for(int i = 0; i < M; i++) {
      
  if(tabela->vetor[i] != NULL) {
    printf(" [%d](%d,%s)\n", i, tabela->vetor[i]->chave, tabela->vetor[i]->info);
    } else {
      printf(" [%d] ~~ \n", i);
    }
  }
  printf("=============================\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiTabelaHashArray(TabelaHashArray *tabela) {
  for(int i = 0; i < M; i++) {
    tabela->vetor[i] = NULL;
  }
  tabela->quantidadeElementos = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
