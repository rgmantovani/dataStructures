#include <stdio.h>
#include <string.h>
#include "TabelaHashArray.h"

int main(int argc, const char * argv[]) {

  TabelaHashArray tabelaHash;
  iniciaTabelaHahsArray(&tabelaHash);
  imprimeTabelaHashArray(&tabelaHash);

  ItemTabelaHash obj1 = {5, "Batima"};
  insereTabelaHashArray(&tabelaHash, &obj1);
  imprimeTabelaHashArray(&tabelaHash);

  ItemTabelaHash obj2 = {0, "Doente verde"};
  insereTabelaHashArray(&tabelaHash, &obj2);
  imprimeTabelaHashArray(&tabelaHash);

  ItemTabelaHash obj3 = {03, "Aranha-aranha"};
  insereTabelaHashArray(&tabelaHash, &obj3);
  imprimeTabelaHashArray(&tabelaHash);

  ItemTabelaHash obj4 = {14, "Formiga-homem"};
  insereTabelaHashArray(&tabelaHash, &obj4);
  imprimeTabelaHashArray(&tabelaHash);

  ItemTabelaHash obj5 = {21, "Felix-gato"};
  insereTabelaHashArray(&tabelaHash, &obj5);
  imprimeTabelaHashArray(&tabelaHash);

  printf("Tamanho da Tabela = %d\n", tamanhoTabelaHashArray(&tabelaHash));

  ItemTabelaHash consulta;
  int valores[] = {0, 3, 2};

  for(int i = 0; i < 3; i++) {
    if(pesquisaTabelaHashArray(&tabelaHash, valores[i], &consulta)) {
      printf(" [?](%d,%s)\n", consulta.chave, consulta.info);
    } else {
      printf("Elemento não encontrado\n");
    }
  }

  removeTabelaHashArray(&tabelaHash, 2);
  removeTabelaHashArray(&tabelaHash, 3);
  removeTabelaHashArray(&tabelaHash, 14);
  imprimeTabelaHashArray(&tabelaHash);

  destroiTabelaHashArray(&tabelaHash);
  if(estaVaziaTabelaHashArray(&tabelaHash)) {
    printf("Tabela foi destruída\n");
  }
  printf("=============================\n");

  return 0;
}
