#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//---------------------------------------------------
// Tipos
//---------------------------------------------------

// NoArvore* PtrNoArvore -> PtrNoArvore* (**NoArvore)
typedef struct NoArvore* PtrNoArvore;

// NoArvore (struct)
typedef struct NoArvore {
  // info
  int x;
  // ponteiro p filho esquerda
  PtrNoArvore esquerda;
  // ponteiro p filho direita
  PtrNoArvore direita;
} NoArvore;

//---------------------------------------------------
// Funções
//---------------------------------------------------

//inicia arvore
void iniciaArvore(PtrNoArvore *node) {
  (*node) = NULL;
}

// esta vazia
bool estaVaziaArvore(PtrNoArvore *node) {
  return ((*node) == NULL);
}

//---------------------------------------------------
// Inserção (Raiz, x) - Booleana (true/false)
//---------------------------------------------------

// quando eu acho o ponto de inserção:
// Criterio de parada da recursao (sucesso - true)
//  cria o no (aloca memoria)
//  copia o valor que será inserido dentro do no
//  filho direita = NULL
//  filho esqueda = NULL

// se cheguei em um node == x (fracasso - false)
// warning
// nao faz nada

// Percurso (se mover na arvore) -> recursao
// Obs 1: se x > valor no no corrente (node) -> ir direita
// ir direita -> recursao p subarvore direita (node->direita)
// Obs 2: se x < valor no no corrente (node) -> ir esquerda
// ir esquerda -> recursao p subarvore esquerda (node->esquerda)

bool insereArvore(PtrNoArvore *node, int x) {
  // criterio parada recursao (sucesso)
  if((*node) == NULL) {
    (*node) = (PtrNoArvore)malloc(sizeof(NoArvore));
    (*node)->x = x;
    (*node)->direita = (*node)->esquerda = NULL;
    return(true);
  }

  // criterio parada fracasso (false)
  if((*node)->x == x) {
    printf("Warning: chave já existente\n");
    return (false);
  }

  // percorrer a arvore (via recursão)
  // valor > valor no -> direita
  if(x > (*node)->x) {
    return (insereArvore(&(*node)->direita, x));
  }
  // valor < valor no -> esquerda
  else {
    return (insereArvore(&(*node)->esquerda, x));
  }
}
//---------------------------------------------------
//---------------------------------------------------

// (booleana) pesquisa(A, x) -> true/false

bool pesquisaArvore(PtrNoArvore *node, int x) {

  // fim de recursão (parada)
  // se eu atingir (*node) == NULL -> falso (nao existe)
  if( (*node) == NULL) return(false);

  // achei o elemento
  // se (*node)->x == x -> verdadeiro (existe)
  if( (*node)->x == x) return (true);

  // recursao
  if(x > (*node)->x) {
    // chamar p filho direita
    return(pesquisaArvore(&(*node)->direita, x));
  } else {
    // chamar p filho esquerda
    return(pesquisaArvore(&(*node)->esquerda, x));
  }
}

//9 linhas
//bool pesquisaArvore(PtrNoArvore *node, int x) {
//  if( (*node) == NULL) return(false);
//  if( (*node)->x == x) return (true);
//  if(x > (*node)->x) {
//    return(pesquisaArvore(&(*node)->direita, x));
//  } else {
//    return(pesquisaArvore(&(*node)->esquerda, x));
//  }
//}


//---------------------------------------------------
// remoção arvore binária
//---------------------------------------------------

PtrNoArvore getMaxAux(PtrNoArvore *node) {
  PtrNoArvore ret;
  // criterio de parada da recursao
  // se o filho direita do nove == NULL
  // eu achei o maior elemento
  if((*node)->direita == NULL) {
    ret = (*node);
    (*node) = (*node)->esquerda;
    return(ret);
  }
  return (getMaxAux(&(*node)->direita));
}


bool removeArvore(PtrNoArvore *node, int x) {

  // criterio de parada de recursao (fracasso)
  // cheguei aonde o elemento deveria existir,
//  mas ele nao existe, logo nao tem o que remover
  if((*node) == NULL) return(false);

  // criterio de parada de sucesso (achei!)
  if((*node)->x == x) {

    PtrNoArvore tmp = (*node);

    // caso 1 - não tem subarvore da esquerda
    //        - tem subarvore da direita
    if((*node)->esquerda == NULL &&
       (*node)->direita != NULL) {
      //  node = filho direita do node
      (*node) = (*node)->direita;
    }
    // caso 2 - folha (nao tem subarvore direita)
    //                (nao tem subarvore esquerda)
    else if((*node)->esquerda == NULL &&
            (*node)->direita == NULL) {
      (*node) = NULL;
    }
    // caso 3 - não tem subarvore da direita
    //        - tem subarvore da esquerda

    else if((*node)->direita == NULL &&
            (*node)->esquerda != NULL) {
      // node = filho esquerda do node
      (*node) = (*node)->esquerda;
    }
    // caso 4 - tem subarvore da direita
    //        - tem subarvore da esquerda
    // como reogarnizar?
    //  a) menor numero da subarvore da direita
    //    getMinAux(&(*node)->direita)
    //  b) maior numero da subarvore da esquerda (*)
    //    getMaxAux(&(*node)->esquerda)
    else {
      // temp recebe a referencia do no que vai ser apagado
      tmp = getMaxAux(&(*node)->esquerda);
      (*node)->x = tmp->x;
    }
    printf("Elemento %d removido com sucesso\n", x);
    free(tmp);
    return true;
  }

  // recursiva
  // recursao
  if(x > (*node)->x) {
    // chamar p filho direita
    return(removeArvore(&(*node)->direita, x));
  } else {
    // chamar p filho esquerda
    return(removeArvore(&(*node)->esquerda, x));
  }
}


// otimizar o codigo -> {1,2}, {3}, {4}

//---------------------------------------------------
//---------------------------------------------------


// tamanho
// min/max

// preOrdem
void percursoPreOrdem(PtrNoArvore *node) {
  if((*node) == NULL) return;
  // imprime o valor do no
  printf("%d ", (*node)->x);
  // recursivo no esquerda
  percursoPreOrdem(&(*node)->esquerda);
  // recursivo no direita
  percursoPreOrdem(&(*node)->direita);
}

// posOrdem

void percursoPosOrdem(PtrNoArvore *node) {
  if((*node) == NULL) return;
  // recursivo no esquerda
  percursoPosOrdem(&(*node)->esquerda);
  // recursivo no direita
  percursoPosOrdem(&(*node)->direita);
  // imprime o valor do no
  printf("%d ", (*node)->x);
}

// emOrdem
void percursoEmOrdem(PtrNoArvore *node) {
  if((*node) == NULL) return;
  // recursivo no esquerda
  percursoEmOrdem(&(*node)->esquerda);
  // imprime o valor do no
  printf("%d ", (*node)->x);
  // recursivo no direita
  percursoEmOrdem(&(*node)->direita);
}

// emOrdem
void percursoEmOrdemContraria(PtrNoArvore *node) {
  if((*node) == NULL) return;
  // recursivo no esquerda
  percursoEmOrdemContraria(&(*node)->direita);
  // imprime o valor do no
  printf("%d ", (*node)->x);
  // recursivo no direita
  percursoEmOrdemContraria(&(*node)->esquerda);
}

//---------------------------------------------------
//---------------------------------------------------

//destrutor
void destroiArvore(PtrNoArvore *node) {
  if((*node) != NULL) {
    destroiArvore(&(*node)->esquerda);
    destroiArvore(&(*node)->direita);
    free(*node);
    *node = NULL;
  }
}


//---------------------------------------------------
//---------------------------------------------------

int main(int argc, const char * argv[]) {

  // arvore = referencia
  PtrNoArvore raiz;    // PtrNoArvore == NoArvore*

  // inicializacao da arvore
  iniciaArvore(&raiz);

  if(estaVaziaArvore(&raiz)) {
    printf("Árvore está vazia\n");
  }

  insereArvore(&raiz, 5);
  insereArvore(&raiz, 4);
  insereArvore(&raiz, 3);
  insereArvore(&raiz, 2);
  insereArvore(&raiz, 7);
  insereArvore(&raiz, 6);
  insereArvore(&raiz, 8);
  insereArvore(&raiz, 9);

  if(!estaVaziaArvore(&raiz)) {
    printf("Existem elementos aqui dentro\n");
  }

  // [5, 4, 3, 2, 7, 6, 8, 9]
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  // [2, 3, 4, 6, 9, 8, 7, 5]
  printf("Percurso PosOrdem = ");
  percursoPosOrdem(&raiz);
  printf("\n");

  // [2, 3, 4, 5, 6, 7, 8, 9]
  printf("Percurso EmOrdem =  ");
  percursoEmOrdem(&raiz);
  printf("\n");

  printf("Percurso EmOrdem2 = ");
  percursoEmOrdemContraria(&raiz);
  printf("\n");

  // consulta -> verificar se existem elementos dentro
//  da arvore

  // 2 a 9
  int consultas[7] = {15, 3, 7, 9, 4, 40, 99};
//  saida esperada =  F  V  V  V  V, F, F

  printf("-------------------------\n");
  for(int i = 0; i < 7; i++) {
    printf("Verificando: %d ->", consultas[i]);
    if(pesquisaArvore(&raiz, consultas[i])){
      printf(" achou\n");
    } else {
      printf(" não achou\n");
    }
  }
  printf("-------------------------\n");

  // [5, 4, 3, 2, 7, 6, 8, 9]
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");
  removeArvore(&raiz, 7); // tinhas duas subarvores
//  5, 4, 3, 2, 6, 8, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 5); // tinha duas subarvores
// 4, 3, 2, 6, 8, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 9); // folha
// 4, 3, 2, 6, 8
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 3); // sub-arvore direita é nula
// 4, 2, 6, 8
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 6); // sub-arvore esquerda é nula
// 4, 2, 8
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");


  printf("-------------------------\n");

  destroiArvore(&raiz);
  // raiz -> NULL

  if(estaVaziaArvore(&raiz)) {
    printf("Cortei a arvore!\n");
  }

  printf("-------------------------\n");
  return 0;
}

//---------------------------------------------------
//---------------------------------------------------
