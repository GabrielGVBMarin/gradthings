#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()  {

  char letra, string[200] = {0}, frase[200][50] = {0};
  float tamanhos, cont = 0;
  float porcent = 0;
  int i = 0, k = 0, k2 = 1, m=0;

  scanf(" %c\n", &letra);
  fgets(string, 200, stdin);
  tamanhos = strlen(string);
  //printf("%c\n", letra);

  for ( i = 0, k = 0; k < tamanhos; k++)  {
    if ( string[k] == ' ') {
      i++;
      k2++;
      m = 0;
    }
    else {
      frase[i][m] = string[k];
      m++;
    }
  }

  //printf("%s\n", frase[0]);
  //printf("%s\n", frase[1]);
  //printf("%d\n", k2);



  for ( i = 0; i < k2; i++) {
    for ( int j = 0; j < strlen(frase[i]); j++) {
      if ( frase[i][j] == letra ) {
        //printf("%s\n", frase[i]);
        cont++;
        break;
      }
    }
  }
  //printf("%f\n", cont);

  porcent = (cont/(float)k2)*100;

  printf("%.1f", porcent);

  return 0;
}
