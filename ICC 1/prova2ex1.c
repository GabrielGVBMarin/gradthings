#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()  {
  char tabu[20], *frase = NULL;
  int c = 0, vezes_encontrada = 0;
  // faz a leitura dos dados
  scanf("%s\n", tabu);
  while (1) {
    frase = (char*) realloc(frase, c+1*sizeof(char));
    scanf("%c", &frase[c]);
    if ( frase[c] == 36)  {
      frase[c] = '\0';
      c--;
      break;
    }
    c++;
  }
  //leitura dos dados completa


  for ( int i = 0, quantidade_de_iguais = 0; i < strlen(frase); i++) {
    if ( frase[i] != tabu[quantidade_de_iguais])  {
      quantidade_de_iguais = 0;
    }
    if (frase[i] == tabu[quantidade_de_iguais]) {
      quantidade_de_iguais++;
    }
    if ( quantidade_de_iguais == strlen(tabu))  {
       for ( int j = i-quantidade_de_iguais+1; j < i+1; j++) {
         frase[j] = 2;
       }
      //strcpy(frase+(i-quantidade_de_iguais+1), frase+(i+1));
      vezes_encontrada++;
    }
  }

  printf("A palavra tabu foi encontrada %d vezes\n", vezes_encontrada);
  printf("Frase: ");
  //imprime os caracteres menos os identificados como sendo a string tabu
  for ( int i = 0; i < strlen(frase); i++)  {
    if ( frase[i] != 2) {
      printf("%c", frase[i]);
    }

  }
  free(frase);

  return 0;
}
