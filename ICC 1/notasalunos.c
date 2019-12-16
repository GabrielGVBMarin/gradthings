#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct aluno{
int matricula;
char nome[50];
int idade;
char sexo;
float notas[5][3];
};
typedef struct aluno estudante;

void lerArqBin(estudante[3], FILE*);
void lerArqTxt(estudante[3], FILE*);
void processarNotas(estudante[3]);

int main()  {
 FILE *txt, *bin;
 txt = fopen("notas.txt", "r");
 assert(txt);
 bin = fopen("alunos.bin", "rb");
 assert(bin);
 
 estudante estudantes[3];

 lerArqBin(estudantes, bin);
 lerArqTxt(estudantes, txt);
 processarNotas(estudantes);

 fclose(bin);
 fclose(txt);
 return 0;
}

void lerArqBin(estudante estudantes[3], FILE *bin)  {
  for( int i = 0; i < 3; i++) {
    fread(&estudantes[i], sizeof(estudante), 1, bin);
  }
}

void lerArqTxt(estudante estudantes[3], FILE *txt)  {
  for ( int i = 0; i < 3; i++)  {
    fscanf(txt, "%d", &estudantes[i].matricula);
    for ( int j = 0; j < 5; j++)  {
      for ( int k = 0; k < 3; k++)  {
        fscanf(txt, "%f", &estudantes[i].notas[j][k]);
      }
    }
  }
}

void processarNotas(estudante estudantes[3]) {
  float medias [3][5];
  for ( int w = 0; w < 3; w++)  {
    for ( int i = 0; i < 5; i++)  {
      medias[w][i] = estudantes[w].notas[i][0] + estudantes[w].notas[i][1] + estudantes[w].notas[i][2];
    }

    printf("%s\n", estudantes[w].nome);

    float conta[5];
    for ( int j = 0; j < 5; j++)  {
      conta[j] = medias[w][j]/3;
      if ( conta[j] >= 5)  {
        printf("aprovado\n");
      }
      else {
        printf("reprovado\n");
      }
    }
    printf("\n");
  }
}
