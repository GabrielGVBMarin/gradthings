#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int ***p; // Stack (8 bytes)
	// int p[5][5][5]
	int i, j; // stack cada um com 4 bytes
	int pp[5]; // stack -> 5 * 4 bytes

	p = (int ***) malloc(sizeof(int **) * 5); // heap (40 bytes)
	/*
	p[0] = // int **
	p[1] = // int **
	p[2] = // int **
	p[3] = // int **
	p[4] = // int **
	*/

	for (i = 0; i < 5; i++) {
		*(p+i) = (int **) malloc(sizeof(int *) * 5);
		/* p[i] = (int **) 
			malloc(sizeof(int *) * 5); // heap (40 bytes)*/
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			p[i][j] = (int *) 
			  malloc(sizeof(int) * 5); // heap (20 bytes)
		}
	}

	return 0;
}
