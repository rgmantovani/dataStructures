#include <stdio.h>

int main(int argc, const char * argv[]) {
  
  // usando o argc 
  printf("Numero de parametros fornecidos: %d\n", argc);
  
  if(argc!= 3) {
    printf("Quantidade de parametros invalida\n");
    return 0;
  }  

  int i = 0;
  for(i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  FILE* entrada = fopen(argv[1], "r");
  FILE* saida   = fopen(argv[2], "w");

  // checar erros de abertura de arquivo
  if(entrada == NULL || saida == NULL) {
     printf("Erro: algum dos arquivos não pode ser criado corretamente\n");
     return 0;
  }

  char ch;
  while(!feof(entrada)) {
    // obtendo caracter do arquivo de entrada
    ch = fgetc(entrada);
    // escrever esse caracter no arquivo de saida (que vai ser criado)
    fprintf(saida, "%c", ch);
  }

  fclose(entrada);
  fclose(saida);
  // chamar o destrutor da pilha dinamica
  return 0;
}
