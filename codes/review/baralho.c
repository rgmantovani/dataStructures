//----------------------------------------------------------
//----------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>

//----------------------------------------------------------
// Definicao dos tipos
//----------------------------------------------------------

typedef struct {
  char valor;
  char naipe;
  bool jogada;
} Carta;

typedef struct  {
  Carta array[54];
} Baralho;

//----------------------------------------------------------
// variaveis globais
//----------------------------------------------------------

char naipes[4] = {'P','O','E','C'};
char valores[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'k'};


//----------------------------------------------------------
// assinatura dos metodos
//----------------------------------------------------------

void imprimeCarta(Carta c);
void imprimeBaralho(Baralho deck);
void criaBaralho(Baralho *deck);
Carta* topo(Baralho *deck);
Carta* fundo(Baralho *deck);
Carta* carteado(Baralho *deck);

//----------------------------------------------------------
//----------------------------------------------------------

int main(int argc, const char * argv[]) {
   
  Baralho baralho;
    
  printf("Antes:\n");
  imprimeCarta(baralho.array[0]);
  criaBaralho(&baralho);

  printf("\n\nDepois: \n");
//    imprimeBaralho(baralho);

  Carta *top = topo(&baralho);
  imprimeCarta(*top);

  return 0;
}

//----------------------------------------------------------
//----------------------------------------------------------

void imprimeCarta(Carta c) {
  printf("Valor = %c ", c.valor);
  printf("Naipe = %c ", c.naipe);
  printf("Jogada? = %d\n", c.jogada);
}

//----------------------------------------------------------
//----------------------------------------------------------

void imprimeBaralho(Baralho deck) {
  for(int i = 0; i < 54; i++){
    imprimeCarta(deck.array[i]);
  }
}

//----------------------------------------------------------
//----------------------------------------------------------

void criaBaralho(Baralho *deck) {
    
  int i;
  for(i = 0; i < 52; i++) {
        
    int valorId = i % 13;
    deck->array[i].valor = valores[valorId];
        
    int naipeId = i % 4;
    deck->array[i].naipe = naipes[naipeId];
        
    deck->array[i].jogada = false;
  }
    
  // inicializar coringas
  deck->array[52].valor = 'C';
  deck->array[52].naipe = ' ';
  deck->array[52].jogada = false;
    
  deck->array[53].valor = 'C';
  deck->array[53].naipe = ' ';
  deck->array[53].jogada = false;
}

//----------------------------------------------------------
//----------------------------------------------------------

Carta* topo(Baralho *deck) {
  
  for(int i = 53; i >=0; i--) {
    if(!deck->array[i].jogada){
      return(&deck->array[i]);
    }
  }
  printf("Não existe carta para ser consultada!");
  return(NULL);
}

//----------------------------------------------------------
//----------------------------------------------------------
