/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 3 - Índices Secundários */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
// inserir registros, pesquisar e apresentar registros, remover registros
// Registro : : número USP, nome, sobrenome, curso e nota
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// VERIFICAÇÕES SE JÁ EXISTE
// VERIFICAÇÕES SE É VÁLIDO
// VERIFICAÇÕES SE FOI REMOVIDO

#define TAM 16

#define SUCCESS 0
#define INVALID_POS -1
#define INVALID_KEY -2
#define INVALID_NAME -3

typedef int tipoChave;

// Chave primaria é o número USP
typedef struct {
	/* aqui devem ser definidos os elementos necessários para compor o índice primário */
	/* voce pode utilizar variáveis estáticas ou dinâmicas */
	int chavePrimaria;
	int pos;
} index_p;

// Chave secundária é o sobrenome do aluno
typedef struct {
	/* aqui devem ser definidos os elementos necessários para compor o índice secundário */
	/* voce pode utilizar variáveis estáticas ou dinâmicas */
	char sobrenome[TAM];
	int pos;
} index_s;

typedef struct {
	tipoChave numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} tipoAluno;

void criaArquivo(FILE *);
index_p* carregaIndex(int*);
void insereIndex();
int qsortComparar(const void*, const void*);
void ordenaIndex();
index_s* carregaIndexSecundario(int*);
void criaIndexSec();
void insereIndexSec();
void removeIndexSec();
tipoAluno* leituraDosDadosDoAluno();
void insereRegistro();
int pesquisaIndex();
void pesquisaChaveSecundaria();
void pesquisaRegistro();
void imprimeRegistro();
void removeRegistro();
void removeIndex();
void salvaIndex();
void finalizaExecucao(FILE *);

int main(void) {
	FILE *df, *indexPrimario, *indexSecundario;
	int comando= 0, contadorDeRegistros = 0;
	tipoAluno *aluno = NULL;


	index_p* indexPrimario = carregaIndex(&contadorDeRegistros);
	index_s* indexSecundario = carregaIndexSecundario(&contadorDeRegistros);

	do {
	    df = fopen("alunos.dat", "r+");
	    if (df == NULL) criaArquivo(df);
	} while(df == NULL);


	do {
		printf("Operacoes:\n1 - Gravar\n2 - Pesquisar chave primaria\n3 - Pesquisar sobrenome\n4 - Remover\n0 - Finalizar\n\n");
		scanf("%d", &comando);
		switch (comando)	{
		case 1:
			// Gravar registro
			aluno = leituraDosDadosDoAluno();
			insereIndex(df, &indexPrimario, *aluno, &contadorDeRegistros);
			insereIndexSec(df, &indexSecundario, *aluno, contadorDeRegistros);
			insereRegistro(df, *aluno);
			break;
		case 2:
			// Pesquisar registro pela chave primaria
			break;
		case 3:
			// Pesquisar registro pelo sobrenome
			break;
		case 4:
			printf("Remoção:\n1 - Pelo NUSP\n2 - Pelo sobrenome\n\n");
			scanf("%d", &comando);
			if (comando == 1) {
				// remover pelo NUSP
			} else {
				// remover pelo sobrenome
			}
			break;
		case 0:
			// Finalizar registro
			break;
		default:
			printf("\n\nOperação invalida !!!\n\n");
			break;
		}

		/* Programa deve proceder de acordo com a operacao desejada */


	} while(comando > 0);


	finalizaExecucao(df);

return 0;

}

int quantidadeDeRegistrosNoArquivo(FILE *arq) {
	FILE *arq = fopen("index_prim.dat", "r+");
	if (arq == NULL) return 0;

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(index_p); // Pega quantos registros existem
	
	rewind(arq);
	return quantidadeDeRegistros;
}

void criaArquivo(FILE *df) {

    if (df== NULL) {
        df= fopen("alunos.dat", "w");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
    /* Não se esqueça de criar os demais arquivos */
    /* Caso os arquivos existam, abra os arquivos. Os índices devem ser carregados em RAM */
}

index_p* carregaIndex(int *contador) {
	/* Neste méetodo devem ser implementadas as operações de carregamento de índice */
	/* Voce pode subdividir em métodos específicos para cada índice */
	/* Lembre-se: no primeiro run do programa, todos os arquivos estão vazios. Nos proximos runs, deve ser feita a leitura e o carregamento do estado anterior */
	/* Os índices devem se manter consistentes ao longo das execuções */ 
	FILE *arq = fopen("index_prim.dat", "r+");
	if (arq == NULL) return (index_p*) calloc(1, sizeof(index_p));

	*contador = quantidadeDeRegistrosNoArquivo(arq); // Pega quantos registros existem; // Atualiza contador
	
	index_p *index = (index_p*) calloc((*contador), sizeof(index_p)); // Aloca memoria pra passar os indices pra RAM
	fread(index, sizeof(index_p), (*contador), arq); // Faz leitura dos indices

	fclose(arq);
	return index;
}

index_s* carregaIndexSecundario(int *contador) {
	FILE *arq = fopen("index_sec.dat", "r+");
	if (arq == NULL) return (index_s*) calloc(1, sizeof(index_s));

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(index_s); // Pega quantos registros existem
	rewind(arq);

	*contador = quantidadeDeRegistros;

	index_s *index = (index_s*) calloc(quantidadeDeRegistros, sizeof(index_s));
	fread(index, sizeof(index_s), quantidadeDeRegistros, arq);

	fclose(arq);
	return index;
}

void insereIndex(FILE *arq, index_p **index, tipoAluno aluno, int *contador) {
	/* Método para manipulação do index primário */
	/* Neste método devem sem implementadas as operações de inserção de um RRN no índice, que deve ser mantido ordenado */
	/* Neste caso, apenas as operações em tempo de execução (RAM) */
	(*index) = (index_p*) realloc((*index), (*contador+1)*sizeof(index_p));

	(*index)[(*contador)].chavePrimaria = aluno.numUSP;
	(*index)[(*contador)].pos = quantidadeDeRegistrosNoArquivo(arq);

	*contador += 1;
	qsort((*index), (*contador), sizeof(index_p), qsortComparar); // Ordena o vetor de index

}

int qsortComparar(const void *a, const void *b) {
	return ( (*(index_p*)a).chavePrimaria - (*(index_p*)b).chavePrimaria );
}

void ordenaIndex() {
	/* Método para manipulação do index primário */
	/* A cada operação de inserção ou remoção de um registro, o índice deve ser atualizado para se manter ordenado */
	/* Neste caso, apenas as operações em tempo de execução (RAM) */
}

void criaIndexSec() {
	/* Método para manipulação do index secundário */
	/* Cria uma estrutura semelhante a uma pilha */

}

void insereIndexSec(FILE *arq, index_s **index, tipoAluno aluno, int contador) {
	/* Método para manipulação do index secundário */
	/* Este método pode ser chamado repetidamente durante o carregamento de uma índice pré-carregado ou a cada inserção durante a execução do programa */
	(*index) = (index_s*) realloc((*index), contador*sizeof(index_s));

	strcpy((*index)[contador-1].sobrenome, aluno.sobrenome);
	(*index)[contador-1].pos = pesquisaIndex();// PESQUISA NO INDEX E RETORNA A POSICAO QUE TA NELA POR QUE PRECISA SER FRACAMENTE LIGADO

	qsort((*index), contador, sizeof(index_p), qsortCompararIndexSec);
}

int qsortCompararIndexSec(const void *a, const void *b) {
	// return ( (*(index_s*)a).chavePrimaria - (*(index_s*)b).chavePrimaria );;
	return strcmp((*(index_s*)a).sobrenome, (*(index_s*)b).sobrenome);
}

void removeIndexSec() {
	/* Método para manipulação do index secundário */
}

tipoAluno* leituraDosDadosDoAluno() {
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

	return &aluno;
}

void insereRegistro(FILE *arq, tipoAluno aluno) {
	/* Neste método devem sem implementadas as operações de inserção registro no arquivo, lembrando que o índice deve se manter consistente com o arquivo */
	fseek(arq, 0, SEEK_END);
	fwrite(&aluno, sizeof(tipoAluno), 1, arq);
	rewind(arq);
// 	if (0 > pesquisaIndex(*chave, index, counter)) { // pesquisa index retorna negativo se registro ja existir
// 		fwrite(&aluno, sizeof(tipoAluno), 1, arq);
// 		*chave = aluno.numUSP;

// 		fseek(arq, 0, SEEK_END);
// 		int final = (int) ftell(arq);
// 		rewind(arq);

// 		return ((final/sizeof(tipoAluno))-1); // Retorna posição que o aluno foi inserido
// 	} else {
// 		printf("Aluno já cadastrado !!!!\n");
// 		return -pesquisaIndex(*chave, index, counter); // Negativo pra demonstrar que ja foi inserido
// 	}
}

int pesquisaIndex() {
	/* Aqui a pesquisa deve ser feita pela chave primária no índice por meio de uma busca binária para, então, encontrado o RRN, dar um seek no arquivo para recuperar o registro*/
	return 0;
}

void pesquisaChaveSecundaria() {
	/* Dado um sobrenome (ou parte dele), este método deverá verificar o índice secundário e retornar referências aos registros que contém este sobrenome */

}

void removeIndex() {
	/* Neste método devem sem implementadas as operações de remoção de um RRN no índice, que deve ser mantido ordenado */
	/* Neste caso, apenas as operações em tempo de execução (RAM) */
}


/* demais metodos a serem implementados */

void removeRegistro() {
	/* Pode ser implementada apenas uma remoção lógica */

}

void salvaIndex() {
	/* Antes do programa ser finalizar, o estado final dos índices deve ser gravado em arquivo */

}

void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */

}