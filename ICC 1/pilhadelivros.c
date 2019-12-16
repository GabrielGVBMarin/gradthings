#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  char nome_do_livro[100];
  char autor[100];
  int numero_de_paginas;
} registro;

void imprime_tudo();

int main(void)  {

  int quantidade, op, i=0;
  scanf("%d", &quantidade);
  registro *vetor;
  vetor = (registro*) malloc(quantidade*sizeof(registro));

  while(1)  {
    scanf("%d", &op);
    switch (op) {
      case 0:
      exit(1);
      break;
      case 1:
        if ( i == quantidade) {
          printf("Pilha cheia\n\n");
          exit(1);
        }
        scanf("%s", vetor[i].nome_do_livro);
        scanf("%s", vetor[i].autor);
        scanf("%d", &vetor[i].numero_de_paginas);
        i++;
      break;
      case 2:
        i--;
        imprime_tudo(vetor[i]);
        *vetor[i].nome_do_livro = 0;
        *vetor[i].autor = 0;
        vetor[i].numero_de_paginas = 0;
      break;
      case 3:
        if ( i == 0)  {
          printf("Pilha vazia\n\n");
          exit(1);
        }
        imprime_tudo(vetor[i-1]);
      break;
    }
  }
  return 0;
}

void imprime_tudo(registro docs) {
  printf("Nome: %s\n", docs.nome_do_livro);
  printf("Autor: %s\n", docs.autor);
  printf("Nro Paginas: %d\n\n", docs.numero_de_paginas);
}
