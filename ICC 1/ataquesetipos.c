#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// void ve_os_pontos_da_matriz_grande(double**, int, double*);
// void ve_os_pontos_da_matriz_menor(double**, int, double*);
void faztudo(double**, double**, int, double*, int);

int main()  {

  int tamLinha, numeros_que_n_sei_pra_que_servem[100], monstro;
  double **matrizg, **matrizp, maiordog = 0;
  scanf("%d", &tamLinha);
  matrizg = (double**) malloc(tamLinha*sizeof(double*));
  for ( int i = 0; i < tamLinha; i++) {
    matrizg[i] = (double*) malloc(tamLinha*sizeof(double));
  }
  matrizp = (double**) malloc(tamLinha*sizeof(double*));
  for ( int i = 0; i < tamLinha; i++) {
    matrizp[i] = (double*) malloc(2*sizeof(double));
  }

  for ( int i = 0; i < tamLinha; i++) {
    for ( int j = 0; j < tamLinha; j++) {
      scanf("%lf", &matrizg[i][j]);
    }
  }
  for ( int i = 0; i < tamLinha; i++) {
    for ( int j = 0; j < 2; j++) {
      scanf("%lf", &matrizp[i][j]);
    }
  }
  for ( int k = 0; k < 100; k++)  {
    scanf("%d", &numeros_que_n_sei_pra_que_servem[k]);
    if ( numeros_que_n_sei_pra_que_servem[k] == -1) {
      break;
    }
  }
  scanf("%d", &monstro);

  faztudo(matrizg, matrizp, tamLinha, &maiordog, monstro);
  // ve_os_pontos_da_matriz_grande(matrizg, tamLinha, &maiordog);
  // ve_os_pontos_da_matriz_menor(matrizp, tamLinha, &maiordop);

  // if ( maiordog > maiordop ) {
  //   printf("O melhor ataque possui indice %d e dano %.2lf", tamLinha, maiordog);
  // }
  // else if ( maiordop > maiordog ) {
  //   printf("O melhor ataque possui indice 2 e dano %.2lf", maiordop);
  // }

  return 0;
}

void faztudo( double **matrizg, double **matrizp, int tamLinha, double *maiordog, int monstro)  {
  int indice;
  for ( int i = 0; i < tamLinha; i++) {
      matrizg[i][monstro] = matrizg[i][monstro]*matrizp[i][0];
  }
  // for ( int i = 0; i < tamLinha; i++) {
  //   for ( int j = 0; j < tamLinha; j++) {
  //     printf("%lf ", matrizg[i][j]);
  //   }
  //   printf("\n");
  // }
  for ( int i = 0; i < tamLinha; i++) {
    if ( *maiordog < matrizg[i][monstro]) {
      *maiordog = matrizg[i][monstro];
      indice = i;
    }
  }
  printf("O melhor ataque possui indice %d e dano %.2lf", indice, *maiordog);
}

// void ve_os_pontos_da_matriz_grande(double **matrizg, int tamLinha, double *maiordog)  {
//   double fake = 1;
//   for ( int i = 0; i < tamLinha; i++) {
//     for ( int j = 0; j < tamLinha; j++) {
//       fake = fake*matrizg[i][j];
//       if ( fake > *maiordog)  {
//         *maiordog = fake;
//       }
//     }
//     fake = 1;
//   }
// }
//
// void ve_os_pontos_da_matriz_menor(double **matrizp, int tamLinha, double *maiordop) {
//   double fake = 1;
//   for ( int i = 0; i < tamLinha; i++) {
//     for ( int j = 0; j < 2; j++) {
//       fake = fake*matrizp[i][j];
//       if ( fake > *maiordop)  {
//         *maiordop = fake;
//       }
//     }
//     fake = 1;
//   }
// }
