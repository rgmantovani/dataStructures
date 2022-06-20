#include <stdio.h>

// ---------------------------------
// A 'MAGICA' está aqui
// ---------------------------------

// Definimos os arquivos como variaveis globais, fora de qlquer função
// todo mundo visualiza eles, e pode editar/alterar/usar/tocar o terror
FILE *arqEntrada;
FILE *arqSaida;

// ---------------------------------
// ---------------------------------

void escreveNoArquivo() {
  // fazer uma lógica só p copiar os valores do arq de entrada p arq de arqSaida
  char string[100];

  while(!feof(arqEntrada)) {
    if(fgets(string, 100, arqEntrada)!= NULL) {
      // ver no console se lemos direito
      printf("%s", string);
      // gravar no arquivo de saida
      fprintf(arqSaida, "%s", string);
    }
  }
}


// ---------------------------------
// ---------------------------------

int main(int argc, char* argv[]) {

  //Na main, vc simplemente usa eles de boas, pq eles as variaveis ja
  // estao definidas la em cima
  // se precisar argv, substituimos os nomes fixos pelos argv
  arqEntrada = fopen("entrada.txt"/*argv[1]*/, "r");
  arqSaida   = fopen("saida.txt" /*argv[2]*/,"w");

  if(arqEntrada == NULL || arqSaida == NULL) {
    printf("Deu zica na abertura de algum dos arquivos!\n");
    return 1;
  }

  // chama a função que grava a parada
  escreveNoArquivo();

  // no final, fecha os arquivos tb
  fclose(arqEntrada);
  fclose(arqSaida);

  return 0;
}

// ---------------------------------
// ---------------------------------
