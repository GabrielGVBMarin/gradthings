#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

int main(void)  {

    SUDOKU *sudokuToSolve = allocMat(16, 16);

    readMat(sudokuToSolve);
    sudokuSolve16X16(sudokuToSolve);
    printMat(sudokuToSolve, sudokuToSolve->solved);

    freeSudoku(sudokuToSolve);
    return 0;
}
