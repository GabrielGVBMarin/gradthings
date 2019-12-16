#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void calcula(int*, int*, int*, int[4], int);

int main()  {

  char time[4][5];
  int resultados[4], vitorias, empates, derrotas, empatesv[4];

  // le salva os empates e calcula os pontos
  for ( int i = 0; i < 4; i++)  {
    scanf("%s", time[i]);
    scanf("%d %d %d", &vitorias, &derrotas, &empates);
    empatesv[i] = empates;
    calcula(&vitorias, &empates, &derrotas, resultados, i);
  }

  // as condicoes de vitorias de cada time
  if ( resultados[0] > resultados[1] && resultados[0] > resultados[2] && resultados[0] > resultados[3]) {
    printf("TIME1 %d", resultados[0]);
    return 0;
  }
  else if ( resultados[1] > resultados[0] && resultados[1] > resultados[2] && resultados[1] > resultados[3]) {
    printf("TIME2 %d", resultados[1]);
    return 0;
  }
  else if ( resultados[2] > resultados[1] && resultados[2] > resultados[0] && resultados[2] > resultados[3]) {
    printf("TIME3 %d", resultados[2]);
    return 0;
  }
  else if ( resultados[3] > resultados[1] && resultados[3] > resultados[2] && resultados[3] > resultados[0]) {
    printf("TIME4 %d", resultados[3]);
    return 0;
  }

  //as condicoes de empate caso aconteça
  for ( int i = 0; i < 3; i++)  {
    if ( resultados[i] == resultados[i+1])  {
      if (empatesv[i] > empatesv[i+1]) printf("TIME%d %d", i+1, resultados[i]);
      else  {
       printf("TIME%d %d", i+2, resultados[i+1]);
      }
    }
  }

  return 0;
}

void calcula(int *vitorias, int *empates, int *derrotas, int resultados[4], int time)  {
  resultados[time] = (*vitorias)*3;
  resultados[time] += (*empates);

}
