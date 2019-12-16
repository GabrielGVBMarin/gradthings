#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()  {

  int quants, tamanho;
  char comandos[100];
  quants = 0;

  for ( int i = 0; i < 1; i++)  {

    fgets(comandos, 100, stdin);
    tamanho = strlen(comandos);
    for ( int k = 0;  k < tamanho; k++) {
      if( tolower(comandos[k]) == 'd') {
        quants = quants + 1;
      }
      else if ( tolower(comandos[k]) == 'e') {
        quants = quants - 1;
      }
    }

    if ( quants%4 == 0)  {
      printf("Norte");
    }
    else if ( quants%4 == 1)  {
      printf("Leste");
    }
    else if ( quants%4 == -1) {
      printf("Oeste");
    }
    else if ( quants%4 == 2 || quants%4 == -2)  {
      printf("Sul");
    }
    else if ( quants%4 == 3)  {
      printf("Oeste");
    }
    else if ( quants%4 == -3) {
      printf("Leste");
    }


  }
}
