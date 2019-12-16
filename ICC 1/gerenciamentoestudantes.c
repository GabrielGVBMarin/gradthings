#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  long int nusp;
  char nome[100];
  char curso[100];
  int idade;
} registro_aluno;

void consulta_nusp(registro_aluno*, long int, int);
void consulta_curso(registro_aluno*, char[100], int);
void imprime_tudo(registro_aluno*, int);

int main()  {

int contador = 0, opt;
long int nusp_consultado;
char curso_consultado[100];
registro_aluno *aluno = NULL;

while(1)  {
  aluno = (registro_aluno*) realloc(aluno, (contador+1)*sizeof(registro_aluno));
  scanf("%ld", &aluno[contador].nusp);
  if (aluno[contador].nusp == -1) {
    break;
  }
  scanf(" %[^\n]s", aluno[contador].nome);
  scanf(" %[^\n]s", aluno[contador].curso);
  scanf("%d", &aluno[contador].idade);
  contador++;
}

while (opt != -1) {
  scanf("%d", &opt);
  switch (opt) {
    case 1:
      scanf("%ld", &nusp_consultado);
      consulta_nusp(aluno, nusp_consultado, contador);
    break;
    case 2:
      scanf(" %[^\n]s", &*curso_consultado);
      consulta_curso(aluno, curso_consultado, contador);
    break;
    case 3:
      imprime_tudo(aluno, contador);
    break;
  }
}

  free(aluno);
  return 0;
}

void consulta_nusp(registro_aluno *registros, long int nusp_consultado, int contador) {
  for ( int i = 0; i < contador; i++) {
    if ( registros[i].nusp == nusp_consultado ) {
      printf("Nome: %s\n", registros[i].nome);
      printf("Curso: %s\n", registros[i].curso);
      printf("N USP: %ld\n", registros[i].nusp);
      printf("IDADE: %d\n\n", registros[i].idade);
    }
  }
}

void consulta_curso(registro_aluno *registros, char curso_consultado[100], int contador)  {
  for ( int i = 0; i < contador; i++) {
    if ( strcmp(registros[i].curso, curso_consultado) == 0 ) {
      printf("Nome: %s\n", registros[i].nome);
      printf("Curso: %s\n", registros[i].curso);
      printf("N USP: %ld\n", registros[i].nusp);
      printf("IDADE: %d\n\n", registros[i].idade);
    }
  }
}

void imprime_tudo(registro_aluno *registros, int contador) {
  for ( int i = 0; i < contador; i++) {
      printf("Nome: %s\n", registros[i].nome);
      printf("Curso: %s\n", registros[i].curso);
      printf("N USP: %ld\n", registros[i].nusp);
      printf("IDADE: %d\n\n", registros[i].idade);
  }
}
