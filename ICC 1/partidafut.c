#include <stdio.h>
#include <math.h>



int main()  {

  int ponto1, ponto2, score1, score2;

  scanf("%d %d", &ponto1, &ponto2);
  scanf("%dx%d", &score1, &score2);

  if ( score1 > score2) {
    ponto1 = ponto1 + 3;
  }
  else if ( score2 > score1 ) {
    ponto2 = ponto2 + 3;
  }
  else if ( score1 == score2) {
    ponto1 += 1;
    ponto2+=1;
  }

  printf("%d %d", ponto1, ponto2);

  return 0;
}
