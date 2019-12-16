#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int* ve_quem_ganhou(char[2][100][3], int);
void faz_a_leitura(char[2][100][3], int*);

int main()  {

  int partidas, *vencedor;
  char jogo[2][100][3] = {0};

  //le a entrada e calcula quantas partidas os jogadores venceram e quantas empataram
  faz_a_leitura(jogo, &partidas);
  vencedor = ve_quem_ganhou(jogo, partidas);

  //printo os resultados
  printf("%d ", vencedor[0]);
  printf("%d ", vencedor[2]);
  printf("%d", vencedor[1]);

  free(vencedor);
  // teste pra ver se ta lendo certo
  // for ( int i = 0; i < 2; i++)  {
  //   for ( int k = 0; k < partidas; k++) {
  //       printf("%s", jogo[i][k]);
  //   }
  //   printf("TROCA DE JOGADOR\n");
  // }

  return 0;
}

 int* ve_quem_ganhou(char jogo[2][100][3], int partidas)  {
   int pontos_do_jogador[2] = {1}, pontos_do_jogador_antes[2] = {1}, verdadeiros_pontos[2] = {0}, *vetor;
   vetor = (int*) malloc(3*sizeof(int));
   //varia o jogador
   for ( int i = 0; i < 2; i++) {
     //varia a rodada
     for ( int l = 0; l < partidas; l++) {
       //varia os caracteres
       for ( int col = 0; col < 3; col++) {
         pontos_do_jogador_antes[i] = pontos_do_jogador[i];
         // atravez dos numeros primos, vai multiplicanto o 1 do pontos_do_jogador, pra depois saber quais valores tinham naquela mao
         //ao multiplicar por primos, posso identificar se o resto da divisao por eles for 0, ja que sao primos, so dividem
         //por eles mesmos
         if (jogo[i][l][col] == '2')  {
           pontos_do_jogador[i] *= 2;
         }
         else if (jogo[i][l][col] == '3')  {
           pontos_do_jogador[i] *= 3;
         }
         else if (jogo[i][l][col] == '4')  {
           pontos_do_jogador[i] *= 5;
         }
         else if (jogo[i][l][col] == '5')  {
           pontos_do_jogador[i] *= 7;
         }
         else if (jogo[i][l][col] == '6')  {
           pontos_do_jogador[i] *= 11;
         }
         else if (jogo[i][l][col] == '7')  {
           pontos_do_jogador[i] *= 13;
         }
         else if (jogo[i][l][col] == '8')  {
           pontos_do_jogador[i] *= 17;
         }
         else if (jogo[i][l][col] == '9')  {
           pontos_do_jogador[i] *= 19;
         }
         else if (jogo[i][l][col] == '1' && jogo[i][l][col+1] == '0')  {
           pontos_do_jogador[i] *= 23;
         }
         else if (jogo[i][l][col] == 'J')  {
           pontos_do_jogador[i] *= 29;
         }
         else if (jogo[i][l][col] == 'Q')  {
           pontos_do_jogador[i] *= 31;
         }
         else if (jogo[i][l][col] == 'K')  {
           pontos_do_jogador[i] *= 37;
         }
         else if (jogo[i][l][col] == 'A')  {
           pontos_do_jogador[i] *= 41;
         }
       }
       // checa se tinha pares de cada valor possivel e atribui os pontos se houve a condicao que indica que teve par
       // faltou colocar aqui as outras combinacoes pra marcar pontos possiveis, ja que n deu tempo
       if ( (pontos_do_jogador - pontos_do_jogador_antes)%4 ==  0) {
         verdadeiros_pontos[i] += 100;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%9 ==  0) {
         verdadeiros_pontos[i] += 200;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%25 ==  0) {
         verdadeiros_pontos[i] += 300;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%49 ==  0) {
         verdadeiros_pontos[i] += 400;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%121 ==  0) {
         verdadeiros_pontos[i] += 500;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%169 ==  0) {
         verdadeiros_pontos[i] += 600;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%289 ==  0) {
         verdadeiros_pontos[i] += 700;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%361 ==  0) {
         verdadeiros_pontos[i] += 800;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%529 ==  0) {
         verdadeiros_pontos[i] += 900;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%841 ==  0) {
         verdadeiros_pontos[i] += 1000;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%961 ==  0) {
         verdadeiros_pontos[i] += 1100;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%1369 ==  0) {
         verdadeiros_pontos[i] += 1200;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%1681 ==  0) {
         verdadeiros_pontos[i] += 1300;
       }
       //
       //
       // A PARTIR DAQUI ELE VE SE TEM TRINCA, SE TIVER MARCA OS PONTOS
       //
       //
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%8 ==  0) {
         verdadeiros_pontos[i] += 1400;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%27 ==  0) {
         verdadeiros_pontos[i] += 1500;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%125 ==  0) {
         verdadeiros_pontos[i] += 1600;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%343 ==  0) {
         verdadeiros_pontos[i] += 1700;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%1331 ==  0) {
         verdadeiros_pontos[i] += 1800;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%2197 ==  0) {
         verdadeiros_pontos[i] += 1900;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%4913 ==  0) {
         verdadeiros_pontos[i] += 2000;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%6859 ==  0) {
         verdadeiros_pontos[i] += 2100;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%12167 ==  0) {
         verdadeiros_pontos[i] += 2200;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%24389 ==  0) {
         verdadeiros_pontos[i] += 2300;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%29791 ==  0) {
         verdadeiros_pontos[i] += 2400;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%50653 ==  0) {
         verdadeiros_pontos[i] += 2500;
       }
       else if ( (pontos_do_jogador - pontos_do_jogador_antes)%68921 ==  0) {
         verdadeiros_pontos[i] += 2600;
       }
       //DETERMINA QUEM GANHOU AQUELE ROUND
        if ( verdadeiros_pontos[0] > verdadeiros_pontos[1])  {
          vetor[0]++;
          // zera os pontos do round
          verdadeiros_pontos[0] = 0;
          verdadeiros_pontos[1] = 0;
          continue;
        }
        if ( verdadeiros_pontos[1] > verdadeiros_pontos[0] ){
          vetor[1]++;
          //zera os pontos do round
          verdadeiros_pontos[0] = 0;
          verdadeiros_pontos[1] = 0;
          continue;
        }
        if ( verdadeiros_pontos[0] == verdadeiros_pontos[1]) {
          vetor[2]++;
          //zera os pontos do round
          verdadeiros_pontos[0] = 0;
          verdadeiros_pontos[1] = 0;
          continue;
        }
       }

     }
   return vetor;
 }

 void faz_a_leitura(char jogo[2][100][3], int*partidas)  {
   scanf("%d\n", &*partidas);
   for ( int i = 0; i < *partidas; i++) {
     fgets(jogo[0][i],25,stdin);
     fgets(jogo[1][i], 25, stdin);
   }
 }
