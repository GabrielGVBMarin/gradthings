#include <string.h>
#include <stdio.h>
#include <math.h>

void noiscarai(int*,int*,int*,int*);
void jupinto(int*,int*,int*,int*);
void mercuzao(int*,int*,int*,int*);
void tovenusvc(int*,int*,int*,int*);

int main()  {

  int segundos = 0, dias = 0, horas = 0, minutos = 0, segstart = 0;
  char planeta[20] = {0};

  scanf("%d %s", &segundos, planeta);
  segstart = segundos;
 if (strcmp(planeta, "Terra") == 0)  {
   noiscarai(&segundos, &minutos, &horas, &dias);
 }
 else if (strcmp(planeta, "Jupiter") == 0)  {
   jupinto(&segundos, &minutos, &horas, &dias);
 }
 else if (strcmp(planeta, "Mercurio") == 0) {
   mercuzao(&segundos, &minutos, &horas, &dias);
 }
 else if (strcmp(planeta, "Venus") == 0)  {
   tovenusvc(&segundos, &minutos, &horas, &dias);
 }

  printf("%d segundos no planeta %s equivalem a:\n", segstart, planeta);
  printf("%d dias, %d horas, %d minutos e %d segundos", dias, horas, minutos, segundos);

  return 0;
}

void noiscarai(int *segundos, int *minutos, int *horas, int *dias)  {
  *minutos = *segundos/60;
  *segundos = *segundos%60;
  *horas = *minutos/60;
  *minutos = *minutos%60;
  *dias = *horas/24;
  *horas = *horas%24;
}

void jupinto(int *segundos, int *minutos, int *horas, int *dias)  {
  *minutos = *segundos/60;
  *segundos = *segundos%60;
  *horas = *minutos/60;
  *minutos = *minutos%60;
  *dias = *horas/10;
  *horas = *horas%10;
}

void mercuzao(int *segundos, int *minutos, int *horas, int *dias) {
  *minutos = *segundos/60;
  *segundos = *segundos%60;
  *horas = *minutos/60;
  *minutos = *minutos%60;
  *dias = *horas/1408;
  *horas = *horas%1408;
}

void tovenusvc(int *segundos, int *minutos, int *horas, int *dias)  {
  *minutos = *segundos/60;
  *segundos = *segundos%60;
  *horas = *minutos/60;
  *minutos = *minutos%60;
  *dias = *horas/5832;
  *horas = *horas%5832;
}
