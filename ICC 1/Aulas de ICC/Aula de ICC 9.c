#include <hanoi.h>

int soma(int);

int main(int argc, char *argv[])  {

  printf("%d\n", argc);
  //printf("")

  enum dia {dom, seg, ter, qua, qui, sex, sab};
  enum dia diaSemana;
  int numero, saida;
  scanf("%d", &numero);
  saida = soma(numero);

  printf("%d", saida);
  return 0;
}

int soma( int numero) {
  // if ( numero <= 1) {
  //   return numero;
  // }
  // else {
  //   return (numero+soma(numero-1));
  // }
  return numero <= 1 ? numero:(numero+soma(numero-1));
}
