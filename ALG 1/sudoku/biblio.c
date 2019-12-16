// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <biblio.h>
#include <stdio.h>
#include <stdlib.h>

// ALOCA AS MATRIZES PARA O SUDOKU E INSERI O TAMANHO
SUDOKU* allocMat(int cols, int rows)   {

    int i;

    SUDOKU *sudo = (SUDOKU*) calloc(1, sizeof(SUDOKU));
    sudo->base = (char**) calloc(rows, sizeof(char*));
    for (i = 0; i < rows; i++)  {
        sudo->base[i] = (char*) calloc(cols, sizeof(char));
    }

    sudo->solved = (char**) calloc(rows, sizeof(char*));
    for (i = 0; i < rows; i++)  {
        sudo->solved[i] = (char*) calloc(cols, sizeof(char));
    }

    sudo->rows = rows;
    sudo->cols = cols;

    return sudo;
}

// FAZ A LEITURA DA MATRIZ BASE PARA O SUDOKU
void readMat(SUDOKU *sudoku)    {

    int i, j;

    for (i = 0; i < sudoku->rows; i++)  {
        for (j = 0; j < sudoku->cols; j++)  {
            scanf("%c ", &sudoku->base[i][j]);
            sudoku->solved[i][j] = sudoku->base[i][j];
        }
    }

}

// PRINTA A MATRIZ DO SUDOKU PASSADO NA REFERENCIA
void printMat(SUDOKU *sudoku, char **matrix)    {

    int i, j;

    for (i = 0; i < sudoku->rows; i++)  {
        for (j = 0; j < sudoku->cols; j++)  {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }


}

// VAI RESOLVENDO O SUDOKU ATÉ ESTAR PRONTO
void sudokuSolve16X16(SUDOKU *sudoku)   {

    int i, j;

    while (!isSudokuSolved(sudoku, sudoku->solved))    {

        for (i = 0; i < sudoku->rows; i++)  {
            for (j = 0; j < sudoku->cols; j++)  {
                if (sudoku->solved[i][j] == '.')    sudoku->solved[i][j] = sudokuValueChooser(sudoku, i, j);
            }
        }

    }


}

// ESCOLHE O VALOR CERTO PARA AQUELA POSIÇÃO NO SUDOKU SE EXISTIR
char sudokuValueChooser(SUDOKU *sudoku, int row, int col)   {

    int i, j, lowestValue = 0;
    char *character = (char*) calloc(2, sizeof(char));
    int *vectorReference = (int*) calloc(16, sizeof(int));
    int colBlockBegin = (col/4)*4;
    int rowBlockBegin = (row/4)*4;
    int flag = 0;

    // CONFERE A LINHA
    for (i = 0; i < sudoku->cols; i++)  {
        if (isdigit(sudoku->solved[row][i])) {
            vectorReference[sudoku->solved[row][i]-48]++;
        }   else if (sudoku->solved[row][i] != '.') vectorReference[sudoku->solved[row][i]-55]++;
    }

    // CONFERE A COLUNA
    for (i = 0; i < sudoku->rows; i++)  {
        if (isdigit(sudoku->solved[i][col])) {
            vectorReference[sudoku->solved[i][col]-48]++;
        } else if (sudoku->solved[i][col] != '.') vectorReference[sudoku->solved[i][col]-55]++;
    }

    // CONFERIR O BLOCO
    for (i = rowBlockBegin; i < rowBlockBegin+4; i++)  {
        for (j = colBlockBegin; j < colBlockBegin+4; j++)  {
            if (isdigit(sudoku->solved[i][j])) {
                vectorReference[sudoku->solved[i][j]-48]++;
            } else if (sudoku->solved[i][j] != '.') vectorReference[sudoku->solved[i][j]-55]++;
        }
    }

    // VERIFICA SE É ÚNICA
    for (i = 0; i < 16; i++)    {
        if (vectorReference[i] == 0)  {
            lowestValue = i;
            flag++;
        }
    }

    if (lowestValue >= 10)  {
        character[0] = (char) lowestValue+55;
    } else {
        character[0] = (char) lowestValue+48;
    }

    free(vectorReference);
    if (flag > 1 || flag == 0)   {
        return '.';
    } else {
        return character[0];
    }
}

// VERIFICA SE O SUDOKU JÁ ESTÁ RESOLVIDO
int isSudokuSolved(SUDOKU *sudoku, char **matrix)    {

    int i, j;

    for (i = 0; i < sudoku->rows; i++)  {
        for (j = 0; j < sudoku->cols; j++)  {
            if (matrix[i][j] == '.') return 0;
        }
    }

    return 1;
}

// DA O FREE NAS ALOCAÇÕES DO SUDOKU
void freeSudoku(SUDOKU *sudoku)  {

    int i;

    for (i = 0; i < sudoku->rows; i++)  {
        free(sudoku->base[i]);
    }
    free(sudoku->base);

    for (i = 0; i < sudoku->rows; i++)  {
        free(sudoku->solved[i]);
    }
    free(sudoku->solved);
    free(sudoku);
}
