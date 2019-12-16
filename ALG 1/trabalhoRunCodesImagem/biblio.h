#ifndef _FUNC_
#define _FUNC_

#include <stdio.h>
#include <stdlib.h>

char* leNomeArquivo();
int** leImagem(FILE*, int*, int*);
char* leNumerosNaImagem(int**, int, int);
int checkBloco(int**, int, int);
int procuraNumero(int**, int*, int*, int, int);
char reconhecerNumero(int**, int, int);
char checkCombinations(int*);


#endif
