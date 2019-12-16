#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int soma(int, int);
int max(int, int);
int executa(int (*pt)(int, int), int, int);

int main()  {

  // tipo_retornado (*nome_ponteiro)(arg1, arg2, ..., argN); // declaracao do ponteiro para func
  // int (*pont)(int, int); //declarei o ponteiro que aponta para uma func
  // pont = soma; //o ponteiro recebe o endereco da func soma;
  // printf("soma=%d", pont(a,b)); // chama a func sendo apontada pelo ponteiro;
  int x, y;
  // printf("(x,y)="); scanf("%d %d", &x, &y);
  // int (*pt)(int, int);
  // pt = soma;
  // printf("soma=%d", pt(x, y));
  // pt = max;
  // printf("\nmax = %d", pt(x,y));
  int (*pt)(int, int);
  printf("(x, y) = "); scanf("%d %d", &x, &y);
  //pt = soma;
  printf("soma = %d\n", executa(soma, x, y));
  //pt = max;
  printf("max = %d\n", executa(max, x, y));


  return 0;
}

int soma( int x, int y) {
  return x+y;
  // (return a>b ? a:b;) // se a for > que b retorna a e se nao retorna b, um if no return basicamente;
}

int max(int x, int y) {
  return x>y ? x:y;
}
int executa(int (*pt)(int, int), int x, int y)  {
  return pt(x, y);
}
