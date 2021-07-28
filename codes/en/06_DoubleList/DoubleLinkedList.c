//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "DoubleLinkedList.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initDoubleList(DoubleLinkedList *list) {
  list->first = NULL;
  list->size = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyDoubleList(DoubleLinkedList *list) {
  return (list->size == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfDoubleList(DoubleLinkedList *list) {
  return (list->size);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insertDoubleList(DoubleLinkedList *list, int x) {

  Pointer new = (Pointer) malloc(sizeof(NodeList));
  
  if(!new) {
    printf("@ The new node was not allocated \n");
    return (false);
  }
  new->element = x;
  printf("@ inserting the value: %d\n", x);

  /* first insertion */
  if(isEmptyDoubleList(list)) {
    new->next = NULL;
    new->previous = NULL;
    list->first = new;
  }
  /* inserting an element lower than the first */
  else if (x < list->first->element) {
    new->previous = NULL;
    list->first->previous = new;
    new->next = list->first;
    list->first = new;
  }
  /* finding the position to insert */
  else {
    Pointer aux;
    aux = list->first;
    while(aux->next != NULL && x > aux->next->element) {
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

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printDoubleList(DoubleLinkedList *list) {
  Pointer ptr;
  printf(" [*] List:{ ");
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->element);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printReverseDoubleList(DoubleLinkedList *list) {

  if(isEmptyDoubleList(list)) {
    printf(" [*] List:{ }\n");
  } else {
    Pointer ptr;
    for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);

    printf(" [*] List:{ ");
    Pointer aux = ptr;
    do {
      printf("%d ", aux->element);
      aux = aux->previous;
    } while(aux != NULL);
    printf("}\n");
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyDoubleList(DoubleLinkedList *list) {
  printf("@ Destroying double list!\n");
  Pointer remove;
  while((list->first)!= NULL) {
    remove = list->first;;
    list->first = list->first->next;
    list->size--;
    free(remove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool searchDoubleList(DoubleLinkedList *list, int key) {

  if(isEmptyDoubleList(list)) {
    return (false);
  }

  Pointer ptr;
  for(ptr = list->first; ptr->next != NULL && key > ptr->element; ptr = ptr->next);
  if(ptr == NULL || ptr->element > key) {
    return (false);
  }
  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeDoubleList(DoubleLinkedList *list, int key, int *item) {

  if(isEmptyDoubleList(list) || key < list->first->element) {
    return(false);
  }

  if(key == list->first->element) {
    return (removeFirstDoubleList(list, item));
  }

  Pointer aux = list->first;
  while((aux->next != NULL) && (key > aux->next->element)) {
    aux = aux->next;
  }

  if(aux->next == NULL || aux->next->element > key) {
    return (false);
  }

  Pointer remove = aux->next;
  *item = remove->element;

  if(aux->next->next != NULL) {
    aux->next->next->previous = aux;
  }
  aux->next = aux->next->next;
  list->size--;
  free(remove);
  printf("@Element: %d was removed\n", (*item));

  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeFirstDoubleList(DoubleLinkedList *list, int *item) {

  if(isEmptyDoubleList(list)) {
    return(false);
  }
  Pointer aux = list->first;
  *item = aux->element;

  list->first = list->first->next;
  list->first->previous = NULL;
  free(aux);
  list->size--;
  printf("@Element: %d was removed\n", (*item));

  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeLastDoubleList(DoubleLinkedList *list, int *item) {

  if(isEmptyDoubleList(list)) {
    return(false);
  }

  if(sizeOfDoubleList(list) == 1) {
    return(removeFirstDoubleList(list, item));
  }

  Pointer aux;
  for(aux = list->first; aux->next->next !=NULL; aux = aux->next);

  Pointer remove = aux->next;
  *item = remove->element;
  aux->next = NULL;
  free(remove);

  printf("@Element: %d was removed\n", (*item));
  list->size--;

  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int firstDoubleList(DoubleLinkedList *list) {
  int x = list->first->element;
  return(x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int lastDoubleList(DoubleLinkedList *list) {
  Pointer ptr;
  for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);
  int x = ptr->element;
  return(x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
