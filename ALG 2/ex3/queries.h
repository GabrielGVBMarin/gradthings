/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 3 - Índices Secundários */
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define TAM 16

#define SUCCESS 0
#define INVALID_POS -1
#define INVALID_KEY -2
#define INVALID_NAME -3

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int tipoChave;
// Chave primaria é o número USP
typedef struct {
	int chavePrimaria;
	int pos;
} index_p;

// Chave secundária é o sobrenome do aluno
typedef struct {
	char sobrenome[TAM];
	int pos;
} index_s;

typedef struct {
    int NUSP;
    int posDoProximo;
} listaInvertidaElem;

typedef struct {
	tipoChave numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} tipoAluno;

void criaArquivo(FILE*);
index_p* carregaIndex(int*);
void insereIndex(FILE*, index_p**, tipoAluno, int*);
int qsortComparar(const void*, const void*);
index_s* carregaIndexSecundario(int*);
void insereIndexSec(FILE*, index_s**, listaInvertidaElem**, tipoAluno, int, int*);
tipoAluno* leituraDosDadosDoAluno();
void insereRegistro(FILE*, tipoAluno);
int pesquisaIndex(index_p*, int, int);
int pesquisaChaveSecundaria(index_s*, char*, int*);
tipoAluno* pesquisaRegistro(FILE*, int);
void imprimeRegistro();
void removeRegistro(index_p**, index_s**, int, int*, int*);
void removeArquivo(index_p**, int, int*);
void removeIndexSecundario(index_s**, int, int*);
void finalizaExecucao(FILE*);
int qsortCompararIndexSec(const void *, const void *);
tipoChave* pesquisaListaInvertida(listaInvertidaElem*, int, int, int*);
int insereListaInvertida(int, int, int);
listaInvertidaElem* leituraDaListaInvertida();
void dumpFile(FILE*);
void dumpIndexPrimario(index_p*, int);
void dumpArquivoIndexPrimario();
void dumpListaInvertida();
void dumpListaSecundaria(index_s*, int);
void dumpArquivoListaSecundaria();
void escreveIndexPrimario(index_p*, int);
void escreveIndexSecundario(index_s*, int);

#endif