// GABRIEL GUIMARAES VILAS BOAS MARIN 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

int main(void)  {

  char *type = (char*) malloc(2*sizeof(char));
  int width, height, maxPixel, *lineSize = NULL, i;
  int **matrix = NULL;


  matrix = readMatrix(&width, &height, &maxPixel, &type);

  // Chama as funcs de acrodo com o que é pra fazer
  if (!strcmp(type, "P2"))  {

    lineSize = (int*) calloc(height, sizeof(int));
    matrix = compress(matrix, &width, &height, &lineSize);
    type = "P8";
    printCompressed(matrix, lineSize, &height, &maxPixel, type, &width);

  } else  {

    matrix = unpack(matrix, &width, &height);
    type = "P2";
    printUnpacked(&matrix, &width, &height, &maxPixel, type);

  }

  for (i = 0; i < height; i++)  {
    free(matrix[i]);
  }
  free(matrix);
  free(lineSize);

  return 0;

}
