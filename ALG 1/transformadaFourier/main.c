// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>


int main(void)  {

  VETOR *header = leArquivo();
  int magNumbers = 0, i;
  int *significantes = (int*) malloc(header->C*sizeof(int));

  _Complex double *coeficientes = calculaFourier(header);
  geraVetorNovo(header, coeficientes, &magNumbers, significantes);

  // PRINTA O QUE É PEDIDO
  printf("%d\n", header->size);
  printf("%d\n", magNumbers);
  for (i = 0; i < header->C; i++) {
    printf("%d ", significantes[i]);
  }
  printf("\n");

  unsigned char *resultado = inverseFourierTransform(header, coeficientes);
  // PRINTA RESULTADO DA INVERSA
  for (i = 0; i < header->size; i++)  {
    printf("%d\n", resultado[i]);
  }

  // FREE
  freeAll(header, coeficientes, resultado, significantes);

  return 0;

}
