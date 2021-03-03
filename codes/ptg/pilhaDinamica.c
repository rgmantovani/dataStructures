#include "pilhaDinamica.h"

void iniciaPilha(PilhaDinamica *p) {
  p->topo = NULL;
  p->tamanho = 0;
}

int tamanhoPilha(PilhaDinamica *p) {
  return(p->tamanho);
}

bool estaVazia(PilhaDinamica *p) {
  return(p->tamanho == 0);
}

void empilha(Objeto obj, PilhaDinamica *p) {
  
  PtrNoPilha aux;
  aux = (PtrNoPilha) malloc(sizeof(NoPilha));
 
  aux->obj = obj;
  aux->proximo = p->topo;
  p->topo = aux;
  p->tamanho = p->tamanho + 1;
}

void desempilha(PilhaDinamica *p, Objeto *item) {
  if(estaVazia(p)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
        
    *item = p->topo->obj;
    PtrNoPilha aux;
    aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    p->tamanho = p->tamanho - 1;
  }
}

void topo(PilhaDinamica *p, Objeto *obj) {
  if(estaVazia(p)) {
    printf(" * Erro: pilha esta vazia - nao ha elemento no topo! \n");
  } else {
    *obj = p->topo->obj;
  }
}


void imprimePilha(PilhaDinamica *p) {
  printf("Pilha = {");
  PtrNoPilha ptr;
  for(ptr = p->topo; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->obj.chave);
  }
  printf("}\n");
}

void destroi(PilhaDinamica *p) {
  printf("@Destroying stack!\n");
  PtrNoPilha remover;
  while(p->topo!= NULL) {
    remover = p->topo;
    p->topo = p->topo->proximo;
    free(remover);
  }
}

void destroi2(PilhaDinamica *p) {
  printf("@Destroying stack!\n");
  Objeto aux;
  while (!estaVazia(p)){
    desempilha(p, &aux);
  }
}
