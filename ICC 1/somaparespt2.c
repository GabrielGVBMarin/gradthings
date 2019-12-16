#include <stdio.h>
#include <math.h>

int soma(int);

int main()  {
  int valores[100], saida = 0;
  for (int i = 0; i < 1000; i++)  {
    scanf("%d", &valores[i]);
    saida = saida + soma(valores[i]);
    if ( valores[i] == -1 ) {
      i = 1000;
    }
  }
  printf("%d", saida);

}


int soma(int valores) {
  int saida = 0;
  if ( valores % 2 == 0) {
    saida = valores;
  }
  return saida;
}
