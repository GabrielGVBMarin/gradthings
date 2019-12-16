#include <stdio.h>

int fatIter(int);
int fatRec(int);
int executa(int (*pt)(int), int);

int main()  {

  int n;
  printf("N = "); scanf("%d", &n);
  printf("!%d = %d", n, executa(fatIter, n));
  return 0;
}

int fatRec(int a) {
  if ( a == 1 )  {
    return a;
  }
  return a*fatRec(a-1);
}

int fatIter(int a)  {
  int fat = 1;
  while (a > 1) {
    fat = fat*a;
    --a;
  }

  return fat;
}

int executa(int (*pt)(int), int a)  {
  return  pt(a);
}
