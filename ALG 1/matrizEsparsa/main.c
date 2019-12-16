// Gabriel Guimarães Vilas Boas Marin 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

int main(void)  {

  int ncols, nrows, col, row = 0, value;
  char operation;

  scanf("%c", &operation);
  scanf("%d %d %d", &nrows, &nrows, &ncols);

  COMPLEX_SPARSE *sparse = createSparse(nrows, ncols, 0);

  // FAZ LEITURA ATÉ ACHAR NOVA MATRIZ
  while (row != -1)  {
    scanf("%d %d %d", &row, &col, &value);
    if (row != -1)  putSparse(sparse, row, col, (double) value);
  }

  COMPLEX_SPARSE *secondSparse = createSparse(col, value, 0);

  // FAZ LEITURA ATÉ ACHAR FINAL DA ENTRADAS
  while (!feof(stdin)) {
    scanf("%d %d %d", &row, &col, &value);
    putSparse(secondSparse, row, col, (double) value);
  }

  COMPLEX_SPARSE *new = NULL;
  if (operation == 'M') {
    new = multiplySparse(sparse, secondSparse);
    // FREE NO QUE NÃO VAI USAR MAIS
    complex_sparse_free(sparse);
    complex_sparse_free(secondSparse);
  } else {
    plusSparse(sparse, secondSparse);
    new = secondSparse;
    // FREE NO QUE NÃO VAI USAR MAIS
    complex_sparse_free(sparse);
  }

  printSparse(new);

  complex_sparse_free(new);

  return 0;
}
