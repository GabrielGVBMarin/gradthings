#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct sudoku {
    char **base;
    char **solved;
    int cols, rows;
};
typedef struct sudoku SUDOKU;
// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

SUDOKU* allocMat(int c, int r);
void readMat(SUDOKU*);
void printMat(SUDOKU*, char**);
void sudokuSolve16X16(SUDOKU*);
char sudokuValueChooser(SUDOKU*, int, int);
int isSudokuSolved(SUDOKU*, char**);
void freeSudoku(SUDOKU*);

#endif
