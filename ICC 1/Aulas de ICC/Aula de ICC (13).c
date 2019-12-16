#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()  {

  FILE *arq;
  char nome[10] = "atireitir";
  arq = fopen("saida.txt", "w");
  assert(arq);
  printf("%s", nome);
  fprintf(arq, "%s", nome);
  fwrite(&agenda, sizeof(agenda), 1, arq);
  fwrite(&x, sizeof(int), 1, arq);
  fread(&agenda, sizeof(agenda), 1, arq);
  fread(&x, sizeof(int), 1, arq);
  fclose(arq); // fecha o arquivo
  feof(arq); // restorna se achou o EOF
  //fscanf(arq, "%s %d", nome, &idade);

  //********** PARA BINARIO ***************
  fwrite(&aluno1, sizeof(tAluno), 1, arq);
  int seila = fclose(arq); //fecha o programa aberto, igual ao free, tem que sempre fechar;
  return 0;
}
