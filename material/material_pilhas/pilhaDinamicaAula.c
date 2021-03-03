#include <stdio.h>
#include <stdbool.h> /* true/false */
#include <stdlib.h>

/* definir os tipos */
typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha {
  int valor;
  PtrNoPilha proximo; // struct NoPilha*
} NoPilha;

typedef struct {
  PtrNoPilha topo;   // struct NoPilha*
  int tamanho;
} PilhaDinamica;

void iniciaPd(PilhaDinamica *pd) {
  pd->topo = NULL;
  pd->tamanho = 0;
}

int tamanhoPd(PilhaDinamica *pd) {
  return(pd->tamanho);
}

bool estaVaziaPd(PilhaDinamica *pd) {
  return(pd->tamanho == 0);
}

void imprimePd(PilhaDinamica *p) {
  printf("Pilha = {");
  PtrNoPilha ptr;
  for(ptr = p->topo; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->valor);
  }
  printf("}\n");
}

void empilhaPd(PilhaDinamica *pd, int valor) {
  // passo 1
  PtrNoPilha Aux;
  // passo 2
  Aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha)); // criando caixinha
  //passo 3
  Aux->valor = valor; //copia o valor p dentro do bloco
  //passo 4
  Aux->proximo = pd->topo; // Novo-proximo -> topo
  //passo 5
  pd->topo = Aux;     // topo -> novo
  //passo 6
  pd->tamanho++;
}

int desempilhaPd(PilhaDinamica *pd) {
  //passo 0 (valor para retorno)
  int v = -99;
  if(!estaVaziaPd(pd)) {
    //passo 1
    PtrNoPilha Aux;
    //passo 2
    Aux = pd->topo;
    //passo 3
    v = Aux->valor;
    //passo 4
    pd->topo = Aux->proximo; // pd->topo = pd->topo->prox;
    //passo 5 - desalocar a memoria
    free(Aux);
    // passo 6 - decerementar a qtde da pilha
    pd->tamanho--;
  } else {
    printf("Warning: esta vazia\n");
  }

  // passo 7 - retornar o valor da pilha
  return(v);
}

int main(int argc, const char * argv[]) {

  PilhaDinamica pilha;

  iniciaPd(&pilha);
  imprimePd(&pilha);
  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  empilhaPd(&pilha, 2);
  imprimePd(&pilha);
  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  empilhaPd(&pilha, 6);
  imprimePd(&pilha);
  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  empilhaPd(&pilha, 9);
  imprimePd(&pilha);

  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  int x = desempilhaPd(&pilha);
  printf("Valor removido = %d\n", x);
  imprimePd(&pilha);
  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  x = desempilhaPd(&pilha);
  printf("Valor removido = %d\n", x);
  imprimePd(&pilha);
  printf("Tamanho = %d\n", tamanhoPd(&pilha));

  return 0;
}
