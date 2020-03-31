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
	char *nome;
	char *sobrenome;
	char *curso;
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
				// printf("ftell : %ld\n", ftell(df));
				insereRegistro(df);
			break;
			case 2:
				printf("Insira o Numero USP : ");
				scanf("%d", &buscaNumeroUSP);
				// printf("ftell : %ld\n", ftell(df));
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
        df= fopen("alunos.dad", "ab+");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
}


/* demais metodos a serem implementados */
void insereRegistro(FILE *arq) {

	tipoAluno aluno;
	int len = 0;

	char *string = NULL;
	string = (char*) calloc(100, sizeof(char));

	printf("NUSP : ");
	scanf("%d", &aluno.numUSP);

	printf("Primeiro nome : ");

	scanf("%s", string);
	aluno.nome = (char*) calloc((int) strlen(string), sizeof(char));
	strcpy(aluno.nome, string);
	// printf("%s == %s\n", string, aluno.nome);

	printf("Ultimo sobrenome : ");

	scanf("%s", string);
	aluno.sobrenome = (char*) calloc((int) strlen(string), sizeof(char));
	strcpy(aluno.sobrenome, string);
	// printf("%s == %s\n", string, aluno.sobrenome);

	printf("Abreviacao do curso (BCC, BSI, ESTAT...) : ");

	scanf("%s", string);
	aluno.curso = (char*) calloc((int) strlen(string), sizeof(char));
	strcpy(aluno.curso, string);
	// printf("%s == %s\n", string, aluno.curso);

	printf("Nota : ");
	scanf("%f", &aluno.nota);

	int tamanho = 3+(int)strlen(aluno.nome)+(int)strlen(aluno.sobrenome)
					+(int)strlen(aluno.curso)+sizeof(int)+sizeof(float);
	printf("TAMANHO : %d\n", tamanho);

	if (pesquisaRegistro(aluno.numUSP, arq)) {
		printf("Usuário já cadastrado !!\n");
	} else {
		fwrite(&tamanho, sizeof(int), 1, arq);
		printf("ESCREVEU TAMANHO E TA NA : %ld\n", ftell(arq));

		fwrite(&aluno.numUSP, sizeof(int), 1, arq);
		printf("ESCREVEU NUSP : %ld\n", ftell(arq));

		len = strlen(aluno.nome);
		fwrite(&len, sizeof(int), 1, arq);
		fwrite(&aluno.nome, sizeof(char), strlen(aluno.nome), arq);
		printf("ESCREVEU NOME : %ld\n", ftell(arq));

		len = strlen(aluno.sobrenome);
		fwrite(&len, sizeof(int), 1, arq);
		fwrite(&aluno.sobrenome, sizeof(char), strlen(aluno.sobrenome), arq);
		printf("ESCREVEU SOBRENOME : %ld\n", ftell(arq));

		len = strlen(aluno.curso);
		fwrite(&len, sizeof(int), 1, arq);
		fwrite(&aluno.curso, sizeof(char), strlen(aluno.curso), arq);
		printf("ESCREVEU CURSO : %ld\n", ftell(arq));

		fwrite(&aluno.nota, sizeof(float), 1, arq);
		// fwrite(&aluno, tamanho, 1, arq);
		printf("ESCREVEU ALUNO E TA NA : %ld\n", ftell(arq));
	}
	free(string);
}

tipoAluno* pesquisaRegistro(int nuspBuscado, FILE *arq) {
	rewind(arq);
	// tipoAluno *aluno = (tipoAluno*) calloc(1, sizeof(tipoAluno));
	tipoAluno aluno;
	int tamanho = 0;

	while(fread(&tamanho, sizeof(int), 1, arq)) {
		printf("LEU TAMANHO E TA NA : %ld\n", ftell(arq));
		// fread(aluno, tamanho, 1, arq);

		fread(&aluno.numUSP, sizeof(int), 1, arq);

		fread(&tamanho, sizeof(int), 1, arq);
		fread(&aluno.nome, sizeof(char), tamanho, arq);

		fread(&tamanho, sizeof(int), 1, arq);
		fread(&aluno.sobrenome, sizeof(char), tamanho, arq);

		fread(&tamanho, sizeof(int), 1, arq);
		fread(&aluno.curso, sizeof(char), tamanho, arq);

		fread(&aluno.nota, sizeof(float), 1, arq);

		printf("LEU ALUNO E TA NA : %ld\n", ftell(arq));
		if (aluno.numUSP == nuspBuscado) {
			// printf("Leu : %d\n", tamanho);
			printf("\n\nNUSP : %08d\n", aluno.numUSP);
			printf("Primeiro nome : %s\n", aluno.nome);
			printf("Ultimo sobrenome : %s\n", aluno.sobrenome);
			printf("Abreviacao do curso : %s\n", aluno.curso);
			printf("Nota : %f\n\n", aluno.nota);
			fseek(arq, 0, SEEK_END);
			return &aluno;
		}
	}

	printf("NUSP BUSCADO : %d\n", nuspBuscado);
	printf("Aluno nao encontrado !\n");
	fseek(arq, 0, SEEK_END);
	return NULL;
	// };

}

void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(df);
}
