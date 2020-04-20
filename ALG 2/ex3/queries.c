/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 3 - Índices Secundários */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include "queries.h"



int quantidadeDeRegistrosNoIndexPrimario(FILE *arq) {

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(index_p);
	
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
	FILE *arq = fopen("index_primario.dat", "r+");
	if (arq == NULL) return (index_p*) calloc(1, sizeof(index_p));

	*contador = quantidadeDeRegistrosNoIndexPrimario(arq); // Atualiza contador pegando quantos registros existem
	
	index_p *index = (index_p*) calloc((*contador), sizeof(index_p));
	fread(index, sizeof(index_p), (*contador), arq);

	fclose(arq);
	return index; // Retorna o index primario
}

index_s* carregaIndexSecundario(int *contador) {
	FILE *arq = fopen("index_secundario.dat", "r+");
	if (arq == NULL) return (index_s*) calloc(1, sizeof(index_s));

	fseek(arq, 0, SEEK_END);
	int quantidadeDeRegistros = ((int) ftell(arq))/sizeof(index_s); // Pega quantos registros existem
	rewind(arq);

	*contador = quantidadeDeRegistros;

	index_s *index = (index_s*) calloc(quantidadeDeRegistros, sizeof(index_s));
	fread(index, sizeof(index_s), quantidadeDeRegistros, arq);

	fclose(arq);
	return index; // Retorna index secundario
}

// PAREI AQUI OS COMENTÁRIO
void insereIndex(FILE *arq, index_p **index, tipoAluno aluno, int *contador) {
	(*index) = (index_p*) realloc((*index), (*contador+1)*sizeof(index_p));

	(*index)[(*contador)].chavePrimaria = aluno.numUSP;
	(*index)[(*contador)].pos = *contador;// quantidadeDeRegistrosNoArquivo(arq);

	*contador += 1;
	qsort((*index), (*contador), sizeof(index_p), qsortComparar); // Ordena o vetor de index

}

int qsortComparar(const void *a, const void *b) {
	return ( (*(index_p*)a).chavePrimaria - (*(index_p*)b).chavePrimaria );
}

void insereIndexSec(FILE *arq, index_s **index, listaInvertidaElem **listaInvertida, tipoAluno aluno, int contador,
						int *contadorIndexSecundario) {
	int posAux = pesquisaChaveSecundaria((*index), aluno.sobrenome, &(*contadorIndexSecundario));
	if (posAux == -1) {

		*contadorIndexSecundario += 1;
		(*index) = (index_s*) realloc((*index), (*contadorIndexSecundario)*sizeof(index_s));
		(*index)[*contadorIndexSecundario-1].pos = insereListaInvertida(aluno.numUSP, posAux, (contador-1));
		strcpy((*index)[*contadorIndexSecundario-1].sobrenome, aluno.sobrenome);

		qsort((*index), *contadorIndexSecundario, sizeof(index_s), qsortCompararIndexSec);
	} else {
		insereListaInvertida(aluno.numUSP, posAux, (contador-1));
	}


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
        return INVALID_POS;
    }

    int i = 0;
	int f = contador;
	int meio;

	// *** Busca binaria ***
	while (i <= f) {
		meio = (i + f)/2;
 		if (indexPrimario[meio].chavePrimaria == nusp) {
			return (indexPrimario[meio].pos)*sizeof(tipoAluno);
		}
		else if (nusp > indexPrimario[meio].chavePrimaria) i = meio+1;
		else f = meio-1;
	}
	return INVALID_POS; // Se n encontrar retorna invalido
}

int pesquisaChaveSecundaria(index_s *index, char *sobrenome, int *contadorIndexSecundario) {
	/* Dado um sobrenome (ou parte dele), este método deverá verificar o índice secundário e retornar referências aos registros que contém este sobrenome */
    // Retornar -1 se não tiver retornar o valor da pos daquela egiao

    int tamanho = *contadorIndexSecundario; // talvez
    int i;

    for (i = 0; i < tamanho; i++) {
        if (strstr(index[i].sobrenome, sobrenome) != NULL) {
			return (index[i].pos);
		}
    }
    return -1; // retorna menos 1 se não existir
}

listaInvertidaElem* leituraDaListaInvertida() {

    FILE *arq = fopen("lista_invertida.dat", "r+");
    if (arq == NULL) {
		printf("\n\n***Lista invertida não existe para leitura***\n\n");
		return NULL;
	}

    fseek(arq, 0, SEEK_END);
    int contador = ((int) ftell(arq))/sizeof(listaInvertidaElem);
    rewind(arq);

    listaInvertidaElem *listaInvertida = (listaInvertidaElem*) calloc(contador, sizeof(listaInvertidaElem));
    fread(listaInvertida, sizeof(listaInvertidaElem), contador, arq);

    fclose(arq);
    return listaInvertida;
}

int insereListaInvertida(int nusp, int pos, int tamanhoDaLista) {
    listaInvertidaElem *lista = leituraDaListaInvertida();
    FILE *arq = fopen("lista_invertida.dat", "w+");
    int auxPos = pos;
	lista = (listaInvertidaElem*) realloc(lista, (tamanhoDaLista+1)*sizeof(listaInvertidaElem));

	lista[tamanhoDaLista].NUSP = nusp;
	lista[tamanhoDaLista].posDoProximo = -1;

    if (pos != -1) { // Se já existir um com o mesmo sobrenome, atualizar o a posicao do proximo do ultimo e registrar
        while (lista[auxPos].posDoProximo != -1) auxPos = lista[auxPos].posDoProximo;
        lista[auxPos].posDoProximo = tamanhoDaLista;
    }

	fwrite(lista, sizeof(listaInvertidaElem), tamanhoDaLista+1, arq);
	fclose(arq);
	free(lista);
    return tamanhoDaLista;
}

tipoChave* pesquisaListaInvertida(listaInvertidaElem *listaInvertida, int pos, int tamanhoDaLista, int *contadorDeTamanho) { // Retorna a posição do sobrenome
	listaInvertida = leituraDaListaInvertida();
    if (tamanhoDaLista < pos) return NULL;

    int contador = 0;
    tipoChave *listaDeChaves = (tipoChave*) calloc(1, sizeof(tipoChave));


    do {
        listaDeChaves[contador] = listaInvertida[pos].NUSP;
        contador++;
        listaDeChaves = (tipoChave*) realloc(listaDeChaves, contador+1);
        pos = listaInvertida[pos].posDoProximo;

    } while(pos != -1 && pos != -2);

	if (pos == -2) printf("Esse cadastro foi deletado !!!\n");

	*contadorDeTamanho = contador;

    return listaDeChaves;
}

tipoAluno* pesquisaRegistro(FILE *arq, int pos) {
    if (pos == -1) return NULL;
	tipoAluno *aluno = (tipoAluno*) calloc(1, sizeof(tipoAluno));

	fseek(arq, pos, SEEK_SET); // mudei de sizeof(tipoAluno)*pos para só pos

	fread(aluno, sizeof(tipoAluno), 1, arq);

	rewind(arq);
	return aluno;
}

void removeRegistro(index_p **indexPrimario, index_s **indexSecundario, int nusp, int *contadorIndexPrimario,
						int *contadorIndexSecundario) {
	/* Pode ser implementada apenas uma remoção lógica */
	int posEmBytesNoArquivo = pesquisaIndex((*indexPrimario), nusp, *contadorIndexPrimario);

	if (posEmBytesNoArquivo == -1) {
		printf("Aluno não encontrado no index primário !!!\n");
	} else {
		removeArquivo(indexPrimario, posEmBytesNoArquivo, contadorIndexPrimario);
		removeIndexSecundario(indexSecundario, posEmBytesNoArquivo, contadorIndexSecundario);
	}

}

void removeArquivo(index_p **index, int posEmBytesNoArquivo, int *contador) {

	tipoAluno aluno;

	FILE *arq = fopen("alunos.dat", "r+");
	if (!arq) printf("O arquivo não tem registros para remover !!!\n");
	else {
		fseek(arq, posEmBytesNoArquivo, SEEK_SET);
		fread(&aluno, sizeof(tipoAluno), 1, arq);

		aluno.nota = -1;

		fseek(arq, posEmBytesNoArquivo, SEEK_SET);
		fwrite(&aluno, sizeof(tipoAluno), 1, arq);
	}
	fclose(arq);

}

void removeIndexSecundario(index_s **index, int posEmBytesNoArquivo, int *contador) {

	listaInvertidaElem *listaInvertida = leituraDaListaInvertida();
	tipoAluno aluno;
	listaInvertidaElem alunoNaListaInvertida, alunoAnterior;
	int posAux = 0, posDoUltimoEncontrado = 0, temp = 0;

	FILE *arqListaInvertida = fopen("lista_invertida.dat", "r+");
	FILE *arq = fopen("alunos.dat", "r+");

	if (arq) {
		fseek(arq, posEmBytesNoArquivo, SEEK_SET);
		fread(&aluno, sizeof(tipoAluno), 1, arq);

		posAux = pesquisaChaveSecundaria((*index), aluno.sobrenome, contador);
		if (posAux == -1) {
			printf("Erro, aluno procurado não encontrado nas chaves secundárias !!!\n");
		} else {

			if (!arqListaInvertida) printf("Lista invertida não existe !!!"); // verifica se o arquivo existe
			else {
				fseek(arqListaInvertida, posAux*sizeof(listaInvertidaElem), SEEK_SET);
				fread(&alunoNaListaInvertida, sizeof(listaInvertidaElem), 1, arqListaInvertida);

				temp = posAux;
				while (alunoNaListaInvertida.NUSP != aluno.numUSP && alunoNaListaInvertida.posDoProximo != -1) {
					posDoUltimoEncontrado = temp;
					temp = alunoNaListaInvertida.posDoProximo;
					fseek(arqListaInvertida, alunoNaListaInvertida.posDoProximo*sizeof(listaInvertidaElem), SEEK_SET);
					fread(&alunoNaListaInvertida, sizeof(listaInvertidaElem), 1, arqListaInvertida);
					
				}

				if (alunoNaListaInvertida.NUSP == aluno.numUSP) { // achou o que queriamos
					fseek(arqListaInvertida, posDoUltimoEncontrado*sizeof(listaInvertidaElem), SEEK_SET);
					fread(&alunoAnterior, sizeof(listaInvertidaElem), 1, arqListaInvertida);

					if (alunoNaListaInvertida.posDoProximo != -1) 
						alunoAnterior.posDoProximo = alunoNaListaInvertida.posDoProximo; // Marca o proximo no anterior
					else alunoAnterior.posDoProximo = -1; // Marca que não tem próximo

					fseek(arqListaInvertida, posDoUltimoEncontrado*sizeof(listaInvertidaElem), SEEK_SET);
					fwrite(&alunoAnterior, sizeof(listaInvertidaElem), 1, arqListaInvertida);

					alunoNaListaInvertida.posDoProximo = -2; // -2 significara que o usuário foi deletado;

					fseek(arqListaInvertida, temp*sizeof(listaInvertidaElem), SEEK_SET);
					fwrite(&alunoNaListaInvertida, sizeof(listaInvertidaElem), 1, arqListaInvertida); // Sobreescreve deletado

				} else { // Não encontrou e não tem mais nenhum na lista invertida !!!
					printf("Erro, aluno procurado não encontrado na lista invertida !!!\n");
				}
			}
		}

	}

	free(listaInvertida);
	fclose(arq);
	fclose(arqListaInvertida);

}

void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
	fclose(df);
	printf("\n\n*** Programa finalizado ***\n\n");

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
	if (!arq) printf("\n\n***Lista invertida não criada para dump***\n\n");
	else {
		while(fread(&elem, sizeof(listaInvertidaElem), 1, arq)) {
			printf("NUSP: %d\n", elem.NUSP);
			printf("POS DO PROXIMO: %d\n", elem.posDoProximo);
		}
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

void dumpListaSecundaria(index_s *index, int contador) {
	printf("\n\n");
	printf("TAMANHO INDEX SECUNDARIO: %d\n", contador);
	for (int i = 0; i < contador; i++) {
		printf("CHAVE DA LISTA INVERTIDA: %s\n", index[i].sobrenome);
		printf("POSICAO NA LISTA INVERTIDA: %d\n", index[i].pos);
	}
}

void dumpArquivoListaSecundaria() {
	FILE *arq = fopen("index_secundario.dat", "r+");
	index_s index;
	printf("\n\n");
	while(fread(&index, sizeof(index_s), 1, arq)) {
		printf("CHAVE PRIMARIA: %s\n", index.sobrenome);
		printf("POSICAO NA LISTA INVERTIDA: %d\n", index.pos);
	}
	fclose(arq);
}

void escreveIndexPrimario(index_p *indexPrimario, int contador) {
	FILE *arq = fopen("index_primario.dat", "w");
	fwrite(indexPrimario, sizeof(index_p), contador, arq);
	fclose(arq);
}

void escreveIndexSecundario(index_s *indexSecundario, int contador) {
	FILE *arq = fopen("index_secundario.dat", "w");
	fwrite(indexSecundario, sizeof(index_s), contador, arq);
	fclose(arq);
}