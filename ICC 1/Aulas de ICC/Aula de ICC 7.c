#include <stdio.h>
#include <assert.h>

int main()  {

  char *p[10];
  for ( i = 0; i < 10; i++) {
    p[i] = (char*) malloc(10);
    assert(p[i]);
    scanf("%s", p[i]);
  }
  // tratar o vetor ponteiro como uma matriz, ja que ele pega e salva a string na quantidade exata que precisa da memoria
  
  return 0;
}
