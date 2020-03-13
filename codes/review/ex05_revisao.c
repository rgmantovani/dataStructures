//---------------------------------------------
// EX 05 - Revisao
//---------------------------------------------

#include <stdio.h>

#define tamanhoNome   50
#define tamanhoGenero 50

typedef struct{
    char nome[tamanhoNome];
    char genero[tamanhoGenero];
    int integrantes;
    int rk;
} Banda;

//---------------------------------------------
// Funcao de entrada dos dados. Recebe:
//- *vetor: ponteiro para vetor de banda
//- n: tamanho do vetor
//---------------------------------------------

void preencheVetor(Banda *vetor, int n){

  printf("---------------------------\n");
  printf(" *** Leitura dos dados *** \n");
  printf("---------------------------\n");

  for(int i = 0; i < n; i++) {

    printf("Nome da banda: ");
    setbuf(stdin, NULL);                          // limpa o buffer
    fgets(vetor[i].nome, tamanhoNome, stdin);     // le a string

    printf("Genero da banda: ");
    setbuf(stdin, NULL);                          // limpa o buffer
    fgets(vetor[i].genero, tamanhoGenero, stdin); // le a string

    printf("Nro de integrantes: ");
    scanf("%d", &vetor[i].integrantes);
    vetor[i].rk = i+1;
    printf("\n");
  }
  printf("---------------------------\n");
}

//---------------------------------------------
// Funcao de impressao dos dados. Recebe:
//- *vetor: ponteiro para vetor de banda
//- n: tamanho do vetor
//---------------------------------------------

void imprimeVetor(Banda *vetor, int n) {

  printf("---------------------------\n");
  printf(" *** Impressao dos dados *** \n");
  printf("---------------------------\n");

  for(int i = 0; i < n; i++) {
    printf("Ranking: %d\n", vetor[i].rk);
    printf("Nome da banda:%s", vetor[i].nome);
    printf("Genero da banda: %s", vetor[i].genero);
    printf("Nro de integrantes: %d\n\n", vetor[i].integrantes);
  }

  printf("---------------------------\n");
}

//---------------------------------------------
// Funcao de consulta. Recebe:
//- *vetor: ponteiro para vetor de banda
//- n: tamanho do vetor
//- posicao: posicao do ranking para ser impressa
//---------------------------------------------

void consultaVetor(Banda *vetor, int n, int posicao) {

  posicao = posicao - 1;

  if(posicao < 0 || posicao > (n-1)) {
    printf(" - Posicao invalida! \n");
  } else {
    printf(" *** Valores encontrados *** \n");
    printf("Ranking: %d\n", vetor[posicao].rk);
    printf("Nome da banda:%s", vetor[posicao].nome);
    printf("Genero da banda: %s", vetor[posicao].genero);
    printf("Nro de integrantes: %d\n\n", vetor[posicao].integrantes);
  }
  printf("---------------------------\n");
}


//---------------------------------------------
// funcao principal
//---------------------------------------------

 int main(int argc, const char * argv[]) {

  int opcao;
  int N = 5;

  //criamos um vetor de Bandas aqui
  Banda vetor[N];

  //chamamos uma funçao para preencher o vetor (usando ponteiros)
  preencheVetor(&vetor[0], N);

  //podemos checar os valores dentro do vetor
  imprimeVetor(&vetor[0], N);

  //e consultar alguma posicao do vetor
  printf(">>> Digite uma posicao para consultar o valor ou 9 para encerrar: ");
  scanf("%d", &opcao);
  while(opcao != 9) {
    consultaVetor(&vetor[0], N, opcao);
    scanf("%d", &opcao);
  }

  printf("Fim de execucao\n");
  return 0;
}

//---------------------------------------------
//---------------------------------------------
