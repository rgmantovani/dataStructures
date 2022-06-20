#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// -----------------------------
// -----------------------------

typedef struct {
  int **matriz;  // por os 0s e 1s
  int vertices;  // qtde de vertices
  int arestas;   // qtde de arestas
  bool dirigido; // se é dirigido ou não
} GrafoMatriz;

// -----------------------------
// -----------------------------

void iniciaGrafoMatriz(GrafoMatriz *g, int V, bool dir) {
  int i, j;

  g->vertices = V;   // vertices
  g->arestas = 0;    // arestas
  g->dirigido = dir; // dirigido

  // alocando memoria da matriz
  g->matriz = malloc(V * sizeof(int*));
  for(i = 0; i < V; i++) {
    g->matriz[i] = malloc(V * sizeof(int));
  }

  // inicializa toda as celulas como 0
  for(i = 0; i < V; i++) {
    for(j = 0; j< V; j++) {
      g->matriz[i][j] = 0;
    }
  }

}

// -----------------------------
// -----------------------------

void imprimeGrafoMatriz(GrafoMatriz *g) {
  int i, j, V;
  V = g->vertices;
  // inicializa toda as celulas como 0
  for(i = 0; i < V; i++) {
    printf("%d: ", i);
    for(j = 0; j< V; j++) {
      printf("%d ", g->matriz[i][j]);
    }
    printf("\n");
  }
}

// -----------------------------
// -----------------------------

void insereArestaGrafoMatriz(GrafoMatriz *g, int v1, int v2) {
  g->matriz[v1][v2] = 1;
  if(!g->dirigido) {
    g->matriz[v2][v1] = 1;
  }
  g->arestas++;
}

// -----------------------------
// -----------------------------

void removeArestaGrafoMatriz(GrafoMatriz *g, int v1, int v2) {

  g->matriz[v1][v2] = 0;
  if(!g->dirigido) {
    g->matriz[v2][v1] = 0;
  }
  g->arestas--;
}

// -----------------------------
// -----------------------------

int* consultaAdjacentesGrafoMatriz(GrafoMatriz *g, int x, int *N) {

  int *adjacentes;
  (*N) = 0;
  // X = indice do vertice quer consultar os adjacentes
  if(x < 0 || x > (g->vertices)-1) {
    printf("Warning: indice do vertice não existe!\n");
    return (NULL);
  }

  int contador = 0;
  // contar a qtde de adjacentes do vertice x (N)
  for(int i = 0; i < g->vertices; i++) {
    if(g->matriz[x][i] == 1) {
      contador++;
    }
  }

  // Não tem adjacentes
  if(contador == 0) return (NULL);

  // ja sabe qtde de adjacentes do vertice x (contador)
  // aloca a memoria de um vetor de tamanho N
  (*N) = contador;
  adjacentes = malloc(contador * sizeof(int));

  // percorre a linha, e salva os idx das colunas cujos valores sao 1
  int posicao = 0;
  for(int i = 0; i < g->vertices; i++) {
    if(g->matriz[x][i] == 1) {
      adjacentes[posicao] = i;
      posicao++;
    }
  }
  // retorna o vetor, e (refencia p qtde de elementos)
  return(adjacentes);
}

// -----------------------------
// -----------------------------

void imprimeAdjacentesGrafoMatriz(int* vet, int N, int id) {
  printf("Numero de adjacentes: %d\n", N);
  printf("Adjacentes(%d) = [", id);
  for(int k = 0; k < N; k++) {
    printf("%d ", vet[k]);
  }
  printf("]\n");
}

// -----------------------------
// -----------------------------

void destruirGrafoMatriz(GrafoMatriz *g) {
  for(int i = 0; i < g->vertices; i++) {
    free(g->matriz[i]);
  }
  free(g->matriz);
}

// -----------------------------
// -----------------------------

int main(int argc, const char * argv[]) {
  GrafoMatriz g;
  iniciaGrafoMatriz(&g, 6, true);
  imprimeGrafoMatriz(&g);
  printf("------------------\n");
  insereArestaGrafoMatriz(&g, 0, 1);  //1, 2
  insereArestaGrafoMatriz(&g, 0, 4);  //1,5
  insereArestaGrafoMatriz(&g, 1, 3);  // 2,4
  insereArestaGrafoMatriz(&g, 2, 3);  //3, 4
  insereArestaGrafoMatriz(&g, 2, 5);  //3, 6
  insereArestaGrafoMatriz(&g, 3, 4);  //4,5
  insereArestaGrafoMatriz(&g, 4, 1);  // 5,2
  insereArestaGrafoMatriz(&g, 5, 5);  //6,6
  printf("------------------\n");
  imprimeGrafoMatriz(&g);
  printf("------------------\n");

  int N, *vet;
  for(int id = 0; id < g.vertices; id++) {
    vet = consultaAdjacentesGrafoMatriz(&g, id, &N);
    imprimeAdjacentesGrafoMatriz(vet, N, id);
    printf("------------------\n");
  }
  destruirGrafoMatriz(&g);
  printf("\n\n\n\n\n\n\n");
  return 0;
}

// -----------------------------
// -----------------------------
