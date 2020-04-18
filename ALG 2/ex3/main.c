/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 3 - Índices Secundários */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include "queries.h"

// VERIFICAÇÕES SE JÁ EXISTE
// VERIFICAÇÕES SE É VÁLIDO
// VERIFICAÇÕES SE FOI REMOVIDO


int main(void) {
	FILE *df;
	int comando= 0, contadorDeRegistros = 0, auxiliar = 0;
	tipoAluno *aluno = NULL;


	index_p *indexPrimario = carregaIndex(&contadorDeRegistros);
	index_s *indexSecundario = carregaIndexSecundario(&contadorDeRegistros);

	tipoChave *aux = NULL;

	listaInvertidaElem *listaInvertida = leituraDaListaInvertida();

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
			printf("COMECO DE TUDO\n");
			insereIndex(df, &indexPrimario, *aluno, &contadorDeRegistros);
			printf("ANTES DO INSERE INDEX SEC\n");
			insereIndexSec(df, &indexSecundario, &listaInvertida, *aluno, contadorDeRegistros);
			printf("ANTES INSERE REGISTRO\n");
			insereRegistro(df, *aluno);
			printf("Aluno inserido !!!\n");
			// dumpFile(df);
			// dumpIndexPrimario(indexPrimario, contadorDeRegistros);
			break;
		case 2:
			printf("\nInsira o NUSP : ");
			scanf("%d", &aluno->numUSP);
			aluno = pesquisaRegistro(df, pesquisaIndex(indexPrimario, aluno->numUSP, contadorDeRegistros));
			if (!aluno) printf("NUSP não encontrado !!!\n");
			else {
				printf("NUSP : %d\n", aluno->numUSP);
				printf("Primeiro nome : %s\n", aluno->nome);
				printf("Sobrenome : %s\n", aluno->sobrenome);
				printf("Abreviacao do curso (BCC, BSI, ESTAT...) : %s\n", aluno->curso);
				printf("Nota : %d\n", aluno->numUSP);
			}
			break;
		case 3:
			// Pesquisar registro pelo sobrenome
			printf("\nInsira o sobrenome : ");
			scanf("%[^\n]s", aluno->sobrenome);
			aux = pesquisaListaInvertida(listaInvertida, pesquisaChaveSecundaria(indexSecundario, aluno->sobrenome));
			auxiliar = sizeof(aux)/sizeof(listaInvertidaElem);
			printf("TAMANHO DA LISTA INVERTIDA : %d\n", auxiliar);
			for (int i = 0; i < auxiliar; i++) {
				printf("NUSP ENCONTRADO : %d\n", aux[i]);
			}
			break;
		case 4:
			printf("Remoção:\n1 - Pelo NUSP\n2 - Pelo sobrenome\n\n");
			scanf("%d", &comando);
			if (comando == 1) {
				// remover pelo NUSP
				printf("\nInsira o NUSP : ");
				scanf("%d", &aluno->numUSP);
				removeRegistro(indexPrimario, aluno->numUSP, contadorDeRegistros);
				printf("Removido !!!\n");

			} else if (comando == 2) {
				// remover pelo sobrenome
				printf("\nInsira o sobrenome : ");
				scanf("%[^\n]s", aluno->sobrenome);
				aux = pesquisaListaInvertida(listaInvertida, pesquisaChaveSecundaria(indexSecundario, aluno->sobrenome));
				auxiliar = sizeof(aux)/sizeof(listaInvertidaElem);
				printf("TAMANHO DA LISTA INVERTIDA : %d\n", auxiliar);
				for (int i = 0; i < auxiliar; i++) {
					printf("NUSP ENCONTRADO : %d\n", aux[i]);
				}
				printf("Digite o NUSP que deseje remover : ");
				scanf("%d", aluno->numUSP);
				removeRegistro(indexPrimario, aluno->numUSP, contadorDeRegistros);
				printf("Removido !!!\n");
				} else {
					printf("Operação inválida !!!\n\n");
				}
			break;
		case 0:
			// Escreve dados

			// Finalizar registro
			if (aluno) free(aluno);
			if (indexPrimario) free(indexPrimario);
			if (indexSecundario) free(indexSecundario);
			if (aux) free(aux);
			if (listaInvertida) free(listaInvertida);
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