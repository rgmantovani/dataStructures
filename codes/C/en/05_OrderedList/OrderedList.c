//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "OrderedList.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initOrderedList(OrderedList *list) {
  list->first = NULL;
  list->size  = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyOrderedList(OrderedList *list) {
  return(list->first == NULL);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfOrderedList(OrderedList *list){
  return(list->size);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyOrderedList(OrderedList *list) {
  printf("@Destroying list!\n");
  PtrNodeList toRemove;
  while(list->first!= NULL) {
    toRemove = list->first;;
    list->first = list->first->next;
    free(toRemove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printOrderedList(OrderedList *list) {
  PtrNodeList ptr;
  printf(" [*] List:{ ");
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool searchOrderedList(OrderedList *list, int x) {

  if(isEmptyOrderedList(list))  return false;

  PtrNodeList ptr;
  for(ptr = list->first; ptr != NULL; ptr = ptr->next) {
    if(ptr->x == x) return true;
  }
  return false;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool searchFasterOrderedList(OrderedList *list, int x) {
  
  if(isEmptyOrderedList(list))  return false;

  PtrNodeList ptr;
  for(ptr = list->first; ptr->next != NULL && x > ptr->x; ptr = ptr->next);
  if(ptr == NULL || ptr->x > x) return false;
  
  return true;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void insertOrderedList(OrderedList *list, int x) {

  PtrNodeList new = (PtrNodeList)malloc(sizeof(NodeList));
  new->x = x;
  
  /* first insertion or value lower than the first */
  if(isEmptyOrderedList(list) || (x < list->first->x)) {
    new->next = list->first;
    list->first = new;
  } else {
   
    PtrNodeList aux = list->first;
    while(aux->next != NULL && x > aux->next->x) {
      aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
  }
  list->size++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removeFirstOrderedList(OrderedList *list, int *x) {
  if(!isEmptyOrderedList(list)) {
    PtrNodeList aux = list->first;
    *x = aux->x;
    list->first = list->first->next;
    free(aux);
    list->size--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removeLastOrderedList(OrderedList *list, int *x) {
  
  if(!isEmptyOrderedList(list)) {
    
    if(sizeOfOrderedList(list) == 1) {
      removeFirstOrderedList(list, x);
    }
    else
    {
      PtrNodeList aux = list->first;
      for(aux = list->first; aux->next->next !=NULL; aux = aux->next);
    
      PtrNodeList remove = aux->next;
      *x = remove->x;
      aux->next = NULL;
      free(remove);
      list->size = list->size-1;
    }
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void removeOrderedList(OrderedList *list, int key, int *x){
  
  /* empty list or the value lower than the first */
  if(isEmptyOrderedList(list) || key < list->first->x) return;
  
  if(key == list->first->x) {
    removeFirstOrderedList(list, x);
  } else {
      
    PtrNodeList aux = list->first;
    while((aux->next != NULL) && (key > aux->next->x)) {
      aux = aux->next;
    }
      
    if((aux->next == NULL) || (key < aux->next->x)) {
      return;
    }
    
    PtrNodeList toRemove = aux->next;
    aux->next = aux->next->next;
    list->size--;
    free(toRemove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int firstOrderedList(OrderedList *list) {
  return(list->first->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int lastOrderedList(OrderedList *list) {
  PtrNodeList ptr;
  for(ptr = list->first; ptr->next != NULL; ptr = ptr->next);
  return(ptr->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
