#include <stdio.h>
#include <stdlib.h>

int *maxPA = NULL;
int sizeMaxPA = 0;

void orderSequence(int *, int);
void pushOnArray(int **, int *, int);
void getMaxPA(int *, int);

int startLongestAP() {		// funcao principal
	int size = 0, i = 0;
	printf("\t\nDigite o tamanho da sequencia: ");
	scanf("%d", &size);

	printf("\tDigite os %d elementos: ", size);
	int *seq = (int *) malloc(size * sizeof(int));	// sequencia original
	for (i = 0; i < size; i++)
		scanf("%d", &seq[i]);

	orderSequence(seq, size);

	getMaxPA(seq, size);		// gera e armazena a maior PA
	
	printf("\t\nSequencia: ");
	for(i = 0; i < sizeMaxPA; i++) 
		printf("%d ", maxPA[i]);

	printf("\t\nTotal: %d elementos\n", sizeMaxPA);

	free(maxPA);
	free(seq);

	return 0;
}

void orderSequence(int *seq, int size) {	// insertion sort
	int i = 0, j = 0, new = 0;
	for(i = 1; i < size; i++) {
		j = i;
		new = seq[i];
		while(j > 0 && new < seq[j-1]) {
			seq[j] = seq[j-1];
			j--;
		}
		seq[j] = new;
	}
}

void pushOnArray(int **myArray, int *sizeArray, int newValue) {	// adiciona valor no Array
	(*myArray) = (int *) realloc((*myArray), ((*sizeArray) + 1) * sizeof(int));
	(*myArray)[*sizeArray] = newValue;
	(*sizeArray)++;
}

void getMaxPA(int *seq, int size) {
	int i = 0, j = 0, k = 0, sizeTempPA = 0, currDiff = 0, tempDiff = 0;
	int *tempPA = NULL;
	
	for(i = 0; i < size; i++) {			// inicio da tentativa da PA
		for(j = i+1; j < size; j++) {	// define qual diff usar como razao da PA
			tempPA = NULL;		// PA temporaria
			sizeTempPA = 0;		// tamanho da PA temporaria
			pushOnArray(&tempPA, &sizeTempPA, seq[i]);
			pushOnArray(&tempPA, &sizeTempPA, seq[j]);
			currDiff = tempPA[1] - tempPA[0];	// razao da tempPA

			for(k = j+1; k < size; k++) {	// testa as possiveis PA
				tempDiff = seq[k] - tempPA[sizeTempPA-1];
				if(tempDiff > currDiff) break;	// nao pode ser PA daqui pra frente

				if(tempDiff == currDiff)
					pushOnArray(&tempPA, &sizeTempPA, seq[k]);
			}

			if(sizeTempPA > sizeMaxPA) {
				sizeMaxPA = sizeTempPA;
				maxPA = tempPA;
			}
		}
	}
}
