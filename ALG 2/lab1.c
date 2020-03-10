/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 1 - Arquivos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define TAM 16

typedef struct {
	int nusp;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} tipoAluno;
typedef tipoAluno ALUNO;

void criaArquivo(FILE *);
void insereRegistro(ALUNO*, int);
void leRegistro();
void pesquisaRegistro(ALUNO*, int);
void imprimeRegistro();
void escreverRegistro(ALUNO*, FILE*, int);
void finalizaExecucao(FILE *, ALUNO*);

int main(void) {
	FILE *df;
	int comando = 0;
	int quantidadePreenchida = 0;
	ALUNO *alunos = (ALUNO*) calloc(quantidadePreenchida+1, sizeof(ALUNO));

	do {
	    df = fopen("alunos.dad", "r+");
	    if (df == NULL) criaArquivo(df);
	} while(df == NULL);

	while(fread(alunos, sizeof(ALUNO), 1, df) == 1) {
		// LER ARQUIVO E SALVA PRA TER O TAMANHO E SALVAR DEPOIS
		quantidadePreenchida++;
		// printf("alunos %s\n", alunos[quantidadePreenchida-1].nome);
		alunos = (ALUNO*) realloc(alunos, (quantidadePreenchida+1)*sizeof(ALUNO));
	}

	do {
		printf("Operacoes:\n1 - Gravar\n2 - Pesquisar\n0 - Finalizar\n\n");
		scanf("%d", &comando);
		if (comando == 1) {
			insereRegistro(alunos, quantidadePreenchida);
			quantidadePreenchida++;
		} else if (comando == 2) {
			pesquisaRegistro(alunos, quantidadePreenchida);
		}

		/* Programa deve proceder de acordo com a operacao desejada */


	} while(comando > 0);

	escreverRegistro(alunos, df, quantidadePreenchida);
	imprimeRegistro(alunos, quantidadePreenchida);
	finalizaExecucao(df, alunos);

return 0;

}

void criaArquivo(FILE *df) {

    if (df== NULL) {
        df= fopen("alunos.dad", "w");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
}


/* demais metodos a serem implementados */
void insereRegistro(ALUNO *alunos, int quantidadePreenchida) {
	int nusp;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;

	printf("Insira o numero USP\n");
	scanf("%d", &nusp);
	printf("Insira o nome\n");
	scanf("%s", nome);
	printf("Insira o sobrenome\n");
	scanf("%s", sobrenome);
	printf("Insira o curso\n");
	scanf("%s", curso);
	printf("Insira a nota\n");
	scanf("%f", &nota);

	alunos[quantidadePreenchida].nusp = nusp;
	strcpy(alunos[quantidadePreenchida].nome, nome);
	strcpy(alunos[quantidadePreenchida].sobrenome, sobrenome);
	strcpy(alunos[quantidadePreenchida].curso, curso);
	alunos[quantidadePreenchida].nota = nota;
}

void pesquisaRegistro(ALUNO *alunos, int quantidadePreenchida) {
	int i;
	int nuspPesquisado;
	printf("Insira o NUSP a ser pesquisado\n");
	scanf("%d", &nuspPesquisado);

	for (i = 0; i < quantidadePreenchida; i++) {
		if (alunos[i].nusp == nuspPesquisado) {
			printf("\n\nAluno: %s\n", alunos[i].nome);
			printf("Sobrenome: %s\n", alunos[i].sobrenome);
			printf("Curso: %s\n", alunos[i].curso);
			printf("Nota: %f\n\n\n", alunos[i].nota);
			break;
		}
	}
}

void imprimeRegistro(ALUNO *alunos, int quantidadePreenchida) {
	int i;
	for (i = 0; i < quantidadePreenchida; i++) {

		printf("\n\nNUSP: %d\n", alunos[i].nusp);
		printf("Aluno: %s\n", alunos[i].nome);
		printf("Sobrenome: %s\n", alunos[i].sobrenome);
		printf("Curso: %s\n", alunos[i].curso);
		printf("Nota: %f\n\n\n", alunos[i].nota);

	}
}

void escreverRegistro(ALUNO *alunos, FILE *df, int quantidadePreenchida) {
	rewind(df);
	fwrite(alunos, sizeof(ALUNO), quantidadePreenchida, df);
}

void finalizaExecucao(FILE *df, ALUNO *alunos) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(df);
	free(alunos);

}
