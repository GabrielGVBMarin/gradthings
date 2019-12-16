#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//1 adiciona no vetor;
//2 retira um numero do vetor;
//3 consulta uma posicao no vetor;
//4 altera o valor de um numero;
void func_faz_a_brisa(int, int, int, int*, int*, int*);
enum op { adicionar = 1, remover, consultar, alterar };

int main()  {
  int opt1, opt2, opt3, quantidade_de_numeros = 0, *vetor, contador = 0, nemsei, vezes = 0;
  vetor = (int*) malloc(quantidade_de_numeros*sizeof(int));

  scanf("%d", &nemsei);

  do  {
    scanf("%d %d", &opt1, &opt2);
    if ( opt1 == 4 )  {
      scanf("%d", &opt3);
    }
    func_faz_a_brisa(opt1, opt2, opt3, vetor, &contador, &quantidade_de_numeros);
    vezes++;
  } while (vezes != nemsei);

  for ( int i = quantidade_de_numeros; i >= 0; i-- ) {
    if ( vetor[i] != 999 && vetor[i] != 0 )  {
      printf("%d ", vetor[i]);
    }
  }

  return 0;
}

void func_faz_a_brisa(int opt1, int opt2, int opt3, int *vetor, int *contador, int *quantidade_de_numeros) {
  if ( opt1 == adicionar )  {
    vetor = (int*) realloc(vetor, (*quantidade_de_numeros+1)*sizeof(int));
    vetor[*quantidade_de_numeros] = opt2;
    *quantidade_de_numeros = *quantidade_de_numeros + 1;
  }
  else if ( opt1 == remover ) {
    for ( int i = 0; i < *quantidade_de_numeros; i++)  {
      if ( vetor[i] == opt2 ) {
        vetor[i] = 999;
        *contador = *contador + 1;
      }
    }
    if ( *contador == 0) {
      printf("-1\n");
    }
    *contador = 0;
  }
  else if ( opt1 == consultar )  {
    for ( int i = 0; i < *quantidade_de_numeros; i++) {
      if ( vetor[i] == opt2 ) {
        printf("%d ", i);
        *contador = *contador + 1;
      }
    }
    if ( *contador == 0 ) {
      printf("-1\n");
    }
    else {
      printf("\n");
    }
    *contador = 0;
  }
  else if ( opt1 == alterar ) {
    for ( int i = 0; i < *quantidade_de_numeros; i++)  {
      if ( vetor[i] == opt2 ) {
        vetor[i] = opt3;
        *contador = *contador + 1;
      }
    }
    if ( *contador == 0) {
      printf("-1\n");
    }
    *contador = 0;
  }
}
