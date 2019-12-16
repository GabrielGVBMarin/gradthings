#include <stdio.h>
#include <stdlib.h>

typedef struct  {
int dia;
int mes;
int ano;
char sexo;
float altura;
float peso;
char nome[50];
} bebe;

int main()  {

  bebe registro_bin[6], registro_txt[6];
  int bebe_homem, bebe_mulher;
  float altura_homem = 0, altura_mulher = 0, peso_homem = 0, peso_mulher = 0;
  FILE *bin, *txt;
  bin = fopen("dados-bebes.bin", "rb");
  txt = fopen("dados-bebes.txt", "r");

  for ( int i = 0; i < 6; i++)  {
    fread(&registro_bin[i], sizeof(bebe), 1, bin);
    if ( registro_bin[i].sexo == 'm' )  {
      bebe_homem++;
      altura_homem = altura_homem + registro_bin[i].altura;
      peso_homem = peso_homem + registro_bin[i].peso;
    }
    else {
      bebe_mulher++;
      altura_mulher = altura_mulher + registro_bin[i].altura;
      peso_mulher = peso_mulher + registro_bin[i].peso;
    }

    fscanf(txt, "%d %d %d %c %f %f %[^\n]s", &registro_txt[i].dia, &registro_txt[i].mes, &registro_txt[i].ano, &registro_txt[i].sexo, &registro_txt[i].altura, &registro_txt[i].peso, registro_txt[i].nome);

    if ( registro_txt[i].sexo == 'm' )  {
      bebe_homem++;
      altura_homem = altura_homem + registro_txt[i].altura;
      peso_homem = peso_homem + registro_txt[i].peso;
    }
    else {
      bebe_mulher++;
      altura_mulher = altura_mulher + registro_txt[i].altura;
      peso_mulher = peso_mulher + registro_txt[i].peso;
    }

  }

  printf("Dados dos Bebes Homens: \n");
  printf("Total: %d\n", bebe_homem);
  printf("Media da Altura: %.2f metros\n", altura_homem/bebe_homem);
  printf("Media do Peso: %.2f kg\n\n", peso_homem/bebe_homem);

  printf("Dados dos Bebes Mulheres: \n");
  printf("Total: %d\n", bebe_mulher);
  printf("Media da Altura: %.2f metros\n", altura_mulher/bebe_mulher);
  printf("Media do Peso: %.2f kg\n", peso_mulher/bebe_mulher);



  fclose(bin);
  fclose(txt);
  return 0;
}
