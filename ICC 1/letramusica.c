#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()  {

  //FILE *arq;
  char *palavra1 = NULL, *palavra2 = NULL;
  int tamanho1 = 0, tamanho2 = 0;

  palavra1 = (char*) malloc((tamanho1+1)*sizeof(char));
  palavra2 = (char*) malloc((tamanho2+1)*sizeof(char));

  while(1) {

    palavra1 = (char*) realloc(palavra1, (tamanho1+1)*sizeof(char));
    scanf("%c", &palavra1[tamanho1]);
    tamanho1++;

    if ( palavra1[tamanho1-1] == ' ' || palavra1[tamaho1-1] == '\n' ) {

      palavra1[tamanho1-1] = '\0';
      break;

    }

  }

  while(1)  {

    palavra2 = (char*) realloc(palavra2, (tamanho2+1)*sizeof(char));
    scanf("%c", palavra2[tamanho2]);
    tamanho2++;

    if ( palavra2[tamanho2-1] == "\0" || palavra2[tamanho2-1] == "\n")  {

      palavra2[tamanho2-1] = "\0";
      break;

    }

  }

  //arq = fopen("teste.txt", "r");

  printf("%s\n%s", palavra1, palavra2);

  free(palavra1);
  free(palavra2);

  return 0;
}
