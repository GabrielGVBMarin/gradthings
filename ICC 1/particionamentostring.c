#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 500

void particionar(char*, char[50][MAX], int*);
void imprimir(char[50][MAX], int*);
void ordenar(char*, char[50][MAX], char[MAX], int*);

int main()  {

char frase[MAX] = {'0'}, matriz[50][MAX] = {'0'}, sup[MAX] = {0};
int chose, cont = 0;

fgets(frase, MAX, stdin);
scanf("%d", &chose);

switch (chose) {
  case 1:
  particionar(frase, matriz, &cont);
  break;
  case 2:
  particionar(frase, matriz, &cont);
  ordenar(frase, matriz, sup, &cont);
  break;
  default: break;
}

imprimir(matriz, &cont);

  return 0;
}

void particionar(char *letra, char matriz[50][MAX], int *cont)  {
  int k = 0;
  for ( int i = 0, y = 0; i < 500; i++, y++)  {
    if(isspace(letra[i])) {
      letra[i] = '\0';
      k++;
      y = 0;
      continue;
    }
    matriz[k][y] = letra[i];
  }
  *cont = k;

}

void ordenar(char *letra, char matriz[50][MAX], char sup[MAX], int *cont)  {

//colocar as palavras em minusculo
for ( int h = 0; h < *cont; h++) {
  for ( int f = 0; f < MAX; f++)  {
    matriz[h][f] = tolower(matriz[h][f]);
  }
}
//deve ta aqui
  for ( int i = 0; i < *cont; i++)  {
    strcpy(sup, matriz[i]);
    printf("%s teste da sup\n", sup);
    for ( int j = 0; j < *cont; j++) {
      if (sup[0] < matriz[j][0])  {
        strcpy(sup, matriz[j]);
        strcpy(matriz[j], matriz[i]);
        strcpy(matriz[i], sup);
      }
      else if (sup[0] == matriz[j][0] && sup[1] < matriz[j][1]) {
        strcpy(sup, matriz[j]);
        strcpy(matriz[j], matriz[i]);
        strcpy(matriz[i], sup);
      }
      else if (sup[0] == matriz[j][0] && sup[1] == matriz[j][1] && sup[2] < matriz[j][2]) {
        strcpy(sup, matriz[j]);
        strcpy(matriz[j], matriz[i]);
        strcpy(matriz[i], sup);
      }
    }
  }
  //deve ta aqui
}

void imprimir(char matriz[50][MAX], int *cont) {
   for ( int h = 0; h < *cont; h++) {
     for ( int f = 0; f < MAX; f++)  {
       printf("%c", matriz[h][f]);
     }
     printf("\n");
   }
}
