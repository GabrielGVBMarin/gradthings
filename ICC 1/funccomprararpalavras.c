#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void maiortam(char[100]);
void ordemalfa(char[100]);
void somaletras(char[100]);
void repetletras(char[100]);
void achaletra(char[100]);

int main()  {
  char pala[100];
  int opt = 0;
  scanf("%d", &opt);

  scanf("%s", &*pala);

  switch (opt) {
    case 1:
    maiortam(pala);
    break;
    case 2:
    ordemalfa(pala);
    break;
    case 3:
    somaletras(pala);
    break;
    case 4:
    repetletras(pala);
    break;
    case 5:
    achaletra(pala);
    break;
  }
  return 0;
}

void maiortam(char pala[100])  {
  int tam1, tam2;
  char pala2[100];

  scanf("%s", &*pala2);

  tam1 = strlen(pala);
  tam2 = strlen(pala2);

  if ( tam1 > tam2 )  {
    printf("1");
  }
  else if ( tam2 > tam1) {
    printf("2");
  }
  else if ( tam1 == tam2) {
    printf("0");
  }

}

void ordemalfa(char pala[100])  {
  char pala2[100];
  scanf("%s", &*pala2);

  for ( int i = 0; i < 100; i++)  {
    if ( tolower(pala[i]) < tolower(pala2[i]))  {
      printf("1");
      break;
    }
    else if ( tolower(pala2[i]) < tolower(pala[i])) {
      printf("2");
      break;
    }
    if ( i > strlen(pala) + strlen(pala2) )  {
      printf("0");
      break;
    }
  }

}

void somaletras(char pala[100]) {
  int tam1, tam2, soma1 = 0, soma2 = 0;
  char pala2[100];
  scanf("%s", &*pala2);

  tam1 = strlen(pala);
  tam2 = strlen(pala2);

  for ( int i = 0; i < tam1; i++) {
    soma1 = soma1 + pala[i];
  }
  for ( int i2 = 0; i2 < tam2; i2++)  {
    soma2 = soma2 + pala2[i2];
  }
   if ( soma1 > soma2 ) {
     printf("1");
   }
   else if ( soma2 > soma1){
     printf("2");
   }
   else if ( soma1 == soma2)  {
     printf("0");
   }
}

void repetletras(char pala[100]) {
  char pala2[100];
  scanf("%s", &*pala2);


}

void achaletra(char pala[100])  {
  char pala2[100];
  scanf("%s", &*pala2);


}
