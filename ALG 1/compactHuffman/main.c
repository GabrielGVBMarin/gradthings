#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

int main()  {

  int i;
  char *text, *textCompac, *textDescompac;
  text = (char *)malloc(10001 * sizeof(char));
  HUFFMAN_TABLE *table = huffmanCreate();

  // leitura do texto
  for(i = 0; (text[i] = getchar()) != '\n' && i < 10000; ++i);
  text[i] = '\0';

  // compacta o texto e modifica a tabela
  int sizeCompac = huffmanCompact(text, &textCompac, &table);
  // descompacta o texto baseado na tabela criada
  textDescompac = huffmanDescompact(textCompac, sizeCompac, table);

  // imprime o tamanho do texto original e a compactação e descompactação
  printf("%d\n", (int) strlen(text));
  printf("%d\n", sizeCompac);
  printf("%s\n", textDescompac);

  freeHuffman(&table);
  free(text);
  free(textCompac);
  free(textDescompac);

  return 0;
}
