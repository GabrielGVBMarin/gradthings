#include <stdio.h>
#include <math.h>
#include <string.h>

void tipo1(double[5]);
void tipo2(double[5]);
void tipo3(double[5]);

int main()  {

  double notas[5];
  int type;

  for( int i = 0; i < 5; i++) {
    scanf("%lf", &notas[i]);
  }
  scanf("%d", &type);

  switch (type) {
    case 1:
    tipo1(notas);
    break;
    case 2:
    tipo2(notas);
    break;
    case 3:
    tipo3(notas);
    break;
  }
  return 0;
}

void tipo1(double notas[5])  {
  double soma = 0;
 for ( int i = 0; i < 5; i++) {
   soma = soma + notas[i];
 }
 soma = soma/5;
 printf("%.2lf\n", soma);
 if ( soma >= 5) {
   printf("APROVADO");
 }
 else {
   printf("REPROVADO");
 }
}

void tipo2(double notas[5])  {
  int pesos[5], somas= 0;
  double soma = 0;
  for ( int i = 0; i < 5; i++)  {
    scanf("%d", &pesos[i]);
    somas = somas + pesos[i];
    notas[i] = notas[i] * pesos[i];
    soma = soma + notas[i];
  }
  soma = soma/somas;
  printf("%.2lf\n", soma);
  if ( soma >= 5) {
    printf("APROVADO");
  }
  else {
    printf("REPROVADO");
  }
}

void tipo3(double notas[5])  {
  double soma = 0;
  for ( int i = 0; i < 5; i++)  {
    notas[i]= 1/notas[i];
    soma = soma + notas[i];
  }
  soma = 5/soma;
  printf("%.2lf\n", soma);
  if ( soma >= 5) {
    printf("APROVADO");
  }
  else if ( soma >= 3)  {
    printf("REC");
  }
  else {
    printf("REPROVADO");
  }
}
