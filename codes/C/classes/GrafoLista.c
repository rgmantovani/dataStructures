//---------------------------------------------------------
//---------------------------------------------------------

#include <stdio.h>
#include "ListaDuplamenteEncadeada.h"

//---------------------------------------------------------
//---------------------------------------------------------

typedef struct {
  int vertices;
  int arestas;
  bool dirigido;
  ListaDupla* vetor;
} GrafoLista;

//---------------------------------------------------------
//---------------------------------------------------------

void iniciaGrafoLista(GrafoLista *g, int V, bool dir) {
  g->vertices = V;   //  int vertices;
  g->arestas  = 0;   //  int arestas;
  g->dirigido = dir; //  bool dirigido;
  // ListaDupla* vetor;
  // vetor dinamico
  // alocar a memoria do vetor de listas (V)
  g->vetor = malloc(V * sizeof(ListaDupla));
  // inicializar cada lista contida na posicao do vetor
  for(int i = 0; i < V; i++) {
    iniciaListaDupla(&(g->vetor[i]));
  }
}

//---------------------------------------------------------
//---------------------------------------------------------

void insereArestaGrafoLista(GrafoLista* g, int v1, int v2) {

  // vertices que nao existem
  if(v1 < 0 || v1 > (g->vertices-1) || v2 < 0 || v2 > (g->vertices-1)) {
    printf("Warning: um dos vértices não existe\n");
    return;
  }

  printf("Debug: v1 = %d, v2 = %d\n", v1, v2);
  // verifica se a aresta ja existe
  if(procuraListaDupla(&(g->vetor[v1]), v2)) {
    printf("Warning: aresta já existe!\n");
    return;
  }

  // acessar o vetor na posicao v1 (lista), add o valor v2
  insereListaDupla(&(g->vetor[v1]), v2);
  // nao dirigido?
  // acessar o vetor na posicao v2 (lista), add o valor v1
  if(!g->dirigido) {
    insereListaDupla(&(g->vetor[v2]), v1);
  }
  g->arestas++;
}

//---------------------------------------------------------
//---------------------------------------------------------

void destruirGrafoLista(GrafoLista *g) {

  // as listas (destruir Lista) - Varias
  for(int i = 0; i < g->vertices; i++) {
    destroiListaDupla(&(g->vetor[i]));
  }
  free(g->vetor);
}

//---------------------------------------------------------
//---------------------------------------------------------

void imprimeGrafoLista(GrafoLista * g) {
  // para cada vertice, imprimir a lista
  for(int i = 0; i < g->vertices; i++) {
    printf("Ajd(%d): ", i);
    imprimeListaDupla(&(g->vetor[i]));
  }
}

//---------------------------------------------------------
//---------------------------------------------------------

int main(int argc, const char * argv[]) {
  GrafoLista g;
  iniciaGrafoLista(&g, 6, true);
  imprimeGrafoLista(&g);
  printf("------------------\n");
  insereArestaGrafoLista(&g, 0, 1);  //1, 2
  insereArestaGrafoLista(&g, 0, 4);  //1,5
  insereArestaGrafoLista(&g, 1, 3);  // 2,4
  insereArestaGrafoLista(&g, 2, 3);  //3, 4
  insereArestaGrafoLista(&g, 2, 5);  //3, 6
  insereArestaGrafoLista(&g, 3, 4);  //4,5
  insereArestaGrafoLista(&g, 4, 1);  // 5,2
  insereArestaGrafoLista(&g, 5, 5);  //6,6
  printf("------------------\n");
  imprimeGrafoLista(&g);
  printf("------------------\n");

//  int N, *vet;
//  for(int id = 0; id < g.vertices; id++) {
//    vet = consultaAdjacentesGrafoMatriz(&g, id, &N);
//    imprimeAdjacentesGrafoMatriz(vet, N, id);
//    printf("------------------\n");
//  }
  destruirGrafoLista(&g);
//  printf("Olá!!!\n");
  return 0;
}
