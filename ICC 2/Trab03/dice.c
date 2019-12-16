#include <stdio.h>
#include <stdlib.h>

int sides = 0, diceCount = 0, sum = 0;	// informacoes dos dados
long possibilities = 0;			// numero de possibilidades
long *factorial;			// tabela de fatoriais
int *used;					// valore usados na PA (conta multiplicidades)

void setFactorial();
int getPossibilities(int, int, int);

int startDice() {			// funcao principal
	sides = diceCount = sum = possibilities = 0;
	printf("\tnQuantidade de dados: ");
	scanf("%d", &diceCount);
	printf("\tNumero de lados: ");
	scanf("%d", &sides);
	printf("\tSoma a ser obtida: ");
	scanf("%d", &sum);
	
	setFactorial();
	used = (int *) calloc(sides+1, sizeof(int));
	
	int i = 0;
	for(i = 1; i <= sides; i++) {
		used[i]++;
		getPossibilities(0, i, 0);
		used[i]--;
	}
	printf("\t\nHá %ld modo(s) de se obter %d lançando %d dados com %d lados\n\n", possibilities, sum, diceCount, sides);

	free(used);
	free(factorial);
	return 0;
}

void setFactorial() {						// preenche os fatoriais, para usa-los rapidadmente
	int lim = (sides > diceCount) ? sides : diceCount;	// pega o maior valor entre o maior lado e a quantidade de dados
	factorial = (long *) calloc(lim+1, sizeof(long));
	
	factorial[0] = 1;
	int i = 0;
	for(i = 1; i <= lim; i++)
		factorial[i] = factorial[i-1] * i;
}

int getPossibilities(int tempSum, int try, int tryCount) {
	tempSum += try;
	tryCount++;    
	
	if(tryCount > diceCount || tempSum > sum)	// caso base 1: se excedeu os dados ou excedeu a soma
		return 0;

	if(tryCount == diceCount && tempSum < sum)	// caso base 2: se usou todos os dados, mas nao chegou a soma
		return 0;

	if(tryCount < diceCount && tempSum == sum)	// caso base 3: nao usou todos os dados, mas somou
		return 0;
	
	int i = 0;
	if(tempSum == sum) {				// caso base 4: se chegou a soma
		long temp = factorial[tryCount];	// considera os casos em ordem diferente

		for(i = 1; i <= sides; i++)
			temp /= factorial[used[i]];	// divide, para evitar permutacoes do mesmo elemento
		possibilities += temp;

		return 1;
	}

	for(i = try; i <= sides; i++) {
		used[i]++;
		getPossibilities(tempSum, i, tryCount);
		used[i]--;
	}
	
	return 1;
}
