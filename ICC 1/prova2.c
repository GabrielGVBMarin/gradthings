#include <stdio.h>
#include <math.h>
int main()  {
  int quant, tambloco, arquivos[100], soma = 0, blocosusados = 1;
  scanf("%d", &quant);
  scanf("%d", &tambloco);
  for ( int i = 0; i < quant; i++)  {
    scanf("%d", &arquivos[i]);
  }
  for ( int k = 0; k < quant; k++)  {
    soma = soma + arquivos[k];
    if ( soma > tambloco )  {
      blocosusados++;
      soma = arquivos[k];
    }
  }
printf("Blocos ocupados: %d", blocosusados);
  return 0;
}
