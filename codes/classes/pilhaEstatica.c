#include <stdio.h>
#include <stdbool.h> // 1/0 -> true/false, bool

// Definir os tipos (ED)
// array (vetor) -> elementos
// topo (indexador)

#define MAXTAM 8
typedef struct {
  int vetor[MAXTAM];
  int topo;
} PilhaEstatica;

// 1. inicialização
void iniciaPilhaEstatica(PilhaEstatica *pilha) {
  pilha->topo = 0;
  // a primeira posicao para inserção na pilha, é a posicao 0 do vetor
}


// 5. esta Vazia
bool estaVaziaPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->topo == 0);
}

// 6. esta Cheia
bool estaCheiaPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->topo == MAXTAM);
}

//7. quantidade de elemento na estrutura
int tamanhoPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->topo);
}

// 2. inserção (push / empilha)
void empilhaPilhaEstatica(PilhaEstatica *pilha, int x) {
  
  // Se a pilha não estiver cheia:
  if(estaCheiaPilhaEstatica(pilha) == false) {
    // atribuir o x no vetor na posicao do topo
    pilha->vetor[pilha->topo] = x;
    // incrementa o topo (topo++)
    // pilha->topo+=1;
    pilha->topo++;
    // pilha->topo = pilha->topo + 1;
  } else {
    // printf(warning: vc não pode inserir)
    printf("Desculpa, mas não vai rolar\n");
  }
}
 
// 3. remoção (pop / desempilha)
int desempilhaPilhaEstatica(PilhaEstatica *pilha) {
  int aux = -9999;
  // Se a pilha nao estiver vazia:
  if(estaVaziaPilhaEstatica(pilha) == false) {
    // aux = salva ultimo valor valido da pilha
    aux = pilha->vetor[pilha->topo-1];
    // decrementar o topo
    pilha->topo--;
  } else {
    printf("Warning: não pode remover\n");
  }
  return(aux);
}

 /*
 4. pesquisa/consulta (topo / top) -> mostra o topo
 */

// 8. imprimir a estrurura (print)
void imprimePilhaEstatica(PilhaEstatica *pilha) {
  // pilha->vetor, pilha->topo
  printf("Pilha = {");
  for(int i = 0; i < pilha->topo; i++){
    printf("%d ", pilha->vetor[i]);
  }
  printf("}\n");
}


int main(int argc, const char * argv[]) {
 
  PilhaEstatica p;
  iniciaPilhaEstatica(&p);
  printf("Rodouuuuuu\n");
  
  // vazia
  if(estaVaziaPilhaEstatica(&p)) {
    printf("Pilha está vazia\n");
  } else {
    printf("Tem alguma coisa ai dentro\n");
  }
  
  // cheia
  if(estaCheiaPilhaEstatica(&p)) {
    printf("Está cheia\n");
  } else {
    printf("Pilha não está cheia\n");
  }
  
  int tmp = tamanhoPilhaEstatica(&p);
  printf("Tamanho = %d\n", tmp);
  
  imprimePilhaEstatica(&p);
  
  // 8 elementos
  empilhaPilhaEstatica(&p, 7);
  imprimePilhaEstatica(&p);
  // Pilha = {7}
  
  empilhaPilhaEstatica(&p, 23);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23}
  
  empilhaPilhaEstatica(&p, 10);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10}
  
  empilhaPilhaEstatica(&p, 47);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47}
  
  empilhaPilhaEstatica(&p, 19);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47 19}
  
  empilhaPilhaEstatica(&p, 14);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47 19 14}
  
  empilhaPilhaEstatica(&p, 41);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47 19 14 41}
  
  empilhaPilhaEstatica(&p, 4);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47 19 14 41 4}
  
  empilhaPilhaEstatica(&p, 69);
  imprimePilhaEstatica(&p);
  // Pilha = {7 23 10 47 19 14 41 4}
  tmp = tamanhoPilhaEstatica(&p);
  printf("Tamanho = %d\n", tmp);
  
  int valor;
  for(int i = 0; i < 9; i++) {
    valor = desempilhaPilhaEstatica(&p);
    imprimePilhaEstatica(&p);
  }
  
  return 0;
}

