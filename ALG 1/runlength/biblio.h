// GABRIEL GUIMARAES VILAS BOAS MARIN 11218521
#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int** readMatrix(int*, int*, int*, char**);
int** compress(int**, int*, int*, int**);
int** unpack(int**, int*, int*);
void printCompressed(int**, int*, int*, int*, char*, int*);
void printUnpacked(int***, int*, int*, int*, char*);

#endif
