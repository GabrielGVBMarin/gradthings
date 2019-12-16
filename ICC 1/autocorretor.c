#include <stdio.h>
#include <string.h>

int main()  {

  int quant, set[100] = {0};
  char palavras[100][100] = {0}, palavraerrada[100];
  //int maior = -10000;

  scanf("%d\n", &quant);

  for ( int i = 0; i < quant; i++)  {
    scanf("%s\n", &*palavras[i]);
  }
  scanf("%s\n", &*palavraerrada);

  for ( int i = 0; i < 100; i++)  {
    for ( int j = 0; j < strlen(palavras[i]); j++)  {
      if ( palavraerrada[j] == palavras[i][j])  {
        set[i] += 1;
      }
    }
    //if ( set[i] > maior ) {
    //  maior = set[i];
    //  maior = maior*0.7;
    //}
    //printf("%d\n", set[i]);
  }

  for ( int i = 0; i < quant; i++)  {
    if (set[i] >= 0.7*strlen(palavraerrada)) {
      printf("%s\n", palavras[i]);
    }
  }

  return 0;
}
