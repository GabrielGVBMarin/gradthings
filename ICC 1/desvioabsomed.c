#include <stdio.h>
#include <math.h>
#include <string.h>

  void lemat(double[10], double[1]);
  void mednormal(double[1], double[1]);
  void medabsoluta(double[10], double[1], double[1]);

  int main()  {

    double num[10];
    double soma[1];
    double mednormals[1];
    soma[0] = 0;
    mednormals[0] = 0;
    lemat(num, soma);
    mednormal(soma, mednormals);
    medabsoluta(num, mednormals, soma);
    mednormal(soma, mednormals);

    printf("%.2lf", mednormals[0]);

    return 0;
  }

  void lemat(double num[10], double soma[1])  {
    for ( int i = 0; i < 10; i++) {
      scanf("%lf", &num[i]);
      soma[0] = soma[0] + num[i];
    }
  }

  void mednormal(double soma[1], double media[1])  {
    media[0] = soma[0]/10;
  }

  void  medabsoluta(double num[10], double mednormal[1], double somas[1])  {
    somas[0] = 0;
    for ( int i = 0; i < 10; i++) {
      if (num[i] >= mednormal[0])  {
        num[i] = num[i] - mednormal[0];
      }
      else if (num[i] < mednormal[0]) {
        num[i] = mednormal[0] - num[i];
      }
    }
    for ( int k = 0; k < 10; k++) {
      somas[0] = somas[0] + num[k];
    }
  }
