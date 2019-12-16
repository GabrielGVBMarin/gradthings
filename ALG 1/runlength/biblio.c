// GABRIEL GUIMARAES VILAS BOAS MARIN 11218521
#include <biblio.h>

// LE A MATRIZ, TANTO COMPACTADA QUANTO DESCOMPACTADA
int** readMatrix(int *width, int *height, int *maxPixel, char **type)  {

  int **matrix = NULL, i, j, flag, aux, nDigits;
  char *string = NULL;

  scanf("%s", *type);
  scanf("%d", width);
  scanf("%d", height);
  scanf("%d", maxPixel);

  if (!maxPixel)  {
    nDigits = 1;
  } else  {
    // PEGA A LENGTH DO INTEIRO, RETIRADO DE https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
    nDigits = floor(log10(abs(*maxPixel))) + 1;
  }
  string = (char*) calloc(nDigits, sizeof(char));

  matrix = (int**) malloc((*height)*sizeof(int*));
  for (i = 0; i < *height; i++)  {
    matrix[i] = (int*) malloc((*width)*sizeof(int));
  }

  if (!strcmp(*type, "P2")) {
    for (i = 0; i < *height; i++)  {
      for (j = 0; j < *width; j++) {
        scanf("%d", &matrix[i][j]);
      }
    }
  } else  {
    for (i = 0; i < *height; i++)  {
      flag = 0, aux = 0;
      for (j = 0; aux < *width; j++) {
        scanf("%s", string);
        if (!isdigit(string[0])) {
          matrix[i][j] = -1;
          // DISPARA CONTADOR FLAG
          flag = 1;
        } else  {
          matrix[i][j] = atoi(string);
          if (flag == 1) flag++;
          else if (flag == 2) {
            // VE QUANTAS VEZES REPETE PRA DEIXAR ESPAÇO NA MATRIZ
            aux = aux + matrix[i][j], flag = 0;
          } else  aux++;
        }
      }
    }
  }

  free(string);

  return matrix;

}

// COMPACTA IMAGEM DADA
int** compress(int **matrix, int *width, int *height, int **lineSize) {

  int **new = (int**) malloc((*height)*sizeof(int*));
  int sequence, i, j, aux, m;

  for (i = 0; i < *height; i++)  {
    new[i] = NULL;
  }

  for (i = 0; i < *height; i++)  {
    sequence = 0;
    aux = matrix[i][0];
    for (j = 0; j < *width; j++) {
      if (aux == matrix[i][j])  {
        sequence++;
      } else if (sequence >= 4) {

        // REALLOCA A LINHA, COLOCA OS VALORES E MUDA A VARIAVEL DE TAMANHO DA LINHA
        new[i] = (int*) realloc(new[i], ((*lineSize)[i]+3)*sizeof(int));
        new[i][(*lineSize)[i]] = -1;
        new[i][(*lineSize)[i]+1] = aux;
        new[i][(*lineSize)[i]+2] = sequence;
        (*lineSize)[i] = (*lineSize)[i] + 3;
        aux = matrix[i][j];
        sequence = 1;

      } else  {

        new[i] = (int*) realloc(new[i], ((*lineSize)[i]+sequence)*sizeof(int));
        for (m = 0; m < sequence; m++)  {
          new[i][(*lineSize)[i]+m] = aux;
        }
        (*lineSize)[i] = (*lineSize)[i] + sequence;
        aux = matrix[i][j];
        sequence = 1;

      }
    }
    // CHECA SE A LINHA TERMINA COM UMA SEQUENCIA OU N
    if (sequence >= 4) {

      new[i] = (int*) realloc(new[i], ((*lineSize)[i]+3)*sizeof(int));
      new[i][(*lineSize)[i]] = -1;
      new[i][(*lineSize)[i]+1] = aux;
      new[i][(*lineSize)[i]+2] = sequence;
      (*lineSize)[i] = (*lineSize)[i] + 3;

    } else  {

      new[i] = (int*) realloc(new[i], ((*lineSize)[i]+sequence)*sizeof(int));
      for (m = 0; m < sequence; m++)  {
        new[i][(*lineSize)[i]+m] = aux;
      }
      (*lineSize)[i] = (*lineSize)[i] + sequence;

    }
  }

  return new;

}

// DESCOMPACTA A IMAGEM DADA
int** unpack(int **matrix, int *width, int *height)  {

  int i, j, aux, k;
  int **new = (int**) malloc((*height)*sizeof(int*));
  for (i = 0; i < *height; i++)  {
    new[i] = (int*) malloc((*width)*sizeof(int));
  }

  for (i = 0; i < *height; i++)  {
    aux = 0;
    for (j = 0; j < *width; j++) {
      if (matrix[i][aux] == -1) {
        for (k = 0; k < matrix[i][aux+2]; k++)  {
          new[i][j+k] = matrix[i][aux+1];
        }
        aux = aux + 3;
        j = j + k-1;
      } else  {
        new[i][j] = matrix[i][aux];
        aux++;
      }

    }
  }

  return new;

}

// PRINTA A MATRIZ COMPACTADA
void printCompressed(int **matrix, int *lineSize, int *height, int *maxPixel, char *type, int *width)  {
  int i, j;

  printf("%s\n", type);
  printf("%d %d\n", *width, *height);
  printf("%d\n", *maxPixel);
  for (i = 0; i < *height; i++) {
    for (j = 0; j < lineSize[i]; j++) {
      if (matrix[i][j] == -1) {
        printf("@ ");
      } else  {
        printf("%d ", matrix[i][j]);
      }
    }
    printf("\n");
  }

}

// PRINTA A MATRIZ DESCOMPACTADA
void printUnpacked(int ***matrix, int *width, int *height, int *maxPixel, char *type)  {
  int i, j;

  printf("%s\n", type);
  printf("%d %d\n", *width, *height);
  printf("%d\n", *maxPixel);
  for (i = 0; i < *height; i++)  {
    for (j = 0; j < *width; j++) {
      printf("%d ", (*matrix)[i][j]);
    }
    printf("\n");
  }

}
