#define N 10

typedef struct {
   int vetor[N];  //vetor com 10 elementos inteiros
   int topo;       //controla o topo da pilha
} PilhaEstatica;

// iniciar a pilha
void iniciaPe(PilhaEstatica *p) {
 p->topo = 0;
}

//tamanho da pilha
int tamanhoPe(PilhaEstatica *p) {
 return(p->topo);
}

void imprimePe(PilhaEstatica *p) {
 int i = 0;
 printf("Pilha = {");
 for(i = 0; i < p->topo; i++) {
   printf("|%d| ", p->vetor[i]);
 }
 printf("}\n");
}

bool estaVaziaPe(PilhaEstatica *p) {
 return(p->topo == 0);
}

bool estaCheiaPe(PilhaEstatica *p) {
 return(p->topo == N);
}

void empilharPe(PilhaEstatica *p, int valor) {
 if(!estaCheiaPe(p)){
   p->vetor[p->topo] = valor;
   p->topo++; /* p->topo = p->topo + 1 */
 } else {
   printf("Warning: nao inserido porque está cheia\n");
 }
}

int desempilharPe(PilhaEstatica *p) {
 int x = -1;
 if(!estaVaziaPe(p)){
   x = p->vetor[p->topo-1];
   p->topo--;
 } else{
   printf("Warning: nao removido porque esta vazia\n");
 }
 return(x);
}


int main(int argc, const char * argv[]) {
 PilhaEstatica p;

 iniciaPe(&p);
 imprimePe(&p);

 if(estaVaziaPe(&p)) {
   printf("Aviso: está vazia\n");
 }

 /* 10, 15 */
 empilharPe(&p, 10);
 //imprimePilha(&p);

 empilharPe(&p, 15);
 //imprimePilha(&p);

 // tentanto inserir 9 elementos (8)
 int i;
 for(i = 0; i < 9; i++) {
   empilharPe(&p, i+11);
 }
 imprimePe(&p);
 empilharPe(&p, 42);
 printf("Tamanho = %d\n", tamanho(&p));

 int x;
 x = desempilharPe(&p);
 x = desempilharPe(&p);
 imprimePe(&p);

 return 0;
}
