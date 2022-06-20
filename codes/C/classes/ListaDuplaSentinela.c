#include <stdio.h>
#include <stdbool.h> // true/false
#include <stdlib.h>  // free, malloc, sizeof

//----------------------------------------------
//----------------------------------------------
// TAD (struct)

// NoLista* = PtrNoLista
typedef struct NoLista* PtrNoLista;

//  - NoLista (chaves - ints, ptr proximo, ptr anterior)
typedef struct NoLista {
    int chave;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

//  - ListaOrdenada
typedef struct {
    PtrNoLista inicio;
    int qtdeElementos;
} ListaDuplaSentinela;

//----------------------------------------------
//----------------------------------------------

void iniciaListaDuplaSentinela(ListaDuplaSentinela *lista) {

  PtrNoLista sentinela = malloc(sizeof(NoLista));

  sentinela->chave = -999;
  sentinela->proximo  = sentinela;
  sentinela->anterior = sentinela;

  lista->inicio = sentinela;
  lista->qtdeElementos = 0;
}

//----------------------------------------------
// estaVazia
//----------------------------------------------

bool estaVaziaListaDuplaSentinela(ListaDuplaSentinela *lista) {
  return(lista->qtdeElementos == 0);
}

//----------------------------------------------
//----------------------------------------------
int tamanhoListaDuplaSentinela(ListaDuplaSentinela *lista) {
  return(lista->qtdeElementos);
}

//----------------------------------------------
// imprimir do primeiro para o ultimo
//----------------------------------------------
void imprimeListaDuplaSentinelaCres(ListaDuplaSentinela *lista) {
  printf("Lista = [");
  for(PtrNoLista aux = lista->inicio->proximo; aux->chave != -999; aux = aux->proximo) {
    printf("%d ", aux->chave);
  }
  printf("]\n");
}

void imprimeListaDuplaSentinelaDecres(ListaDuplaSentinela *lista) {
  printf("Lista = [");
  for(PtrNoLista aux = lista->inicio->anterior; aux->chave != -999; aux = aux->anterior) {
    printf("%d ", aux->chave);
  }
  printf("]\n");
}


//----------------------------------------------
// insere elementos
//----------------------------------------------
void inserirListaDuplaSentinela(ListaDuplaSentinela *lista, int valor){

  PtrNoLista novo = malloc(sizeof(NoLista));
  novo->chave = valor;

  // Primeira insercao
  if(estaVaziaListaDuplaSentinela(lista)){
    // ligar o novo ao sentinela (lista->inicio == sentinela)
    novo->proximo  = lista->inicio;
    novo->anterior = lista->inicio;

    // conectar o sentinela ao novo
    lista->inicio->proximo  = novo;
    lista->inicio->anterior = novo;
  }

  // Insercao de um elemento menor que o primeiro
  else if(valor < lista->inicio->proximo->chave){

    // conectar o novo ao proximo do sentinela
    novo->proximo = lista->inicio->proximo;
    lista->inicio->proximo->anterior = novo;

    // conectar o sentinela ao novo
    novo->anterior = lista->inicio;
    lista->inicio->proximo = novo;
  }

  /*  TODO: falta fazer a parte de quanto percorre e insere
   aqui também serão 4 comandos, pq são 4 ponteiros que mudam
   (dois no novo, e dois conectando de volta)
   */

  // incrementar contador de elementos
  lista->qtdeElementos++;

}
//----------------------------------------------
//----------------------------------------------

int main(int argc, const char * argv[]) {

  ListaDuplaSentinela lista;
  iniciaListaDuplaSentinela(&lista);

  // primeira insercao
  inserirListaDuplaSentinela(&lista, 10);
  imprimeListaDuplaSentinelaCres(&lista);

  // inserindo um elemento menor que o primeiro
  inserirListaDuplaSentinela(&lista, 5);
  imprimeListaDuplaSentinelaCres(&lista);
  imprimeListaDuplaSentinelaDecres(&lista);

  int tam = tamanhoListaDuplaSentinela(&lista);
  printf("Tamanho = %d\n", tam);

  return 0;
}

//----------------------------------------------
//----------------------------------------------
