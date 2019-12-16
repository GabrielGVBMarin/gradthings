// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto  {
  float x,y;
  int guide;
  int ligadoCounter, ligadoVermelhoCounter;
  int *ligado;
  int *ligadoVermelho;
  int cor; // 1 vermelho / 2 verde / 0 nada
};
typedef struct ponto PONTO;

struct mapa {
  struct ponto *pontos;
  int pontosCounter, ligamentosCounter, camarasCounter, whereami;
};
typedef struct mapa MAPA;

struct caminhoEncontrado  {
  int pontosPassados;
  int *vetor;
  int caminhosPegados;
  double distancia;
  struct caminhoEncontrado *next;
};
typedef struct caminhoEncontrado CAMINHO_ENCONTRADO;

struct headerCaminhos {
  struct caminhoEncontrado *first;
  struct caminhoEncontrado *last;
  int caminhosAchados;
};
typedef struct headerCaminhos HEADER_CAMINHOS;

MAPA* fazLeitura();
void addCaminho(HEADER_CAMINHOS*, int*, int);
HEADER_CAMINHOS* identificaCaminhos(MAPA*);
HEADER_CAMINHOS* filtradorDeCaminhos(MAPA*, HEADER_CAMINHOS*);
int calculaDistancia(MAPA*, CAMINHO_ENCONTRADO*);
int existeNoVetor(int*, int, int);
void ordenaCaminhos(MAPA*, HEADER_CAMINHOS**);
void printCaminhos(MAPA*, HEADER_CAMINHOS*);
void freeAll(MAPA*, HEADER_CAMINHOS*);

#endif
