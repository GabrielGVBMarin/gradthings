#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  char nome[30];
  int idade;
  char sexo;
} registro;

int main()  {

  registro *pessoa = NULL;
  char op;
  int vezes, quantidade = 0; scanf("%d", &vezes);
  for (int i = 0; i < vezes; i++) {

    scanf(" %c", &op);
    switch (op) {

      case 'i':
      pessoa = (registro*) realloc(pessoa, (quantidade+1)*sizeof(registro));
      scanf(" %s", pessoa[quantidade].nome);
      //printf("%s\n", pessoa[quantidade].nome);
      scanf("%d", &pessoa[quantidade].idade);
      //printf("%d\n", pessoa[quantidade].idade);
      scanf(" %c", &pessoa[quantidade].sexo);
      //printf("%c\n", pessoa[quantidade].sexo);
        quantidade++;
      break;
      case 'r':
        if ( quantidade != 0 )  {
          quantidade--;
        }
        scanf(" %s", pessoa[quantidade].nome);
        scanf("%d", &pessoa[quantidade].idade);
        scanf(" %c", &pessoa[quantidade].sexo);
      break;

    }

  }

  for ( int i = quantidade-1; i >= 0; i--)  {
    printf("%s %d %c\t", pessoa[i].nome, pessoa[i].idade, pessoa[i].sexo);
  }

  return 0;
}
