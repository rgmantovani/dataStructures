//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "ListaOrdenada.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaListaOrdenada(ListaOrdenada *lista) {
  lista->inicio  = NULL;
  lista->tamanho = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaListaOrdenada(ListaOrdenada *lista) {
  return(lista->inicio == NULL);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoListaOrdenada(ListaOrdenada *lista) {
  return(lista->tamanho);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiListaOrdenada(ListaOrdenada *lista) {
  PtrNoLista remover;
  while(lista->inicio != NULL) {
    remover = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(remover);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeListaOrdenada(ListaOrdenada *lista){
  PtrNoLista ptr;
  printf(" [*] Lista:{ ");
  for(ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool pesquisaListaOrdenada(ListaOrdenada *lista, int x) {

  if(estaVaziaListaOrdenada(lista))  return false;

  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo) {
    if(ptr->x == x) return true;
  }
  return false;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool pesquisaOtimizadaListaOrdenada(ListaOrdenada *lista, int x) {
  
  if(estaVaziaListaOrdenada(lista))  return false;

  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL && x > ptr->x; ptr = ptr->proximo);
  if(ptr == NULL || ptr->x > x) return false;
  
  return true;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void insereListaOrdenada(ListaOrdenada *lista, int x) {

  PtrNoLista novo = (PtrNoLista)malloc(sizeof(NoLista));
  novo->x = x;
  
  /* primeira inserção ou valor menor que o primeiro elemento */
  if(estaVaziaListaOrdenada(lista) || (x < lista->inicio->x)) {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
  } else {
   
    PtrNoLista aux = lista->inicio;
    while(aux->proximo != NULL && x > aux->proximo->x) {
      aux = aux->proximo;
    }
    novo->proximo = aux->proximo;
    aux->proximo = novo;
  }
  lista->tamanho++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removePrimeiroListaOrdenada(ListaOrdenada *lista, int *x) {
  if(!estaVaziaListaOrdenada(lista)) {
    PtrNoLista aux = lista->inicio;
    *x = aux->x;
    lista->inicio = lista->inicio->proximo;
    free(aux);
    lista->tamanho--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removeUltimoListaOrdenada(ListaOrdenada *lista, int *x) {
  
  if(!estaVaziaListaOrdenada(lista)) {
    
    if(tamanhoListaOrdenada(lista) == 1) {
      removePrimeiroListaOrdenada(lista, x);
    }
    else
    {
      PtrNoLista aux = lista->inicio;
      for(aux=lista->inicio; aux->proximo->proximo!=NULL; aux=aux->proximo);
    
      PtrNoLista remover = aux->proximo;
      *x = remover->x;
      aux->proximo = NULL;
      free(remover);
      lista->tamanho--;
    }
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removeListaOrdenada(ListaOrdenada *lista, int key, int *x){

  /* empty list or the value lower than the first */
  if(estaVaziaListaOrdenada(lista) || key < lista->inicio->x) return;
  
  if(key == lista->inicio->x) {
    removePrimeiroListaOrdenada(lista, x);
  } else {
      
    PtrNoLista aux = lista->inicio;
    while((aux->proximo != NULL) && (key > aux->proximo->x)) {
      aux = aux->proximo;
    }
      
    if((aux->proximo == NULL) || (key < aux->proximo->x)) {
      return;
    }
    
    PtrNoLista remover = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    lista->tamanho--;
    free(remover);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int primeiroListaOrdenada(ListaOrdenada *lista) {
  return(lista->inicio->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int ultimoListaOrdenada(ListaOrdenada *lista) {
  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL; ptr = ptr->proximo);
  return(ptr->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
