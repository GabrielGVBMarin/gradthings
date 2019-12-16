#include <teste.h>

int main(void)  {

  // inicia as variaveis e le o tamanho do vetor
  int tamanho, i;
  double *resultado = NULL, *vetor = NULL;
  scanf("%d", &tamanho);

  //alocação dos vetores
  vetor = (double*) calloc(tamanho, sizeof(double));
  resultado = (double*)  calloc(tamanho, sizeof(double));

  //leitura da entrada
  for (i = 0; i < tamanho; i++) {
    scanf("%lf", &vetor[i]);
  }

  //func pra calcular
  DCTII(resultado, vetor, (long)tamanho);

  //print do resultado final
  for (i = 0; i < tamanho; i++) {
    printf("%lf\n", resultado[i]);
  }

  free(vetor);
  free(resultado);

  return 0;
}
