// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <biblio.h>

// LE A ENTRADA ALOCANDO DINAMICAMENTE
MAPA* fazLeitura()  {

  int i, aux, segundaAux;
  MAPA *new = (MAPA*) calloc(1, sizeof(MAPA));

  scanf("%d", &new->pontosCounter);
  new->pontos = (PONTO*) calloc(new->pontosCounter, sizeof(PONTO));
  for (i = 0; i < new->pontosCounter; i++)  {
    scanf("%f %f", &new->pontos[i].x, &new->pontos[i].y);
  }

  scanf("%d", &new->camarasCounter);
  for (i = 0; i < new->camarasCounter; i++) {
    scanf("%d", &aux);
    scanf("%d", &new->pontos[aux-1].cor);
    new->pontos[aux-1].cor++;
  }

  scanf("%d", &new->ligamentosCounter);
  for (i = 0; i < new->ligamentosCounter; i++)  {

    scanf("%d %d", &aux, &segundaAux);
    aux--;
    if (segundaAux > 0) {
      segundaAux--;
      new->pontos[aux].ligadoCounter++;
      new->pontos[aux].ligado = (int*) realloc(new->pontos[aux].ligado, new->pontos[aux].ligadoCounter*sizeof(int));
      new->pontos[aux].ligado[new->pontos[aux].ligadoCounter-1] = segundaAux;

      new->pontos[segundaAux].ligadoCounter++;
      new->pontos[segundaAux].ligado = (int*) realloc(new->pontos[segundaAux].ligado, new->pontos[segundaAux].ligadoCounter*sizeof(int));
      new->pontos[segundaAux].ligado[new->pontos[segundaAux].ligadoCounter-1] = aux;
    } else  {
      segundaAux++;
      new->pontos[aux].ligadoVermelhoCounter++;
      new->pontos[aux].ligadoVermelho = (int*) realloc(new->pontos[aux].ligadoVermelho, new->pontos[aux].ligadoVermelhoCounter*sizeof(int));
      new->pontos[aux].ligadoVermelho[new->pontos[aux].ligadoVermelhoCounter-1] = segundaAux;

    }

  }
  scanf("%d", &new->whereami);
  new->whereami--;

  return new;

}

// ADICIONA UM NOVO CAMINHO NO HEADER DE CAMINHOS
void addCaminho(HEADER_CAMINHOS *header, int *caminhos, int camCounter) {

  int i;

  if (header->first == NULL)  {
    CAMINHO_ENCONTRADO *encontrado = (CAMINHO_ENCONTRADO*) calloc(1, sizeof(CAMINHO_ENCONTRADO));
    encontrado->vetor = (int*) malloc(camCounter*sizeof(int));
    encontrado->caminhosPegados = camCounter-1;

    for (i = 0; i < camCounter; i++)  {
      encontrado->vetor[i] = caminhos[i];
    }

    header->last = header->first = encontrado;
    header->caminhosAchados++;

  } else  {
    CAMINHO_ENCONTRADO *found = (CAMINHO_ENCONTRADO*) calloc(1, sizeof(CAMINHO_ENCONTRADO));

    if (camCounter) {
      found->vetor = (int*) malloc(camCounter*sizeof(int));
      found->caminhosPegados = camCounter-1;

      for (i = 0; i < camCounter; i++)  {
        found->vetor[i] = caminhos[i];
      }

    } else {
      found->vetor = (int*) malloc(1*sizeof(int));
      found->caminhosPegados = 0;
      found->vetor[0] = caminhos[0];
    }

    header->last->next = found;
    header->last = found;
    header->caminhosAchados++;
  }

}

// PEGA O MAPA E IDENTIFICA *TODOS* OS CAMINHOS EXISTENTES (LITERALMENTE)
HEADER_CAMINHOS* identificaCaminhos(MAPA *mapa)  {

  PONTO *pontos = mapa->pontos;
  int *caminho = NULL;
  int i = mapa->whereami, camCounter = 0;
  HEADER_CAMINHOS *resultado = (HEADER_CAMINHOS*) calloc(1, sizeof(HEADER_CAMINHOS));

  while (pontos[i].guide != pontos[i].ligadoCounter+1)  {

      caminho = (int*) realloc(caminho, (camCounter+1)*sizeof(int));
      caminho[camCounter] = i;

      if (pontos[i].guide < pontos[i].ligadoCounter && !existeNoVetor(caminho, pontos[i].ligado[pontos[i].guide], camCounter) && pontos[i].ligadoCounter >= 1 && (i == mapa->whereami || pontos[i].ligado[pontos[i].guide] != caminho[camCounter-1]))  {
        camCounter++;
        pontos[i].guide++;
        i = pontos[i].ligado[pontos[i].guide-1];
      } else if (pontos[i].guide < pontos[i].ligadoCounter && pontos[i].ligado[pontos[i].guide] == caminho[camCounter-1]) { // segfault no camCounter quando for 0 e tals
        pontos[i].guide++;
      } else if (pontos[i].guide == pontos[i].ligadoCounter || pontos[i].ligado[pontos[i].guide] == mapa->whereami || existeNoVetor(caminho, pontos[i].ligado[pontos[i].guide], camCounter)) {

        if (caminho[camCounter] == mapa->whereami && pontos[mapa->whereami].guide == pontos[mapa->whereami].ligadoCounter)  {
          addCaminho(resultado, caminho, camCounter);
          pontos[i].guide++;
          continue;
        }
        addCaminho(resultado, caminho, camCounter+1);
        pontos[i].guide = 0;
        i = caminho[camCounter-1];
        camCounter--;

      }

  }

  return resultado;

}

// FILTRA FINAIS QUE POSSUEM UMA SAIDA, SALVANDO EM UM NOVO HEADER DE CAMINHOS
HEADER_CAMINHOS* filtradorDeCaminhos(MAPA *map, HEADER_CAMINHOS *caminhos)  {

  HEADER_CAMINHOS *novo = (HEADER_CAMINHOS*) calloc(1, sizeof(HEADER_CAMINHOS));
  CAMINHO_ENCONTRADO *pointer = caminhos->first;

  do {
    if ( map->pontos[pointer->vetor[pointer->caminhosPegados]].cor == 2) {
      addCaminho(novo, pointer->vetor, pointer->caminhosPegados+1);
    }
  } while(pointer->next && (pointer = pointer->next));

  // DA FREE NOS ANTIGOS CAMINHOS
  pointer = caminhos->first;
  while (pointer->next) {
    pointer = pointer->next;
    free(caminhos->first);
    caminhos->first = pointer;
  }
  free(pointer);
  free(caminhos);

  return novo;

}

// CALCULA O TAMANHO DO PERCURSO DO CAMINHO DADO
int calculaDistancia(MAPA *mapa, CAMINHO_ENCONTRADO *pointer)  {

  float distancia = 0;
  int i;

  for (i = 0; i < pointer->caminhosPegados; i++)  {
    distancia = distancia + sqrt(pow(mapa->pontos[pointer->vetor[i+1]].x-mapa->pontos[pointer->vetor[i]].x, 2) + pow(mapa->pontos[pointer->vetor[i]].y-mapa->pontos[pointer->vetor[i+1]].y, 2));
  }

  return distancia;

}

// VERIFICA SE O NUMERO EXISTE NO VETOR DADO
int existeNoVetor(int *vetor, int a, int tamanhoVetor) {

  int i;

  for (i = 0; i < tamanhoVetor; i++)  {
    if (vetor[i] == a)  {
      return 1;
    }
  }

  return 0;
}

// ORDENA OS CAMINHOS
void ordenaCaminhos(MAPA *mapa, HEADER_CAMINHOS **header) {

  int i, j;
  CAMINHO_ENCONTRADO *pointer = (*header)->first;
  CAMINHO_ENCONTRADO *aux = NULL;
  CAMINHO_ENCONTRADO *prev = NULL;

  // BUBBLE SORT VERSÃO LISTA SIMP ENCADEADA (TROCAS DE PARES ADJACENTES)
  for (i = 0; i < (*header)->caminhosAchados*500; i++)  {

    pointer = (*header)->first;
    aux = NULL;
    prev = NULL;
    while (pointer && pointer->next) {

      if (pointer->distancia > pointer->next->distancia || pointer->caminhosPegados+1 > pointer->next->caminhosPegados+1) {
        if (prev) {
          prev->next = pointer->next;
          aux = pointer->next->next;
          pointer->next->next = pointer;
          pointer->next = aux;

          if (prev->next == (*header)->last) (*header)->last = pointer;

          prev = prev->next;
        } else {

          prev = pointer;
          pointer = pointer->next;
          prev->next = pointer->next;
          pointer->next = prev;
          (*header)->first = pointer;

          prev = pointer;
          pointer = pointer->next;

        }
      } else if (pointer->distancia == pointer->next->distancia && pointer->caminhosPegados+1 == pointer->next->caminhosPegados+1) {

        j = 0;
        while (pointer->vetor[j] == pointer->next->vetor[j]) j++;
        if (pointer->vetor[j] > pointer->next->vetor[j])  {
          if (prev) {
            prev->next = pointer->next;
            aux = pointer->next->next;
            pointer->next->next = pointer;
            pointer->next = aux;

            if (prev->next == (*header)->last) (*header)->last = pointer;

            prev = prev->next;
          } else {

            prev = pointer;
            pointer = pointer->next;
            prev->next = pointer->next;
            pointer->next = prev;
            (*header)->first = pointer;

            prev = pointer;
            pointer = pointer->next;

          }
        } else {
          prev = pointer;
          pointer = pointer->next;
        }

      } else {

        prev = pointer;
        pointer = pointer->next;
      }

    }

  }

}

// ORDENA OS CAMINHOS PRA FORMATAR A SAIDA E PRINTA
void printCaminhos(MAPA *mapa, HEADER_CAMINHOS *header)  {

  ordenaCaminhos(mapa, &header);
  CAMINHO_ENCONTRADO *pointer = header->first;
  int i;

  do {
    printf("%d ", pointer->caminhosPegados+1);
    for (i = 0; i < pointer->caminhosPegados+1; i++)  {
      printf("%d ", (pointer->vetor[i] + 1));
    }
    printf("%d\n", calculaDistancia(mapa, pointer));
  } while(pointer->next && (pointer = pointer->next));

}

// FAZ O FREE EM TUDO
void freeAll(MAPA *mapa, HEADER_CAMINHOS *header)  {

  CAMINHO_ENCONTRADO *pointer = header->first;
  int i;

  while (pointer->next) {
    pointer = pointer->next;
    free(header->first);
    header->first = pointer;
  }
  free(pointer);
  free(header);

  for (i = 0; i < mapa->pontosCounter; i++) {
    free(mapa->pontos[i].ligado);
    free(mapa->pontos[i].ligadoVermelho);
  }
  free(mapa->pontos);
  free(mapa);


}
