/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 2 - Índices */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

// inserir registros, pesquisar e apresentar registros, remover registros
// Não ordenado e sequencial
// Tamanho fixo e campo fixo

// {
// 	NumeroUSP, (chave primaria)
// 	nome,
// 	sobrenome,
// 	curso,
// 	nota
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define TAM 16

#define SUCCESS 0
#define INVALID_POS -1
#define INVALID_KEY -2

typedef struct {
	/* aqui devem ser definidos os elementos necessários para compor o índice */
	/* voce pode utilizar variáveis estáticas ou dinâmicas */
	int chavePrimaria;
	int pos; // Se a pos é positivo, ta valendo se for negativo significa que o registro foi deletado
} indexAluno;
// 8 Bytes

typedef struct {
	int numUSP;	// 4 bytes
	char nome[TAM]; // 16 bytes
	char sobrenome[TAM]; // 16 bytes
	char curso[TAM]; // 16 bytes
	float nota; // 4 bytes;
} tipoAluno;
// 56 bytes

void indexDump(indexAluno*, int);
void criaArquivo(FILE*);
void criaIndex(FILE*);
indexAluno* readIndexFile(int*);
void insereIndex(indexAluno*, int);
void insereIndexRAM();
int ordenaIndex(const void*, const void*);
int insereRegistro(FILE*, int*, indexAluno*, int);
int pesquisaIndex(int, indexAluno*, int);
int pesquisaRegistro(FILE*, int);
int imprimeRegistro(tipoAluno);
void imprimeRegistroTodo();
int removeRegistro(FILE*, int);
int removeIndex(int, indexAluno**, int*);
void finalizaExecucao(FILE*);

int main(int argc, char **argv) {

	FILE *arq = NULL;

	int indexCounter = 0;
	indexAluno *indexStruct = readIndexFile(&indexCounter);

	do {
	    arq= fopen("alunos.dad", "r+");
	    if (arq== NULL) criaArquivo(arq);
	} while(arq== NULL);

	int comando = 0, chave = 0, pos = 0, procura = 0;
	printf("******************    Programa inicializado    ******************\n");

	do {
		printf("\nOperacoes:\n1 - Gravar\n2 - Remover\n3 - Pesquisar\n4 - Dump registros\n5 - Dump index\n0 - Finalizar\n\n");
		/* Programa deve proceder de acordo com a operacao desejada */
		scanf("%d", &comando);
		switch (comando) {
			case 1:
				chave = 0;
				pos = insereRegistro(arq, &chave, indexStruct, indexCounter); // retorna negativo se aluno ja inserido
				if (pos >= 0) insereIndexRAM(&indexStruct, &indexCounter, pos, chave);
			break;
			case 2:
				printf("Insira o número USP que deseja deletar: ");
				scanf("%d", &procura);
				pos = pesquisaIndex(procura, indexStruct, indexCounter); // Retorna negativo se aluno já deletado
				if (pos < 0) {
					printf("Aluno já deletado !!!\n");
				} else {
					removeIndex(procura, &indexStruct, &indexCounter);
					removeRegistro(arq, pos);
				}
			break;
			case 3:
				printf("Insira o número USP que deseja encontrar: ");
				scanf("%d", &procura);
				procura = pesquisaIndex(procura, indexStruct, indexCounter); // Retorna negativo se o aluno buscado foi deletado
				if (procura < 0) printf("Aluno deletado !!!\n");
				else pesquisaRegistro(arq, procura);
			break;
			case 4:
				imprimeRegistroTodo(arq, indexCounter);
			break;
			case 5:
				indexDump(indexStruct, indexCounter);
			break;
		}


	} while( comando> 0);

	printf("******************    Programa finalizado    ******************\n");
	insereIndex(indexStruct, indexCounter); // Reescreve o arquivo index.dad
	finalizaExecucao(arq);
	free(indexStruct);

return 0;

}

void indexDump(indexAluno *index, int counter) {
	printf("QUANTIDADE: %d\n", counter);
	for(int i = 0; i < counter; i++) {
		if (index[i].pos < 0) continue; // Pula registros deletados
		printf("CHAVE: %d\tPOSIÇÃO: %d\n", index[i].chavePrimaria, index[i].pos);
	}
}

void criaArquivo(FILE *arq) {

    if (arq== NULL) {
        arq= fopen("alunos.dad", "w+");        /* Se nao existir, cria o arquivo de dados */
        fclose(arq);
        arq= NULL;
    }
}

void insereIndexRAM(indexAluno **index, int *counter, int pos, int chave) {

	(*index) = (indexAluno*) realloc((*index), (*counter+1)*sizeof(indexAluno));

	(*index)[(*counter)].chavePrimaria = chave;
	(*index)[(*counter)].pos = pos;

	*counter += 1;
	qsort((*index), (*counter), sizeof(indexAluno), ordenaIndex); // Ordena o vetor de index
}

int ordenaIndex(const void *a, const void *b) {
	return ( (*(indexAluno*)a).chavePrimaria - (*(indexAluno*)b).chavePrimaria );
}

indexAluno* readIndexFile(int *counter) {
	FILE *arq = fopen("index.dad", "r+");
	if (arq == NULL) return (indexAluno*) calloc(1, sizeof(indexAluno));

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(indexAluno); // Pega quantos registros existem
	indexAluno *index = (indexAluno*) calloc(quantidadeDeRegistros, sizeof(indexAluno)); // Aloca memoria pra passar os indices pra RAM
	*counter = quantidadeDeRegistros; // Atualiza contador
	rewind(arq);
	fread(index, sizeof(indexAluno), quantidadeDeRegistros, arq); // Faz leitura dos indices
	rewind(arq);

	fclose(arq);
	return index;
}

void insereIndex(indexAluno *index, int counter) {
	/* neste método devem sem implementadas as operações de inserção de um RRN no índice, que deve ser mantido ordenado */
	FILE *arq = fopen("index.dad", "w+");
	fwrite(index, sizeof(indexAluno), counter, arq); // Escreve arquivo index.dad com os indices
}


// Retorna negativo se registro ja existe ou foi deletado
int pesquisaIndex(int chave, indexAluno *index, int counter) {
	/* aqui a pesquisa deve ser feita pela chave primária no índice por meio de uma busca binária para, então, encontrado o RRN, dar um seek no arquivo para recuperar o registro*/
	int i = 0;
	int f = counter -1;
	int meio;

	// *** Busca binaria ***
	while (i<=f) {
		meio = (i+f)/2;
 		if (index[meio].chavePrimaria == chave || index[meio].chavePrimaria == chave*(-1)) return index[meio].pos;
		else if (chave > index[meio].chavePrimaria) i = meio+1;
		else f = meio-1;
	}
	return INVALID_KEY; // Se n encontrar retorna invalido

}

int removeIndex(int chave, indexAluno **src, int *counter) {
	/* neste método devem sem implementadas as operações de remoção de um RRN no índice, que deve ser mantido ordenado */

	int i = 0;
	int f = (*counter) -1;
	int meio;

	// Busca binaria pra marcar registro como deletado
	while (i<=f) {
		meio = (i+f)/2;
 		if ((*src)[meio].chavePrimaria==chave) {
			(*src)[meio].pos = (*src)[meio].pos*(-1);
			return SUCCESS;
		}
		else if (chave>(*src)[meio].chavePrimaria) i = meio+1;
		else f = meio-1;
	}
	return INVALID_POS;
}

int insereRegistro(FILE *arq, int *chave, indexAluno *index, int counter) {
	/* neste método devem sem implementadas as operações de inserção registro no arquivo, lembrando que o índice deve se manter consistente com o arquivo */
	fseek(arq, 0, SEEK_END);
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

	if (0 > pesquisaIndex(*chave, index, counter)) { // pesquisa index retorna negativo se registro ja existir
		fwrite(&aluno, sizeof(tipoAluno), 1, arq);
		*chave = aluno.numUSP;

		fseek(arq, 0, SEEK_END);
		int final = (int) ftell(arq);
		rewind(arq);

		return ((final/sizeof(tipoAluno))-1); // Retorna posição que o aluno foi inserido
	} else {
		printf("Aluno já cadastrado !!!!\n");
		return -pesquisaIndex(*chave, index, counter); // Negativo pra demonstrar que ja foi inserido
	}

}



int pesquisaRegistro(FILE *arq, int pos) {
	if (pos == -1) return INVALID_POS;
	tipoAluno aluno;

	fseek(arq, sizeof(tipoAluno)*pos, SEEK_SET);

	fread(&aluno, sizeof(tipoAluno), 1, arq);
	imprimeRegistro(aluno);

	rewind(arq);
	return SUCCESS;
}

/* demais metodos a serem implementados */

int removeRegistro(FILE *arq, int pos) {
	/* pode ser implementada apenas uma remoção lógica */
	if (pos < 0) return INVALID_POS;

	tipoAluno aluno;

	fseek(arq, sizeof(tipoAluno)*pos, SEEK_SET);
	fread(&aluno, sizeof(tipoAluno), 1, arq);

	aluno.numUSP = aluno.numUSP*(-1); // Deixa nusp negativo quanto registro é removido

	fseek(arq, -sizeof(tipoAluno), SEEK_CUR);
	fwrite(&aluno, sizeof(tipoAluno), 1, arq);

	rewind(arq);
	return SUCCESS;
}

int imprimeRegistro(tipoAluno aluno) {
	printf("\n\nNUSP : %08d\n", aluno.numUSP);
	printf("Primeiro nome : %s\n", aluno.nome);
	printf("Ultimo sobrenome : %s\n", aluno.sobrenome);
	printf("Abreviacao do curso : %s\n", aluno.curso);
	printf("Nota : %f\n\n", aluno.nota);

	return 1;
}

void imprimeRegistroTodo(FILE *arq) {
	tipoAluno aluno;
	rewind(arq);
	while(fread(&aluno, sizeof(tipoAluno), 1, arq)) {
		if (aluno.numUSP < 0) continue; // Pula de registro foi deletado
		else imprimeRegistro(aluno);
	}
	rewind(arq);
}

void finalizaExecucao(FILE *arq) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(arq);
}
