/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 1 - Arquivos */
// Gabriel Guimarães Vilas Boas Marin	NUSP: 11218521
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define TAM 16

typedef int tipoChave;

// NUSP
// nome
// sobrenome
// curso
// nota

typedef struct {
	tipoChave numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} tipoAluno;

void criaArquivo(FILE*);
void insereRegistro(FILE*);
tipoAluno* pesquisaRegistro(int, FILE*);
void imprimeRegistro();
void finalizaExecucao(FILE*);

int main(void) {
	FILE *df;
	int comando = 0;
	int buscaNumeroUSP;

	do {
	    df= fopen("alunos.dad", "r+");
	    if (df== NULL) criaArquivo(df);
	} while(df== NULL);

	fseek(df, 0, SEEK_END);

	do {
		printf("Operacoes:\n1 - Gravar\n2 - Pesquisar\n0 - Finalizar\n\n");
		scanf("%d", &comando);
		switch (comando) {
			case 1:
				printf("De entrada nos seguintes dados :\n");
				insereRegistro(df);
			break;
			case 2:
				printf("Insira o Numero USP : ");
				scanf("%d", &buscaNumeroUSP);
				pesquisaRegistro(buscaNumeroUSP, df);
			break;
			case 0:
				printf("Programa finalizado !\n");
			break;
			default:
				printf("Insira um digito valido !\n");
		}


	} while(comando > 0);


	finalizaExecucao(df);

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
void insereRegistro(FILE *arq) {

	tipoAluno aluno;

	printf("NUSP : ");
	scanf("%d", &aluno.numUSP);
	printf("Primeiro nome : ");
	scanf("%s", aluno.nome);
	printf("Ultimo sobrenome : ");
	scanf("%s", aluno.sobrenome);
	printf("Abreviacao do curso (BCC, BSI, ESTAT...) : ");
	scanf("%s", aluno.curso);
	printf("Nota : ");
	scanf("%f", &aluno.nota);

	fwrite(&aluno, sizeof(tipoAluno), 1, arq);
}

tipoAluno* pesquisaRegistro(int nuspBuscado, FILE *arq) {
	rewind(arq);
	tipoAluno *aluno = (tipoAluno*) calloc(1, sizeof(tipoAluno));

	while(fread(aluno, sizeof(tipoAluno), 1, arq) && aluno->numUSP != nuspBuscado);

	if (aluno) {
		printf("\n\nNUSP : %08d\n", aluno->numUSP);
		printf("Primeiro nome : %s\n", aluno->nome);
		printf("Ultimo sobrenome : %s\n", aluno->sobrenome);
		printf("Abreviacao do curso : %s\n", aluno->curso);
		printf("Nota : %f\n\n", aluno->nota);
		fseek(arq, 0, SEEK_END);
		return aluno;
	} else {
		printf("Aluno nao encontrado !\n");
		fseek(arq, 0, SEEK_END);
		return NULL;
	};

}

void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(df);
}
