#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trocaLetra(char* palavra, char letra, int* nTrocas);

int main()  {

char letra, palavra[50] = {0}, original[50] = {0};
int numtrocas = 0;
scanf("%c", &letra);
scanf("%s", palavra);
strcpy(original, palavra);

trocaLetra(palavra, letra, &numtrocas);

printf("Numero de trocas: %d\n", numtrocas);
printf("Nova palavra: %s\n", palavra);
printf("Palavra original: %s", original);

  return 0;
}

void trocaLetra(char* palavra, char letra, int* nTrocas)  {
  for ( int i = 1; i < strlen(palavra); i++)  {
    if ( palavra[i] == letra ) {
      palavra[i] += i;
      *nTrocas += 1;
    }
  }
}
