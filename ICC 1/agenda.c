#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  int dia;
  int mes;
  int ano;
  char atividade[300];
} data;

typedef struct  {
  int hora;
  int min;
  int seg;
} hora;

void printa(data, hora);

int main()  {

  int quantidade;
  scanf("%d", &quantidade);
  data *data_regis = NULL;
  data_regis = (data*) malloc(quantidade*sizeof(data));
  hora *horario = NULL;
  horario = (hora*) malloc(quantidade*sizeof(hora));

  for ( int i = 0; i < quantidade; i++) {
    scanf("%d %d %d %d %d %d\n", &data_regis[i].dia, &data_regis[i].mes, &data_regis[i].ano, &horario[i].hora, &horario[i].min, &horario[i].seg);
    fgets(data_regis[i].atividade, 300, stdin);
  }

  for ( int i = 0; i < quantidade; i++) {
    printa(data_regis[i], horario[i]);
  }

  return 0;
}

void printa(data diax, hora horario) {
  printf("%02d/%02d/%d - %02d:%02d:%02d\n", diax.dia, diax.mes, diax.ano, horario.hora, horario.min, horario.seg);
  printf("%s", diax.atividade);
}
