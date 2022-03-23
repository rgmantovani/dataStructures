//  main.c
//  Listas

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//------------------------------------------
// Single-linkage list
//------------------------------------------

typedef struct NoLista* PtrNoLista;

typedef struct NoLista{
  int chave;
  PtrNoLista proximo;
  // PtrNoLista anterior; // duplamente encadeada
} NoLista;

typedef struct {
  PtrNoLista inicio;
  int tamanho;
} ListaDinamica;

//------------------------------------------
//------------------------------------------

void iniciaListaDinamica(ListaDinamica *lista) {
  //inicio
  lista->inicio = NULL;
  //tamanho
  lista->tamanho = 0;
}

//------------------------------------------
//------------------------------------------
// esta vazia
bool estaVaziaListaDinamica(ListaDinamica *lista) {
  return (lista->tamanho == 0);
  //return(lista->inicio == NULL);
}

//------------------------------------------
//------------------------------------------
// tamanho da lista
int tamanhoListaDinamica(ListaDinamica *lista) {
  return(lista->tamanho);
}

//------------------------------------------
//------------------------------------------
// imprimir elementos da lista
void imprimirListaDinamica(ListaDinamica *lista) {
  printf("Lista = {");
  
  PtrNoLista percorre;
  for(percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo) {
    printf("%d ", percorre->chave);
  }
  printf("}\n");
}

//------------------------------------------
//------------------------------------------
// insercao de elementos na lista
void inserirListaDinamica(ListaDinamica *lista, int elemento) {
  
  printf("Inserindo: %d \n", elemento);
  
  // 1. Criar o ponteiro (Novo)
  PtrNoLista novo;
  // 2. Aloca memoria para Novo
  novo =(PtrNoLista)malloc(sizeof(NoLista));
  // 3. copia o valor do elemento p chave do Novo no
  novo->chave = elemento;
  
  // Situação #1: Lista esta Vazia , ou
  // se o elemento que a gente quer inserir é menor do que o primeiro
  if(estaVaziaListaDinamica(lista) || elemento < lista->inicio->chave) {
    
    //printf("situacao 1 \n");
    // 4. proximo do novo aponta para nulo (inicio)
    novo->proximo = lista->inicio;
    // 5. Inicio aponta para o novo no
    lista->inicio = novo;
    // 6. incrementa o contador
   
  
  } // Situacao # (Lista nao esta vazia)
  else {
 
   //printf("situacao 2 \n");
    // aux = percorre a lista p gente (encontrar o ponto de insercao - posicao)
    PtrNoLista aux;
    
    // 4. percorrer e encontrar o ponto de insercao (aux)
    aux = lista->inicio;
    while((aux->proximo!= NULL) && (elemento > aux->proximo->chave)) {
      aux = aux->proximo;
      //printf("andou ...\n");
    }
    //printf("Aux = %d \n", aux->chave);

    // 5. proximo Novo aponta proximo Aux
    novo->proximo = aux->proximo;
    // 6. proximo do Aux aponta para Novo
    aux->proximo = novo;
    
  }
  // 7. incrementa o contador
  lista->tamanho = lista->tamanho + 1; //++
  //rintf("----------------------\n");
}

//------------------------------------------
//------------------------------------------

//void pesquisaListaDinamica(ListaDinamica *lista,
                          // int* achou);

//bool pesquisaListaDinamica2(ListaDinamica *lista,
                          // int* achou);

// valor invalido caso nao ache (-9999)
//int pesquisaListaDinamica3(ListaDinamica *lista);

bool pesquisaListaDinamica(ListaDinamica *lista, int consulta) {
  PtrNoLista percorre; //aux
  for(percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo) {
    if(consulta == percorre->chave) {
      return (true);
    }
  }
  return(false);
}

bool pesquisaListaDinamica2(ListaDinamica *lista, int consulta) {
  
  if(estaVaziaListaDinamica(lista))
    return false;
  
  PtrNoLista percorre = lista->inicio;
  while(percorre != NULL && consulta > percorre->chave) {
    percorre = percorre->proximo;
  }
  // 1 - cheguei nulo
  // 2 - cheguei > consulta
  // 3 - achei
  
  // 1, e 2
  if(percorre == NULL || percorre->chave > consulta) {
    return false;
  }
  
  // 3
  return true;
}

//------------------------------------------
//------------------------------------------

int main(int argc, const char * argv[]) {
  
  ListaDinamica listinha;
  iniciaListaDinamica(&listinha);
  
  inserirListaDinamica(&listinha, 555);
  //imprimirListaDinamica(&listinha);
  // forcar situacao
  inserirListaDinamica(&listinha, 0);
  //imprimirListaDinamica(&listinha);
  
  inserirListaDinamica(&listinha, 20);
  //imprimirListaDinamica(&listinha);
  
  inserirListaDinamica(&listinha, 700);
  //imprimirListaDinamica(&listinha);
  
  inserirListaDinamica(&listinha, 13);
  //imprimirListaDinamica(&listinha);
  
  if(estaVaziaListaDinamica(&listinha)){
    printf("Lista vazia\n");
  } else {
    printf("Lista contem elementos\n");
  }
  
  printf("Tamanho = %d\n", tamanhoListaDinamica(&listinha));
  
  // impressao da lista
//  {0, 3, 5}
  imprimirListaDinamica(&listinha);
  
  //testar elemento que existe
  if(pesquisaListaDinamica2(&listinha, 13)) {
    printf("Achou miseravi \n");
  } else {
    printf("Try again\n");
  }
  
  if(pesquisaListaDinamica2(&listinha, 87)) {
    printf("Achou miseravi \n");
  } else {
    printf("Try again \n");
  }
  
  //testar um elemento que nao existe
  
  return 0;
}

//------------------------------------------
//------------------------------------------

