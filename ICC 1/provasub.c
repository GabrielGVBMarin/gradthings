#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()  {

  char *frase;
  int letra = 0;
  frase = (char*) malloc(letra+1*sizeof(char));
  if (frase == NULL)  {
    printf("ERRO NO ALLOC");
    exit(1);
  }

  //faz a leitura e ja printa o que esta lendo
  while (1) {
    frase = (char*) realloc(frase, letra+1*sizeof(char));
    if (frase == NULL)  {
      printf("ERRO NO REALLOC");
      exit(1);
    }
    scanf("%c", &frase[letra]);
    if ( frase[letra] == 36)  {
      frase[letra] = '\0';
      break;
    }
    printf("%c", frase[letra]);
    letra++;
  }

  printf("\n");
  for ( int i = 0; i < letra; i++)  {
    //verifica o numero, se for maior que o ultimo caracter se somado com 6, redefine o caracter para dar certo
    if ( frase[i] > 116)  {
      frase[i] = frase[i] - 26;
      printf("%c", frase[i]+6);
      continue;
    }
    if ( frase[i] != ' ') {
    printf("%c", frase[i] + 6);
    }
    // se for espaço, imprime sem nenhuma alteração
    else {
      printf("%c", frase[i]);
    }
  }

  free(frase);
  return 0;
}
