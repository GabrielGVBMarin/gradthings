#include <stdio.h>
#include <math.h>
#include <string.h>

void lemat(int*, int*, int*, int[6][3]);
void misturatudu(int, int, int, int[6][3], int[6][3]);
void printae(int[6][3], int[6][3]);

int main()  {

  int cor1,cor2,corres, start[6][3] = {0}, result[6][3] = {0};

  lemat(&cor1,&cor2,&corres,start);
  misturatudu(cor1, cor2, corres, start, result);
  printae(result, start);

  return 0;
}

void lemat(int *cor1, int *cor2, int *corres, int start[6][3]) {
  scanf("%d %d %d\n", cor1, cor2, corres);

  for ( int i = 0; i < 6 ; i++)  {
    for ( int j = 0; j < 3; j++)  {
      scanf("%d\n", &start[i][j]);
    }
  }
}

void misturatudu(int cor1, int cor2, int corres, int start[6][3], int result[6][3]) {

  for ( int i = 0; i < 6; i++)  {
    for ( int j = 0; j < 3; j++)  {
      result[i][j] = start[i][j];
    }
  }
  result[corres][0] = start[cor1][0]/2 + start[cor2][0]/2 + result[corres][0];
  result[corres][1] = start[cor1][1]/2 + start[cor2][1]/2 + result[corres][1];
  result[corres][2] = start[cor1][2]/2 + start[cor2][2]/2 + result[corres][2];

}

void printae(int result[6][3], int start[6][3])  {
  printf("Start:\n");
  for ( int i = 0; i < 6; i ++) {
    printf("Color(%d): [", i);
      printf("\t%d\t%d\t%d\t]", start[i][0], start[i][1], start[i][2]);
    printf("\n");
  }
  printf("\nResult:\n");
  for ( int i = 0; i < 6; i ++) {
    printf("Color(%d): [", i);
      printf("\t%d\t%d\t%d\t]", result[i][0], result[i][1], result[i][2]);
    printf("\n");
  }
}
