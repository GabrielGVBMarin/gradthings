#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int showMenu() {	// menu para as escolhas
	int option = 0;
	printf("\n======================\n");
	printf("|        MENU        |\n");
	printf("|1) Menor Palindromo |\n");
	printf("|2) Maior P.A.       |\n");
	printf("|3) Jogadas de Dados |\n");
	printf("|0) Sair do programa |\n");
	printf("======================\n");
	printf("Sua escolha: ")
	scanf("%d", &option);
	return option;
}

int main() {
	int option = showMenu();
	while(option) {
		switch(option) {
			case 1:			// Palindromo
				startPalindrome();
				break;
			case 2:			// Maior P.A.
				startLongestAP();
				break;
			case 3:			// Lancamento de dados
				startDice();
				break;
		}
		option = showMenu();
	}

	return 0;
}