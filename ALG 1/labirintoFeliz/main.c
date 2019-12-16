// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>


int main(void)  {

  MAPA *mapinha = fazLeitura();

  HEADER_CAMINHOS *ways = identificaCaminhos(mapinha);
  ways = filtradorDeCaminhos(mapinha, ways);
  printCaminhos(mapinha, ways);

  freeAll(mapinha, ways);
  return 0;

}
