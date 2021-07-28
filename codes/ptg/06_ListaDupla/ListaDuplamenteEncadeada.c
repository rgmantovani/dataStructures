//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "ListaDuplamenteEncadeada.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaListaDupla(ListaDupla *lista){
  lista->inicio = NULL;
  lista->tamanho = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaListaDupla(ListaDupla *lista){
  return(lista->tamanho == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoListaDupla(ListaDupla *lista){
  return(lista->tamanho);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insereListaDupla(ListaDupla *lista, int x){
        
  PtrNoLista novo = (PtrNoLista) malloc(sizeof(NoLista));
  
  if(!novo) {
    printf("@ O novo nó não foi alocado\n");
    return (false);
  }
  novo->elemento = x;
  printf("@ Inserindo o valor: %d\n", x);

  /* primeira inserção */
  if(estaVaziaListaDupla(lista)) {
    novo->proximo  = NULL;
    novo->anterior = NULL;
    lista->inicio  = novo;
  }
  /* inserindo um elemento menor do que o primeiro */
  else if (x < lista->inicio->elemento) {
    novo->anterior = NULL;
    lista->inicio->anterior = novo;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
  }
  /* encontrando a posição de inserção */
  else {
    PtrNoLista aux;
    aux = lista->inicio;
    while(aux->proximo != NULL && x > aux->proximo->elemento) {
      aux = aux->proximo;
    }

    novo->proximo = aux->proximo;
    if(aux->proximo != NULL) {
      aux->proximo->anterior = novo;
    }
    novo->anterior = aux;
    aux->proximo   = novo;
  }
  lista->tamanho++;
  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeListaDupla(ListaDupla *lista) {
  PtrNoLista ptr;
  printf(" [*] Lista:{ ");
  for(ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->elemento);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeListaDuplaReverso(ListaDupla *lista) {

  if(estaVaziaListaDupla(lista)) {
    printf(" [*] Lista:{ }\n");
  } else {

    PtrNoLista ptr;
    for(ptr = lista->inicio; ptr->proximo != NULL; ptr = ptr->proximo);

    printf(" [*] Lista:{ ");
    PtrNoLista aux = ptr;
    do {
      printf("%d ", aux->elemento);
      aux = aux->anterior;
    } while(aux != NULL);
    printf("}\n");
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiListaDupla(ListaDupla *lista) {
  printf("@ Destruindo lista dupla!\n");
  PtrNoLista remove;
  while((lista->inicio)!= NULL) {
    remove = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->tamanho--;
    free(remove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool procuraListaDupla(ListaDupla *lista, int x){

  if(estaVaziaListaDupla(lista)) return (false);

  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL && x > ptr->elemento; ptr = ptr->proximo);
  if(ptr == NULL || ptr->elemento > x) {
    return (false);
  }
  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeListaDupla(ListaDupla *lista, int x, int *item) {

  if(estaVaziaListaDupla(lista) || x < lista->inicio->elemento) {
    return(false);
  }

  if(x == lista->inicio->elemento) {
    return (removePrimeiroListaDupla(lista, item));
  }

  PtrNoLista aux = lista->inicio;
  while((aux->proximo != NULL) && (x > aux->proximo->elemento)) {
    aux = aux->proximo;
  }

  if(aux->proximo == NULL || aux->proximo->elemento > x) {
    return (false);
  }

  PtrNoLista remove = aux->proximo;
  *item = remove->elemento;

  if(aux->proximo->proximo != NULL) {
    aux->proximo->proximo->anterior = aux;
  }
  aux->proximo = aux->proximo->proximo;
  lista->tamanho--;
  free(remove);
  printf("@Elemento: %d foi removido\n", (*item));

  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removePrimeiroListaDupla(ListaDupla *lista, int *item) {
    
  if(estaVaziaListaDupla(lista)) return(false);
  
  PtrNoLista aux = lista->inicio;
  *item = aux->elemento;

  lista->inicio = lista->inicio->proximo;
  lista->inicio->anterior = NULL;
  lista->tamanho--;
  free(aux);
     
  printf("@Elemento: %d foi removido\n", (*item));
  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeUltimoListaDupla(ListaDupla *lista, int *item) {
    
  if(estaVaziaListaDupla(lista)) return(false);

  if(tamanhoListaDupla(lista) == 1) {
    return(removePrimeiroListaDupla(lista, item));
  }

  PtrNoLista aux;
  for(aux = lista->inicio; aux->proximo->proximo != NULL; aux = aux->proximo);

  PtrNoLista remove = aux->proximo;
  *item = remove->elemento;
  aux->proximo = NULL;
  free(remove);

  printf("@Elemento: %d foi removido\n", (*item));
  lista->tamanho--;
  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int primeiroListaDupla(ListaDupla *lista){
  return(lista->inicio->elemento);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int ultimoListaDupla(ListaDupla *lista){
  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL; ptr = ptr->proximo);
  return(ptr->elemento);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
