#include "DoubleLinkedList.h"

void initList(DoubleLinkedList *list) {
  list->first = NULL;
  list->size = 0;
}

bool insert(DoubleLinkedList *list, Item x) {

  Pointer new = (Pointer) malloc(sizeof(NodeList));
  if(!new) {
    printf("@ Novo noh de lista não foi alocado\n");
    return (false);
  }
  new->element = x;
  printf("@ Inserindo elemento: %d\n", x.key);

  // insere no começo se a lista esta vazia
  // ou é menor que o primeiro elemento
  if(isEmpty(list)) {

    new->next = NULL;
    new->previous = NULL;
    list->first = new;

 } else if (x.key < list->first->element.key) {

    new->previous = NULL;
    list->first->previous = new;
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
    if(aux->next != NULL) {
      aux->next->previous = new;
    }
    new->previous = aux;
    aux->next = new;
  }
  list->size++;
  return(true);
}

void printList(DoubleLinkedList *list) {
  Pointer ptr;
  //  printf("---------------\n");
  printf(" [*] List:{ ");
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->element.key);
  }
  printf("}\n");
}

void printInverseList(DoubleLinkedList *list) {

  if(isEmpty(list)) {
    printf(" [*] Inv_List:{ }\n");
  } else {

    Pointer ptr;
    for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);

    printf(" [*] Inv_List:{ ");
    Pointer aux = ptr;
    do {
      printf("%d ", aux->element.key);
      aux = aux->previous;
    } while(aux != NULL);
    printf("}\n");
  }
}

void destroyList(DoubleLinkedList *list) {
  printf("\n @ Destroying list!\n\n");
  Pointer remove;
  while((list->first)!= NULL) {
    remove = list->first;;
    list->first = list->first->next;
    list->size--;
    free(remove);
  }
}

bool isEmpty(DoubleLinkedList *list) {
  return (list->size == 0);
}

int sizeOfList(DoubleLinkedList *list) {
  return (list->size);
}

bool search(DoubleLinkedList *list, int key) {

  if(isEmpty(list)) {
    printf("@ Elemento não encontrado.\n");
    return (false);
  }

  Pointer ptr;
  for(ptr = list->first; ptr->next != NULL && key > ptr->element.key; ptr = ptr->next);
  if(ptr == NULL || ptr->element.key > key) {
    printf("@ Elemento não encontrado.\n");
    return (false);
  }
  printf("@ Elemento encontrado.\n");
  return (true);
}


bool removeElement(DoubleLinkedList *list, int key, Item *item) {

  if(isEmpty(list) || key < list->first->element.key) {
    return(false);
  }

  if(key == list->first->element.key) {
    return (removeFirst(list, item));
  }

  Pointer aux = list->first;
  while((aux->next != NULL) &&
        (key > aux->next->element.key)) {
    aux = aux->next;
  }

  if(aux->next == NULL || aux->next->element.key > key) {
    printf("@ Elemento não encontrado.\n");
    return (false);
  }

  Pointer remove = aux->next;
  *item = remove->element;

  aux->next->next->previous = aux;
  aux->next = aux->next->next;

  list->size--;
  free(remove);
  printf("@Elemento: %d removido\n", (*item).key);

  return(true);
}


bool removeFirst(DoubleLinkedList *list, Item *item) {

  if(isEmpty(list)) {
    return(false);
  }
  Pointer aux = list->first;
  *item = aux->element;

  list->first = list->first->next;
  list->first->previous = NULL;
  free(aux);
  list->size--;
  printf("@Elemento: %d removido\n", (*item).key);

  return (true);
}


bool removeLast(DoubleLinkedList *list, Item *item) {

  if(isEmpty(list)) {
    return(false);
  }

  if(sizeOfList(list) == 1) {
    return(removeFirst(list, item));
  }

  Pointer aux;
  for(aux = list->first; aux->next->next !=NULL; aux = aux->next);

  Pointer remove = aux->next;
  *item = remove->element;
  aux->next = NULL;
  free(remove);

  printf("@Elemento: %d removido\n", (*item).key);
  list->size--;

  return(true);
}


Item first(DoubleLinkedList *list) {
  Item x = list->first->element;
  return(x);
}


Item last(DoubleLinkedList *list) {
  Pointer ptr;
  for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);
  Item x = ptr->element;
  return(x);
}
