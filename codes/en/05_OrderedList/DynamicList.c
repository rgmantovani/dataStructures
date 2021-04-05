//
//  DynamicList.c
//  Created by Rafael Gomes Mantovani on 05/04/19.

#include "DynamicList.h"

void initList(List *list) {
  list->first = NULL;
  list->size  = 0;
}

bool isEmpty(List *list) {
  return(list->first == NULL);
}

int size(List *list) {
  return(list->size);
}

void destroyList(List *list) {
  printf("@Destroying list!\n");
  Pointer remover;
  while(list->first!= NULL) {
    remover = list->first;;
    list->first = list->first->next;
    free(remover);
  }
}
  
void printList(List *list) {
  Pointer ptr;
//  printf("---------------\n");
  printf(" [*] List:{ ");
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->element.key);
  }
  printf("}\n\n");
}

bool search(List *list, int key) {
  Pointer ptr;
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    if(ptr->element.key == key) {
      printf("@ Elemento encontrado: %d\n", ptr->element.key);
      return true;
    }
  }
  printf("@ Elemento não encontrado: %d!\n", key);
  return false;
}


bool searchFaster(List *list, int key) {
  Pointer ptr;
  if(isEmpty(list)) {
    return false;
  }

  for(ptr = list->first; ptr->next != NULL && key > ptr->element.key; ptr = ptr->next);
  if(ptr == NULL || ptr->element.key > key) {
    return false;
  }
  return true;
}


void insert(List *list, Object x) {

  Pointer new;
  new = (Pointer) malloc(sizeof(NodeList));
  new->element = x;
  
  printf("@ Inserindo elemento: %d\n", x.key);
  
  // insere no começo se a lista esta vazia
  // ou é menor que o primeiro elemento
  if(isEmpty(list) || (x.key < list->first->element.key)) {
    new->next = list->first;
    list->first = new;
  } else {
    // cai aqui se for inserir do segundo da frente
    // percorrer e achar a posicao de inserção
    Pointer aux;
    aux = list->first;
    
    while(aux->next != NULL && x.key > aux->next->element.key) {
      aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
  }
  list->size++;
  
}

void removeFirst(List *list, Object *item) {
  if(isEmpty(list) == 0) {
    Pointer aux = list->first;
    *item = aux->element;
    list->first = list->first->next;
    free(aux);
    list->size--;
    printf("@Elemento: %d removido\n", (*item).key);
  } else {
    printf("#Warning: Lista esta vazia. Nao removendo.\n");
  }
}

void removeLast(List *list, Object *item) {
  
  if(isEmpty(list) == 0) {
    if(size(list) == 1) {
      removeFirst(list, item);
    } else {
      Pointer aux;
      aux = list->first;
      
      for(aux = list->first; aux->next->next !=NULL; aux = aux->next);
      Pointer remove = aux->next;
      *item = remove->element;
      aux->next = NULL;
      free(remove);
      printf("@Elemento: %d removido\n", (*item).key);
      list->size = list->size-1;
    }
  } else {
    printf("#Warning: Lista esta vazia. Nao removendo.\n");
  }
}


void removeElement(List *list, int key, Object *item) {
  //se a lista esta vazia (casos 1 e 2)
  if(isEmpty(list) || key < list->first->element.key) {
    printf("#Warning: Lista esta vazia ou nao existe o elemento na lista ordenada. Nao removendo.\n");
  } else {
    // se for o primeiro elemento (caso 3)
    if(key == list->first->element.key) {
      printf(" Removendo o primeiro elemento.\n");
      removeFirst(list, item);
    } else { // casos 4 e 5
      
      Pointer aux = list->first;
      while((aux->next != NULL) && (key > aux->next->element.key)) {
        aux = aux->next;
      }
      
      if((aux->next == NULL) || (key < aux->next->element.key)) {
        printf(" Warning: Nao existe o elemento na lista. Nao removendo.\n");
      } else { // caso 5
        Pointer remove = aux->next;
        aux->next = aux->next->next;
        list->size--;
        free(remove);
      }
    }
  }
}

Object first(List *list) {
  Object aux = list->first->element;
  return(aux);
}

Object last(List *list) {
  Pointer ptr;
  for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);
  Object x = ptr->element;
  return(x);
}
