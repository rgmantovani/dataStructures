
#include <stdio.h>
#include <stdbool.h> // true / false

void converte(int totalMinutos, int* hora, int* minutos) {

  if(totalMinutos < 0) {
    printf("Warning: o valor de minutos nao pode ser negativo!\n");
    *hora = 0;
    *minutos = 0;
  } else {
    *hora = totalMinutos / 60;
    *minutos = totalMinutos % 60;
  }
}

int main(int argc, const char * argv[]) {
  int h, m;
  converte(100, &h, &m);
  printf("Hora: %d , Minutos: %d\n",h,m);
  return 0;
}
