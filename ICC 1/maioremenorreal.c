#include <stdio.h>
#include <string.h>
#include <math.h>

float maior(float[10]);
float menor(float[10]);

int main()  {

  float ent[10], menorn, maiorn;

  for (int i = 0; i < 10; i++)  {
    scanf("%f", &ent[i]);
  }
  maiorn = maior(ent);
  menorn = menor(ent);

  printf("%.2f\n", menorn);
  printf("%.2f", maiorn);
  return 0;
}

float maior(float ent[10])  {
  float maior;
  for ( int i = 0; i < 10; i++) {
    if ( i == 0 ){
      maior = ent[i];
    }
    if ( ent[i] > maior ) {
      maior = ent[i];
    }
  }
  return maior;
}

float menor(float ent[10])  {
  float menor;
  for ( int i = 0; i < 10; i++) {
    if ( i == 0 ){
      menor = ent[i];
    }
    if ( ent[i] < menor ) {
      menor = ent[i];
    }
  }
  return menor;
}
