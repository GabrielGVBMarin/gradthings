/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 3 - Índices Secundários */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include "queries.h"

// inserir registros, pesquisar e apresentar registros, remover registros
// Registro : : número USP, nome, sobrenome, curso e nota


int quantidadeDeRegistrosNoArquivo(FILE *arq) {
	// FILE *arq = fopen("index_prim.dat", "r+");
	// if (arq == NULL) return 0;

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(tipoAluno);
	
	rewind(arq);
	return quantidadeDeRegistros;
}

void criaArquivo(FILE *df) {
    if (df== NULL) {
        df= fopen("alunos.dat", "w");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
}

index_p* carregaIndex(int *contador) {
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
	(*index) = (index_p*) realloc((*index), (*contador+1)*sizeof(index_p));

	(*index)[(*contador)].chavePrimaria = aluno.numUSP;
	(*index)[(*contador)].pos = *contador;// quantidadeDeRegistrosNoArquivo(arq);

	printf("INSERE INDEX CHAVE PRIMARIA : %d\n", (*index)[(*contador)].chavePrimaria);
	printf("INSEREINDEX POSICAO NO ARQUIVO : %d\n", (*index)[(*contador)].pos);

	if (*contador == 1) {

	printf("INSERE INDEX CHAVE PRIMARIA : %d\n", (*index)[(*contador-1)].chavePrimaria);
	printf("INSEREINDEX POSICAO NO ARQUIVO : %d\n", (*index)[(*contador-1)].pos);
	}


	*contador += 1;
	qsort((*index), (*contador), sizeof(index_p), qsortComparar); // Ordena o vetor de index

}

int qsortComparar(const void *a, const void *b) {
	return ( (*(index_p*)a).chavePrimaria - (*(index_p*)b).chavePrimaria );
}

void insereIndexSec(FILE *arq, index_s **index, listaInvertidaElem **listaInvertida, tipoAluno aluno, int contador) {
	(*index) = (index_s*) realloc((*index), contador*sizeof(index_s));  // ISSO NEM SEMPRE ACONTECE NO INDEX SECUNDARIO
																		// PODEM TER ELEMENTOS IGUAL E NÃO ADICIONA OUTRO

    printf("CHEGOU INSERE INDEX SEC\n");
	(*index)[contador-1].pos = insereListaInvertida(aluno.numUSP, pesquisaChaveSecundaria((*index), aluno.sobrenome), (contador-1));
	strcpy((*index)[contador-1].sobrenome, aluno.sobrenome);
    printf("FINALISOU INDEX SEC\n");

	qsort((*index), contador, sizeof(index_p), qsortCompararIndexSec);

}

int qsortCompararIndexSec(const void *a, const void *b) {
	// return ( (*(index_s*)a).chavePrimaria - (*(index_s*)b).chavePrimaria );;
	return strcmp((*(index_s*)a).sobrenome, (*(index_s*)b).sobrenome);
}

tipoAluno* leituraDosDadosDoAluno() {
	tipoAluno *aluno = (tipoAluno*) calloc(1, sizeof(tipoAluno));

	printf("\nNUSP : ");
	scanf("%d", &aluno->numUSP);
	printf("\nPrimeiro nome : ");
	scanf("%s", aluno->nome);
	printf("\nSobrenome : ");
	scanf("\n%[^\n]s", aluno->sobrenome);
	printf("\nAbreviacao do curso (BCC, BSI, ESTAT...) : ");
	scanf("%s", aluno->curso);
	printf("\nNota : ");
	scanf("%f", &aluno->nota);

	return aluno;
}

void insereRegistro(FILE *arq, tipoAluno aluno) {
	fseek(arq, 0, SEEK_END);
	fwrite(&aluno, sizeof(tipoAluno), 1, arq);
	rewind(arq);
}

int pesquisaIndex(index_p *indexPrimario, int nusp, int contador) {
	/* Aqui a pesquisa deve ser feita pela chave primária no índice por meio de uma busca binária para, então, encontrado o RRN, dar um seek no arquivo para recuperar o registro*/
	if (nusp < 0) {
        printf("\nNUSP INVALIDO !!!\n");
        return INVALID_POS;
    }

    int i = 0;
	int f = contador;
	printf("TAMANHO DO INDEX PRIMARIO : %d", f);
	int meio;

	// *** Busca binaria ***
	while (i <= f) {
		meio = (i + f)/2;
 		if (indexPrimario[meio].chavePrimaria == nusp) {
			printf("POSICAO NO ARQUIVO : %lu\n", (indexPrimario[meio].pos)*sizeof(tipoAluno));
			return (indexPrimario[meio].pos)*sizeof(tipoAluno);
		}
		else if (nusp > indexPrimario[meio].chavePrimaria) i = meio+1;
		else f = meio-1;
	}
	return INVALID_POS; // Se n encontrar retorna invalido
}

int pesquisaChaveSecundaria(index_s *index, char *sobrenome) {
	/* Dado um sobrenome (ou parte dele), este método deverá verificar o índice secundário e retornar referências aos registros que contém este sobrenome */
    // Retornar -1 se não tiver retornar o valor da pos daquela egiao

	printf("COMEÇO PESQUISA CHAVE SECUNDARIA\n");
    int tamanho = (sizeof(*index)/sizeof(index_s)); // talvez
	printf("TAMANHO DO INDEX SECUNDARIO : %d\n", tamanho);
    int i;

    for (i = 0; i < tamanho; i++) {
		printf("NOME DO INDEX: %s\n", index[i].sobrenome);
		printf("NOME PROCURADO: %s\n", sobrenome);
        if (strstr(index[i].sobrenome, sobrenome) != NULL) {
			printf("STRING : %s\n", strstr(index[i].sobrenome, sobrenome));
			printf("FINAL PESQUISA CHAVE SECUNDARIA: %d\n", index[i].pos);
			return (index[i].pos-1);
		}
    }
	printf("FINAL PESQUISA CHAVE SECUNDARIA\n");
    return -1;
}

listaInvertidaElem* leituraDaListaInvertida() {

    FILE *arq = fopen("lista_invertida.dat", "r+");
    if (arq == NULL) return NULL;

    fseek(arq, 0, SEEK_END);
    int contador = ((int) ftell(arq))/sizeof(listaInvertidaElem);
    rewind(arq);

    listaInvertidaElem *listaInvertida = (listaInvertidaElem*) calloc(contador, sizeof(listaInvertidaElem));
    fread(listaInvertida, sizeof(listaInvertidaElem), contador, arq);

    fclose(arq);
    return listaInvertida;
}

int insereListaInvertida(int nusp, int pos, int tamanhoDaLista) { // retorna a posição que foi inserido se já tiver algo retorna 0
	printf("\n\nCOMEÇO INSERE LISTA INVERTIDA\n");

    listaInvertidaElem *lista = leituraDaListaInvertida();
	printf("DEPOIS DA LEITURA DA LISTA\n");
    FILE *arq = fopen("lista_invertida.dat", "a+");
    int auxPos = pos;
	printf("TAMANHO DA LISTA INVERTIDA : %d\n", tamanhoDaLista);
	lista = (listaInvertidaElem*) realloc(lista, tamanhoDaLista+1);

	lista[tamanhoDaLista].NUSP = nusp;
	lista[tamanhoDaLista].posDoProximo = -1;

	printf("POS : %d\n", pos);
	printf("NUSP : %d\nPOS DO PROXIMO: %d\n", lista[pos].NUSP, lista[pos].posDoProximo);

    if (pos != -1) { // Se já existir um com o mesmo sobrenome, atualizar o a posicao do proximo do ultimo e registrar
        while (lista[auxPos].posDoProximo != -1) auxPos = lista[auxPos].posDoProximo;
        lista[auxPos].posDoProximo = sizeof(*lista)/sizeof(listaInvertidaElem);
    }

	printf("DEPOIS DO WHILE PERCORRENDO\n");

	fseek(arq, 0, SEEK_END);
    fwrite(&lista[tamanhoDaLista], sizeof(listaInvertidaElem), 1, arq);
	printf("FINAL INSERE LISTA INVERTIDA\n\n");
	fclose(arq);
    return tamanhoDaLista;
}

tipoChave* pesquisaListaInvertida(listaInvertidaElem *listaInvertida, int pos, int tamanhoDaLista) { // Retorna a posição do sobrenome
	printf("CHEGOU PESQUISA LISTA INVERTIDA\n");
	printf("TAMANHO DA LISTA INVERTIDA : %d\n", tamanhoDaLista);
	listaInvertida = leituraDaListaInvertida();
    if (tamanhoDaLista < pos) return NULL;

    int contador = 0;
    tipoChave *listaDeChaves = (tipoChave*) calloc(1, sizeof(tipoChave));

	printf("ANTES DO DO WHILE\n");

    do {
		printf("POS QUE PEGA: %d\n", pos);
        listaDeChaves[contador] = listaInvertida[pos].NUSP;
		printf("NUSP: %d\n", listaInvertida[pos].NUSP);
		printf("POS DO PROXIMO: %d\n", listaInvertida[pos].posDoProximo);
        contador++;
        listaDeChaves = (tipoChave*) realloc(listaDeChaves, contador+1);
        pos = listaInvertida[pos].posDoProximo;

    } while(pos != -1);
    printf("ACABOU A PESQUISA LISTA INVERTIDA\n");

    return listaDeChaves;
}

void criaListaInvertida() {
    FILE *arq = fopen("lista_invertida.dat", "w+");

    fseek(arq, 0, SEEK_END);
    int contador = ((int) ftell(arq))/sizeof(listaInvertidaElem);

	fwrite(index, sizeof(listaInvertidaElem), contador, arq);
}

tipoAluno* pesquisaRegistro(FILE *arq, int pos) {
	printf("PESQUISA REGISTRO POS : %d\n", pos);
    if (pos == -1) return NULL;
	tipoAluno *aluno = (tipoAluno*) calloc(1, sizeof(tipoAluno));

	fseek(arq, pos, SEEK_SET); // mudei de sizeof(tipoAluno)*pos para só pos

	fread(aluno, sizeof(tipoAluno), 1, arq);

	rewind(arq);
	return aluno;
}

void removeRegistro(index_p *index, int nusp, int contador) {
	/* Pode ser implementada apenas uma remoção lógica */
	int pos = pesquisaIndex(index, nusp, contador);
	FILE *arq = fopen("alunos.dat", "w+");

	fseek(arq, pos, SEEK_SET);
	tipoAluno aluno;
	fread(&aluno, sizeof(tipoAluno), 1, arq);
	aluno.numUSP *= -1;

	fseek(arq, pos, SEEK_SET);
	fwrite(&aluno, sizeof(tipoAluno), 1, arq);
}

void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(df);

}

void dumpFile(FILE *arq) {
	rewind(arq);
	tipoAluno aluno;
	while(fread(&aluno, sizeof(tipoAluno), 1, arq)) {
		printf("\n\nPRINTANDO ALUNO\n\n");
		printf("NOME: %s\n", aluno.nome);
		printf("SOBRENOME: %s\n", aluno.sobrenome);
		printf("NUSP: %d\n", aluno.numUSP);
		printf("CURSO: %s\n", aluno.curso);
		printf("NOTA: %f\n", aluno.nota);
	};
	rewind(arq);
}

void dumpIndexPrimario(index_p *index, int contador) {
	printf("\n\n");
	printf("TAMANHO INDEX: %d\n", contador);
	for (int i = 0; i < contador; i++) {
		printf("CHAVE PRIMARIA: %d\n", index[i].chavePrimaria);
		printf("POSICAO NO ARQUIVO: %d\n", index[i].pos);
	}
}

void dumpListaInvertida() {
	FILE *arq = fopen("lista_invertida.dat", "r+");
	listaInvertidaElem elem;
	printf("\n\n");
	while(fread(&elem, sizeof(listaInvertidaElem), 1, arq)) {
		printf("NUSP: %d\n", elem.NUSP);
		printf("POS DO PROXIMO: %d\n", elem.posDoProximo);
	}
	fclose(arq);
}

void dumpArquivoIndexPrimario() {
	FILE *arq = fopen("index_primario.dat", "r+");
	index_p index;
	printf("\n\n");
	while(fread(&index, sizeof(index_p), 1, arq)) {
		printf("CHAVE PRIMARIA: %d\n", index.chavePrimaria);
		printf("POSICAO NO ARQUIVO BRUTO: %d\n", index.pos);
	}
	fclose(arq);
}

void escreveIndexPrimario(index_p *indexPrimario) {
	// int tamanho = sizeof(*indexPrimario)/sizeof()
}

void escreveIndexSecundario() {

}

void escreveListaInvertida() {

}

void escreveArquivo() {

}