#include<stdio.h>
#include<stdlib.h>
#include <time.h>       /* time */

//---------------------------------
//---------------------------------

void imprimeVetor(int *vetor, int tamanho) {
  int i;
  printf("Vetor = [");
  for(i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("]\n");
}

//---------------------------------
//---------------------------------

void preencheVetor(int *vetor, int tamanho) {
  int i;
  for(i = 0; i < tamanho; i++) {
    printf("Insira valor:");
    scanf("%d", &vetor[i]);
  }
}
void preencheVetorAutomaticamente(int *vetor, int tamanho) {
  int i;
  for(i = 0; i < tamanho; i++) {
    // gerar numeros aleatorios
    vetor[i] = rand() % 10;
  }
}


//---------------------------------
//---------------------------------

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int N;
  printf("Informar qtde elementos:");
  scanf("%d", &N);
  printf(" Qtde = %d\n", N);
  int *vet;
  vet = malloc(N * sizeof(int));
  imprimeVetor(vet, N);
//  preencheVetor(vet, N);
  preencheVetorAutomaticamente(vet, N);
  imprimeVetor(vet, N);
  free(vet);
  return 0;
}
