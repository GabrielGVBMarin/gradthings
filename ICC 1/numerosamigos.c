#include <stdio.h>
#include <string.h>
#include <math.h>

int main()  {

  int x, y, soma = 0, soma2 = 0;
  int i, j, aucs;

  scanf("%d %d", &x, &y);

  for ( i = x; i < y; i++)  {
    for ( j = 1; j < i; j++)  {
      if ( i%j == 0 ) {
        soma = soma + j;
      }
    }
    //printf("%d %d\n", soma, i);
    for ( int k = 1; k < soma; k++) {
      if ( soma%k == 0) {
        soma2 = soma2 + k;
      }
    }
    if ( soma2 == i && i != soma && aucs != i)  {
      printf("%d %d\n", i, soma);
      aucs = soma;
    }
    soma = 0;
    soma2 = 0;
  }

  return 0;
}
