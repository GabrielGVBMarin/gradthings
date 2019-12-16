#include <stdio.h>
#include <math.h>
#include <string.h>

float dist(int[10][2], float, float, int ,int);

int main()  {

  int cidades[10][2] = {0}, quants, inicio, fim, i, c1, c2, aux, somas[100], save;
  float calculo, distancia, distancias = 0;
  scanf("%d %d %d", &quants, &inicio, &fim);
  do {
    aux = scanf("%d (%d,%d)", &i, &c1, &c2);
    if ( aux == 3)  {
      cidades[i][0] = c1;
      cidades[i][1] = c2;
    }
  } while (aux == 3);

  for ( int k = 0; k < quants; k++) {
    somas[k] = cidades[k][0] + cidades[k][1];
    }

    for ( int j = 0; j < quants; j++) {
      if (somas[j] > somas[j+1])  {
        save = somas[j+1];
        somas[j+1] = somas[j];
        somas[j] = save;
      }
    }
// a ideia era somar a coordenada x e y (projeção no eixo X e Y) dos pontos, portanto, as que tiverem a soma mais proxima do inicio
    //  serao a cidade com o caminho mais

    for ( int l = 0; l < quants; l++) {
      distancias = distancias + dist(cidades,calculo,distancia, fim, inicio);
      // calcular a distancia de cada ponto na ordem estabelecida pelo vetor somas
    }


  printf("%.2f", distancias);
  //printf("%d\n", cidades[0][0]);  //printf("%d\n", cidades[1][1]);  //printf("%d\n", cidades[2][1]);
  return 0;
}

float dist(int cidades[10][2], float calculo, float distancia, int fim, int inicio)  {
  calculo = pow((cidades[inicio][0]-cidades[fim][0]),2) + pow(cidades[inicio][1]-cidades[fim][1],2);
  distancia = sqrt(calculo);
  return distancia;
}
