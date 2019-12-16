#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100

void lemat(int mat[MAX][MAX], int, int);
void multiplica(int result[MAX][MAX], int mat1[MAX][MAX], int mat2[MAX][MAX], int, int);

int main()  {

int lin1, col1, mat1[MAX][MAX], mat2[MAX][MAX], lin2, col2, result[MAX][MAX];
scanf("%d %d", &lin1, &col1);
lemat(mat1, lin1, col1);
scanf("%d %d", &lin2, &col2);
lemat(mat2, lin2, col2);

multiplica(result, mat1, mat2, lin1, col1);

for ( int i = 0; i<lin1; i++)  {
  for( int j = 0; j < col2; j++)  {
    printf("%d ", result[i][j]);
  }
  printf("\n");
}
return 0;
}


void lemat(int mat[MAX][MAX], int lin, int col){
    for ( int l = 0; l < lin; l++) {
      for ( int c = 0; c < col; c++) {
        scanf("%d", &mat[l][c]);
      }
    }
}

void multiplica(int final[MAX][MAX], int mat1[MAX][MAX], int mat2[MAX][MAX], int lin, int col)  {
  int finals = 0;
  for (int  linn = 0; linn < lin; linn++) {
    for( int coln = 0; coln < col; coln++) {
      for ( int multi = 0; multi <= col; multi++) {
        final[linn][coln] += finals + mat1[linn][multi]*mat2[multi][coln];
      }
    }
  }
}
