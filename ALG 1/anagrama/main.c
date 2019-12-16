// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>


int main(void)  {

  char *nomeArquivo = NULL, *palavra = NULL;
  nomeArquivo = leStringsAlocaDin();
  HASH *hash = hashCreate();

  FILE *arq = fopen(nomeArquivo, "r");

  palavra = (char*) calloc(20, sizeof(char));

  while(fscanf(arq, "%s", palavra) != EOF) {
    addPalavra(hash, palavra);
  }
  printMaisRepetidas(hash);

  freeAll(hash);

  return 0;

}
