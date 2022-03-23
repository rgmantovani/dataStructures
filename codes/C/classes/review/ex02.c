#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

bool verificaVogal(char c) {
  c = tolower(c); // sempre minusculo
  bool ret;
  ret = (c == 'a' || c == 'e' || c == 'o'
  || c == 'i'|| c == 'u');
  return(ret);
}

int main(int argc, char* argv[]) {

  FILE *arq1, *arq2;
  // argv[1] == entrada
  // argv[2] == saida
  arq1 = fopen(argv[1], "r");
  arq2 = fopen(argv[2], "w");

  if(arq1 == NULL || arq2 == NULL) {
    printf("Não foi possível abrir um dos arquivos\n");
    return 0;
  }

  // ler os dados do arquivo (entrada)
  char ch;
  int contador = 0;

  while(!feof(arq1)) {
    ch = fgetc(arq1);
    printf("%c", ch);
    // se o ch for vogal -> *
     if(verificaVogal(ch)) {
       fprintf(arq2, "%c", '*');
     } else {
       fprintf(arq2, "%c", ch);
       if(ch == '\n') {
         contador++;
        // contador = contador + 1;
       }
     }
  }
  fclose(arq1);
  fclose(arq2);
  printf("Quantidade de linhas do programa: %d\n", contador);
  return 0;
}
