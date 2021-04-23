
#include <stdio.h>

 // <nome_arquivo> <entrada>.txt <saida>.txt
int main(int argc, const char * argv[]) {

   // argc - confere o numero de parametros na linha de comando
   if(argc != 3) {
     printf("Numero de parametros não é o correto\n");
     return 1;
     // exit(1);
     // acaba execucao
   }

   // EXIT_FAILURE - 1
   // EXIT_SUCCESS - 0

   printf("Argv[0]: %s\n", argv[0]);
   printf("Argv[1]: %s\n", argv[1]);
   printf("Argv[2]: %s\n", argv[2]);

   // argv[1] // nome do arquivo de entrada
   // argv[2] // nome do arquivo de saida

   FILE *in, *out;
   // in  = fopen("meuarquivo.txt", "r");
   // out = fopen("saida.txt", "w");
   in  = fopen(argv[1], "r");
   out = fopen(argv[2], "w");

   // criou ou nao os arquivos
   if(in == NULL || out == NULL) {
     //erro
     return(1);
   }

   char palavra[50];
   fscanf(in, "%s\n", palavra);
   printf("Palavra = %s\n", palavra);

   fprintf(out, "%s\n", palavra);

   fclose(in);
   fclose(out);

   printf("Hello, World!\n");
   return 0;
}
