#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int soma(int);
int fatorial(int);
int fibonacci(int);

int main()  {

  int numero;
  double result;
  char op;
  scanf("%d %c", &numero, &op);
  int (*ponteiro)(int);

  switch (op) {
    case 43:
      ponteiro = soma;
    break;
    case 33:
      ponteiro = fatorial;
    break;
    case 102:
      ponteiro = fibonacci;
    break;
  }

  result = ponteiro(numero);

  printf("%.0lf", result);

  return 0;
}

int soma(int numero)  {
  return numero==1 ? 1:numero+soma(numero-1);
}

int fatorial(int numero)  {
  return numero == 1 ? 1:(numero*fatorial(numero-1));
}

int fibonacci(int numero) {
  return (numero == 2 || numero == 1) ? 1:fibonacci(numero-1)+fibonacci(numero-2);
}
