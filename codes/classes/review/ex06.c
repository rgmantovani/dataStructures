#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
  char naipe;
  char simbolo;
  bool foiJogada;
} Carta;

typedef struct {
  Carta baralho[4][13];
  int totalNaipes;
  int totalSimbolos;
  int qtdeCartas;
} Baralho;

//---------------------------------
//---------------------------------

void imprimeCarta(Carta *cd) {
  printf("[S:%c,N:%c,J:%d]", cd->simbolo, cd->naipe, cd->foiJogada);
}

void imprimeBaralho(Baralho *bar) {
  int i, j;
  // simbolos
  for(j = 0; j < 13; j++) {
    for(i = 0; i < 4; i++) {
      Carta temp = bar->baralho[i][j];
      imprimeCarta(&temp);
    }
    printf("\n");
  }
}

//---------------------------------
//---------------------------------

void iniciaBaralho(Baralho *bar) {

  char simbolos[13] = {'A','2','3','4',
    '5','6','7','8','9','D','J','Q','K'};
  char naipes[4]  = {'P','C','E','O'};

  int i, j;
  // naipes
  for(i = 0; i < 4; i++) {
      // simbolos
    for(j = 0; j < 13; j++) {
      bar->baralho[i][j].naipe = naipes[i] ;
      bar->baralho[i][j].simbolo = simbolos[j];
      bar->baralho[i][j].foiJogada = false; //0
    }
  }
}
//---------------------------------
//---------------------------------

int qtdeCartasNaoJogadas(Baralho *bar) {
  int cont = 0;
  for(int i=0; i<4;i++) {
    for(int j=0; j<13; j++) {
      Carta cd = bar->baralho[i][j];
      if(!cd.foiJogada) {
        cont++;
      }
    }
  }
  return (cont);
}

//---------------------------------
//---------------------------------

int main(int argc, char* argv[]) {

  Carta c;
  c.simbolo = 'Q';
  c.naipe   = 'E';

//  imprimeCarta(&c);

  Baralho deck;
  iniciaBaralho(&deck);
  imprimeBaralho(&deck);

  int pacoca = qtdeCartasNaoJogadas(&deck);
  printf("-------------------\n");
  printf("*** Cartas não jogadas = %d\n", pacoca);
  printf("-------------------\n");

  return 0;
}
