#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()  {

  char frase[100];
  int tamanho;

  fgets(frase, 100, stdin);
  tamanho = strlen(frase);

  for ( int i = 0; i < tamanho; i++)  {
    if ( tolower(frase[i]) == 'a' || tolower(frase[i]) == 'e' || tolower(frase[i]) == 'i' || tolower(frase[i]) == 'o' || tolower(frase[i]) == 'u'){
      frase[i] = '*';
    }
  }

  printf("%s", frase);

  return 0;
}
