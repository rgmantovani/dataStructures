#include <stdio.h>
#include "GraphMatrix.h"

int main(int argc, const char * argv[]) {
  
  GraphMatrix g;
  
  initGraphMatrix(&g, 6, true);

  printGraphMatrix(&g);
  
  insertEdgeGraphMatrix(&g, 0, 1);
  insertEdgeGraphMatrix(&g, 0, 4);
  insertEdgeGraphMatrix(&g, 1, 3);
  insertEdgeGraphMatrix(&g, 2, 3);
  insertEdgeGraphMatrix(&g, 2, 5);
  insertEdgeGraphMatrix(&g, 3, 4);
  insertEdgeGraphMatrix(&g, 4, 1);
  insertEdgeGraphMatrix(&g, 5, 5);
  
  printGraphMatrix(&g);
  
  removeEdgeGraphMatrix(&g, 0, 4);
  
  printGraphMatrix(&g);
  
  if(!isAdjacent(&g, 0, 4)) {
    printf("Vertices are not adjacent.\n");
  }

  int cont, *v;
  int query;

  for(int i = 0; i < 6; i++) {
    query = i;
    v = getAdjacents(&g, query, &cont);
    printf("Adjacents(%d) = {", query);
    for(int i = 0; i < cont; i++) {
      printf("%d ", v[i]);
    }
    printf("}\n");
  }
  
  destroyGraphMatrix(&g);
  return 0;
}
