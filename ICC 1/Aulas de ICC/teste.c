#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()  {
  char seila[193];
  enum valdemar {corno, gordo, fdp, legal, anao, pirocudo, gostoso};
  enum valdemar caracteristica;
  printf("O valdemar eh alto ?\n");
  scanf("%s", seila);

  for ( int i = corno; i <= gostoso; i++) {
      caracteristica = fdp;
      printf("%d\n", caracteristica+1);
  }

  * >>= <>  != 

  return 0;
}
