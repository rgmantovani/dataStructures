#include <stdio.h>
#include "GrafoMatrizes.h"

int main(int argc, const char * argv[]) {
  
  GrafoMatriz g;
  
  iniciaGrafoMatriz(&g, 6, true);

  imprimeGrafoMatriz(&g);
  
  insereArestaGrafoMatriz(&g, 0, 1);
  insereArestaGrafoMatriz(&g, 0, 4);
  insereArestaGrafoMatriz(&g, 1, 3);
  insereArestaGrafoMatriz(&g, 2, 3);
  insereArestaGrafoMatriz(&g, 2, 5);
  insereArestaGrafoMatriz(&g, 3, 4);
  insereArestaGrafoMatriz(&g, 4, 1);
  insereArestaGrafoMatriz(&g, 5, 5);
  
  imprimeGrafoMatriz(&g);
  
  removeArestaGrafoMatriz(&g, 0, 4);
  
  imprimeGrafoMatriz(&g);
  
  if(!verificaAdjacencia(&g, 0, 4)) {
    printf("Vertices não são adjacentes.\n");
  }

  int cont, *v;
  int query;

  for(int i = 0; i < 6; i++) {
    query = i;
    v = retornarAdjacentes(&g, query, &cont);
    printf("Adjacentes(%d) = {", query);
    for(int i = 0; i < cont; i++) {
      printf("%d ", v[i]);
    }
    printf("}\n");
  }
  
  destruirGrafoMatriz(&g);
  return 0;
}

