#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MIN 2
#define MAX 3

void conta(float matriz[2][3],float *x,float *y){
  *y=((matriz[1][2])*(matriz[0][0])-((matriz[1][0])*(matriz[0][2])))/((matriz[0][0])*(matriz[1][1])-(matriz[1][0])*(matriz[0][1]));
  *x=((matriz[0][2]-matriz[0][1]*(*y))/(matriz[0][0]));
}

int main (){
  int i,j;
  float matriz[MIN][MAX],x,y;
  for(i=0;i<MIN;i++){
    for(j=0;j<MAX;j++){
      scanf("%f",&matriz[i][j]);
    }
  }
  if(((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]))==0){
    if((matriz[0][0]/matriz[1][0])==(matriz[0][1]/matriz[1][1])&&(matriz[0][0]/matriz[1][0])==(matriz[0][2]/matriz[1][2])){
      printf("SPI");
    }
    else{
      printf("SI");
    }
  }
  else{
    printf("SPD\n");
    conta(matriz,&x,&y);
     printf("%.2f %.2f",x,y);
  }

	return 0;
}
