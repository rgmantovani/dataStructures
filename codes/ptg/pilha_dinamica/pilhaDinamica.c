#include "pilhaDinamica.h"

void iniciaPilha(pilhaDinamica *pilha) {
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

int tamanhoPilha(pilhaDinamica *pilha) {
  return(pilha->tamanho);
}

int estaVazia(pilhaDinamica *pilha) {
  return(pilha->tamanho == 0);
  //  return(tamanhoPilha(pilha) == 0);
}

// empilha um novo elemento
void empilha(Item item, pilhaDinamica *pilha) {
    
  Ponteiro aux;
  aux = (Ponteiro) malloc(sizeof(NoPilha));
  aux->item = item;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho = pilha->tamanho + 1;
    
}

void desempilha(pilhaDinamica *pilha, Item *item) {
    
  if(estaVazia(pilha)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
        
    *item = pilha->topo->item;
        
    Ponteiro aux;
    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
        
    free(aux);
    pilha->tamanho = pilha->tamanho - 1;
  }
}

void topo(pilhaDinamica *pilha, Item *item) {
  if(estaVazia(pilha)) {
    printf(" * Erro: pilha esta vazia - nao ha elemento no topo! \n");
  } else {
    *item = pilha->topo->item;
  }
}


void imprimePilha(pilhaDinamica *pilha) {
  printf("Pilha = {");
  Ponteiro ptr;
  for(ptr = pilha->topo; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->item.chave);
  }
  printf("}\n");
}

