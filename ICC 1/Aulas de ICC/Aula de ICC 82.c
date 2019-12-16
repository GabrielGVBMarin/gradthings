#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int *criaVet(int);
void imprimeVet(int[], int);
int maxVet(int*, int);

int main()  {

  int tam;
  int *v;
  printf("tam = "); scanf("%d", &tam);
  srand(time(NULL));
   v = criaVet(tam);
   imprimeVet(v, tam);
   printf("\nmax = %d", maxVet(v, tam));

  return 0;
}

int *criaVet(int n) {
  int *vet, i;
  vet = (int*) calloc(n, sizeof(int));
  assert(vet);
  for ( i = 0; i < n; i++)  {
    vet[i] = 10 + rand()%21;
  }
  return vet;
}

int maxVet(int *vet, int n) {
  int aux;
  if ( n == 1 ) {
    return vet[0];
  }
  aux = maxVet(vet+1, n-1);
  if ( aux > vet[0]) return aux;
  return vet[0];
}

void imprimeVet(int vet[],int n)  {

  printf("\n[");
  for ( int i = 0; i < n; i++)  {
    printf(" %d", vet[i]);
  }
  printf("]");
}
