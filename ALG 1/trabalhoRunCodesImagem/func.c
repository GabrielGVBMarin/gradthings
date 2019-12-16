#include <biblio.h>

char* leNomeArquivo()  {

  int i = 0;
  char *read = NULL;

  do {

    read = (char*) realloc(read, (i+1)*sizeof(char));
    scanf("%c", &read[i]);

  } while( read[i] != '\n' && (i = i + 1));

  read[i] = '\0';

  return read;
}




int** leImagem(FILE *arq, int *height, int *width)  {

  char *naoVaiUsar = (char*) malloc(2*sizeof(char));
  int i, j, **matriz = NULL, max;
  // printf("FOIIII\n\n\n");

  // LE ALGUNS DADOS DO INICIO DO ARQUIVO
  fscanf(arq, "%s %d %d %d", naoVaiUsar, width, height, &max);
  // printf("FOIII22222\n\n\n");

  // ALOCA A MATRIZ DINAMICAMENTE PARA A LEITURA
  matriz = (int**) malloc((*height)*sizeof(int*));
  for ( i = 0; i < *height; i++)  {
    matriz[i] = (int*) malloc((*width)*sizeof(int));
  }

  // FAZ A LEITURA DA MATRIZ
  for (i = 0; i < *height; i++)  {
    for (j = 0; j < *width; j++) {
      fscanf(arq, "%d", &matriz[i][j]);
    }
  }

  return matriz;

}



char* leNumerosNaImagem(int **matriz, int height, int width) {

  char *numerosEncontrados = NULL;
  int x = 0, y = 0,numberSize = 1;

  // ENCONTRA O NUMERO, RECONHECE E ADICIONA NA STRING DANDO REALLOC
  while((procuraNumero(matriz, &x, &y, height, width)))  {
      // printf("ACHOU O NUMERO\n\n\n\n");
      numerosEncontrados = (char*) realloc(numerosEncontrados, numberSize*sizeof(char));
      // printf("TESTE\n\n\n");

      // RECONHECE O NUMERO ENCONTRADO NA FUNC procuraNumero(); E ADICIONA NA STRING
      numerosEncontrados[numberSize - 1] = reconhecerNumero(matriz, x, y);
      // printf("RECONHECEU O BAGULHO\n\n\n");

      // AUMENTA A QUANTIDADE DE NUMERO E MUDA AS POSIÇÕES PARA O PROXIMO
      // X E Y QUE SÃO AONDE O PONTEIRO DA MATRIZ FICA PARA PROCURAR O PROXIMO NUMERO
      numberSize++;
      x = x + 30;
      y = 0;
    }

  // RETORNA A STRING COM OS NUMEROS ENCONTRADOS
  return numerosEncontrados;

}



int procuraNumero(int **matriz, int *x, int *y, int height, int width) {

  // printf("HEIGHT : %d   WIDTH : %d\n\n\n", height, width);

  int times = 0;
  int i, j;

  // printf("TA PROCURANDO %d %d\n\n\n", xis, yis);
  // FOR VARRENDO AS COLUNAS ATÉ ENCONTRAR UM NUMERO
  for (j = *x; j < width-5; j++)  {
    // printf("COLUNA COMEÇA\n\n\n");
    for (i = *y; i < height-45; i++, times = 0) {
      // printf("%d", matriz[i][j]);
      if (matriz[i][j]) {
        if ( matriz[i+1][j] && (times = times + 1))
        ;
        if ( matriz[i+2][j] && (times = times + 1))
        ;
        if ( matriz[i][j+1] && (times = times + 1))
        ;
        if ( matriz[i][j+2] && (times = times + 1))
        ;
        if (matriz[i+1][j+1] && (times = times + 1))
        ;
        if (matriz[i+2][j+2] && (times = times + 1))
        ;
        // QUANTIDADE MINIMA DE 1 PARA QUE SEJA CONSIDERADO UM NUMERO NAQUELA POSIÇÃO
        if ( times >= 6)  {
          // printf("ACHOUUUUU SALVANDO LUGAR\n\n\n");
          // ATUALIZA AS COORDENADAS PARA O 1 PIXEL DO NUMERO
          *x = j;
          *y = i;
          // printf("LUGAR SALVO\n\n\n");
          // RETORNA TRUE PARA NUMERO ENCONTRADO
          return 1;
        }
      }
    }
    // printf("TERMINA COLUNA\n\n\n");
    // printf("\n");
  }
  return 0;
}



char reconhecerNumero(int **numero, int x, int y) {

  int *blocos = (int*) calloc(15, sizeof(int));
  char numberFound;

  // printf("ENTROU RECONHECER\n\n\n");

  // DIVIDINDO EM BLOCOS 10X10 TEREMOS 15 BLOCOS
  // AQUI EH FEITO O RECONHECIMENTO DE CADA BLOCO
  // PARA SABER QUAIS ESTÃO PREENCHIDOS DE 1 OU NÃO

  // PARA ALGUNS BLOCOS NÃO É NECESSÁRIO FAZER A CHECAGEM
  // MAS COMO ELES ESTAO LÁ, VOU DEIXAR O VETOR COM 15 POSICOES
  // APENAS PARA FACILITAR A INTERPRETAÇÃO

  // blocos[0] = checkBloco(numero, x+4, y+4);
  blocos[1] = checkBloco(numero, x+14, y+4);
  blocos[2] = checkBloco(numero, x+24, y+4);
  blocos[3] = checkBloco(numero, x+4, y+14);
  // blocos[4] = checkBloco(numero, x+14, y+14);
  blocos[5] = checkBloco(numero, x+24, y+14);
  blocos[6] = checkBloco(numero, x+4, y+24);
  blocos[7] = checkBloco(numero, x+14, y+24);
  // blocos[8] = checkBloco(numero, x+24, y+24);
  blocos[9] = checkBloco(numero, x+4, y+34);
  // blocos[10] = checkBloco(numero, x+14, y+34);
  blocos[11] = checkBloco(numero, x+24, y+34);
  // blocos[12] = checkBloco(numero, x+4, y+44);
  // blocos[13] = checkBloco(numero, x+14, y+44);
  // blocos[14] = checkBloco(numero, x+24, y+44);

  // printf("CHAMOU AS FUNC TUDO\n\n\n");
  // CHECA AS COMBINAÇÕES DE BLOCOS IDENTIFICANDO QUAL NÚMERO ESTÁ ALI
  numberFound = checkCombinations(blocos);

  // printf("AEEEHOOOOO ACHOU O BAGULHU DE NUMERO %c\n\n\n", numberFound);

  return numberFound;

}

int checkBloco(int **matriz, int x, int y)  {

  int flag = 0;

  // printf("ENTROU NO BLOCO %d %d\n\n\n", x, y);
  // OLHA QUANTOS 1 TEM NO BLOCO PRA JULGAR SE ELE TA CHEIO OU NÃO
  if(matriz[y][x+1] && (flag = flag + 1))
  ;
  if(matriz[y][x+2] && (flag = flag + 1))
  ;
  if(matriz[y][x-1] && (flag = flag + 1))
  ;
  if(matriz[y][x-2] && (flag = flag + 1))
  ;
  if(matriz[y+1][x] && (flag = flag + 1))
  ;
  if(matriz[y+2][x] && (flag = flag + 1))
  ;
  if(matriz[y-1][x] && (flag = flag + 1))
  ;
  if(matriz[y-2][x] && (flag = flag + 1))
  ;

  // VALOR MINIMO PARA QUE SEJA CONSIDERADO UM BLOCO CHEIO DE 1
  if ( flag > 5 ) {
    // printf("BLOCO PREENCHIDO ENCONTRADO\n\n\n");
    return 1;
  }

  return 0;

}

char checkCombinations(int *blocos)  {

  // DE ACORDO COM UMA LÓGICA DE BLOCOS E AONDE ELES ESTÃO PREENCHIDOS
  // NA MASCARA, ESSA PARTE VERIFICA POUCAS POSIÇÕES DE FORMA EFICIENTE
  // PARA QUE O NUMERO SEJA IDENTIFICADO RAPIDAMENTE
  if (blocos[2] == 0)  {
    return '1';
  }
  else  if (blocos[6] == 1 && blocos[7] == 0) {
    return '0';
  }
  else  if (blocos[11] == 0) {
    return '2';
  }
  else if (blocos[5] == 0 && blocos[9] == 0)  {
    return '5';
  }
  else if (blocos[3] == 0 && blocos[7] == 1) {
    return '3';
  }
  else if (blocos[1] == 0) {
    return '4';
  }
  else if (blocos[5] == 0) {
    return '6';
  }
  else if (blocos[3] == 0) {
    return '7';
  }
  else if (blocos[9]) {
    return '8';
  }
  else {
    return '9';
  }
}
