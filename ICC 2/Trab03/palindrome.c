#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char * str); 
int __lowerPalindrome(char * str , char * lower);
int lowerPalindrome(char * str);

int startPalindrome() {
	char * str = (char *) malloc(sizeof(char));
	scanf("%s",str);
	lowerPalindrome(str);

	return 0;
}

int isPalindrome(char * str) {							// Retorna 1 caso a string for um palindromo e 0 se não for 
	int i, j;
	for(i = 0, j = strlen(str)-1; i <= j; i++, j--)	// i começa em 0 e cresce e j na ultima posição e decresce
		if(str[i] != str[j]) return 0;					// Se forem diferentes em algum ponto , não é um palíndromo
	
	return 1;
}

int __lowerPalindrome(char *str , char *lower) {
	int i;
	// STOP CONDITION	
	if(!strlen(str)) return 1;

	for(i = 0; i < strlen(str) ; i++) {
		if(isPalindrome(&str[i])) {
			strcat(lower, &str[i]);
			strcat(lower, " ");
			str[i] = '\0';
			__lowerPalindrome(str , lower);
		}
	}
}

int lowerPalindrome(char * str) {
	char * lower = (char *) malloc(sizeof(char));
	strcpy(lower , "");

	__lowerPalindrome(str , lower);
	int i;
	printf("\tDivisão palindrômica da palavra fornecida:\n\t");
	for(i = strlen(lower); i >= 0; i--)
		printf("%c", lower[i]);
	printf("\n");

	//Dando free
	free(lower);
	free(str);
}



