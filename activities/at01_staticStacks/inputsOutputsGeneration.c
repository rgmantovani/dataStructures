#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void dec2bin(int n, FILE * arq) {
  if (n == 0) {

  }
  else {
    dec2bin(n / 2, arq);
    fprintf(arq, "%d", n % 2);
  }
}

int randomInteger (int low, int high){
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - low + 1);
    return low + k;
}


int main(){ 
  int arqNumber = 0;
  printf("Qual arquivo de entrada deseja criar (Os arquivos vao de 0 ate 9 no maximo)\n");
  printf("Exemplo: Entrada 1 : DIGITE \"1\": ");
  scanf("%d", &arqNumber);
  fflush(stdin);

  FILE* arq = NULL;

  switch(arqNumber){
    case 0:
      arq = fopen("entrada0.txt ", "w+");
      break;

    case 1:
      arq = fopen("entrada01.txt ", "w+");
      break;

    case 2:
      arq = fopen("entrada02.txt ", "w+");
      break;

    case 3:
      arq = fopen("entrada03.txt ", "w+");
      break;

    case 4:
      arq = fopen("entrada04.txt ", "w+");
      break;

    case 5:
      arq = fopen("entrada05.txt ", "w+");
      break;

    case 6:
      arq = fopen("entrada06.txt ", "w+");
      break;

    case 7:
      arq = fopen("entrada07.txt ", "w+");
      break;

    case 8:
      arq = fopen("entrada08.txt ", "w+");
      break;

    case 9:
      arq = fopen("entrada09.txt ", "w+");
      break;
    default:
      break;
  }

  char tipoPilha;

  printf("A pilha é dinamica ou estatica? \n Digite \"d\" para dinamica e \"e\" para estatica: \n");
  scanf("%c", &tipoPilha);
  fprintf(arq, "%c\n", tipoPilha);
  fflush(stdin);

  int linhasArquivo = 0;

  printf("Quantas linhas o arquivo deve ter? \n");
  scanf("%d", &linhasArquivo);
  fflush(stdin);

  int menorIntervalo = 0;
  int maiorIntervalo = 0;

  printf("Digite agora o intervalo que deve ser gerado os numeros aleatorios: \n");
  printf("Digite O MENOR numero do intervalo: \n");
  scanf("%d", &menorIntervalo);
  fflush(stdin);

  printf("Digite O MAIOR numero do intervalo: \n");
  scanf("%d", &maiorIntervalo);
  fflush(stdin);

  char tipoNumeros;

  printf("O arquivo deve ser composto por numeros inteiros, flutuantes ou binarios?\n");
  printf("Digite \"i\" para inteiros e \"b\" para binarios:\n");
  scanf("%c", &tipoNumeros);
  fflush(stdin);

  switch(tipoNumeros){
    case 'i':
      for (size_t i = 0; i < linhasArquivo; i++) {
        fprintf(arq, "%d\n", randomInteger(maiorIntervalo, menorIntervalo));
        for(size_t j = 0; j < (rand() % 100); j++);
    
      }
      break;

    case 'b':
      for (size_t i = 0; i < linhasArquivo; i++) {
        dec2bin(randomInteger(maiorIntervalo, menorIntervalo), arq);
        fprintf(arq, "\n");
        for(size_t j = 0; j < (rand() % 100); j++);
    
      }
      break;
  }
  
}