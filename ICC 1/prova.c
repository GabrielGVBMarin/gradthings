#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int maiorelemento(int[100], int);
int menorelemento(int[100], int);
void intersec(int[100], int[100], int, int, int[100]);

int main()  {

  int tam1, tam2, maior1, maior2 , menor1, menor2;
  scanf("%d %d", &tam1, &tam2);
  int vetor1[100] = {999}, vetor2[100] = {999}, vetor[100] = {999};

  for ( int i = 0; i < tam1; i++) {
    scanf("%d", &vetor1[i]);
  }
  for ( int i = 0; i < tam2; i++) {
    scanf("%d", &vetor2[i]);
  }

  intersec(vetor1, vetor2, tam1, tam2, vetor);

  maior1 = maiorelemento(vetor1, tam1);
  maior2 = maiorelemento(vetor2, tam2);

  menor1 = menorelemento(vetor1, tam1);
  menor2 = menorelemento(vetor2, tam2);

  printf("Intersecao:\n");
  for ( int i = 0; i < 10 ; i++)  {
    if ( vetor[i] == 999) {
      break;
    }
    printf("%d ", vetor[i]);
  }
  printf("\nMenor:\n");
  if ( menor1 < menor2) {
    printf("%d", menor1);
  }
  else {
    printf("%d", menor2);
  }
  printf("\nMaior:\n");
  if ( maior1 > maior2) {
    printf("%d", maior1);
  }
  else {
    printf("%d", maior2);
  }

  return 0;
}

int maiorelemento(int vetor[100], int tam) {
  int maior;
  for ( int i = 0; i < tam; i++)  {
    if ( i == 0 ) {
      maior = vetor[i];
    }
    else if ( vetor[i] > maior )  {
      maior = vetor[i];
    }
  }
  return maior;
}

int menorelemento(int vetor[100], int tam)  {
  int menor;
  for ( int i = 0; i < tam; i++)  {
    if ( i == 0 ) {
      menor = vetor[i];
    }
    else if ( vetor[i] < menor )  {
      menor = vetor[i];
    }
  }
  return menor;
}

void intersec(int vetor1[100], int vetor2[100], int tam1, int tam2, int vetor[100]) {
  int m = 0;
  for ( int i = 0; i < tam1; i++)  {
    for ( int k = 0; k < tam2; k++) {
      if ( vetor1[i] ==  vetor2[k]) {
        vetor[m] = vetor1[i];
        m++;
      }
    }
  }
}
