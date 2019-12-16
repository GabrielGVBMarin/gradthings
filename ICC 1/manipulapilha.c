#include <stdio.h>
#include <stdlib.h>

int main()  {

  int tamanho, numero, *pilha = NULL, numero_da_pilha = 0;
  pilha = (int*) malloc(1*sizeof(int));
  char op;

  scanf("%d", &tamanho);

  for ( int i = 0; i < tamanho; i++)  {

    scanf(" %c", &op);
    scanf("%d", &numero);

    if ( op == 'i') {
      pilha = (int*) realloc(pilha, (tamanho+1)*sizeof(int));
      pilha[numero_da_pilha] = numero;
      numero_da_pilha++;
    }

    else if ( op == 'r' ) {
      if ( numero_da_pilha == 0 ) {
        numero_da_pilha++;
      }
      numero_da_pilha--;
    }

  }

  for ( int i = numero_da_pilha-1; i >= 0; i--)  {
    printf("%d ", pilha[i]);
  }

  return 0;
}
