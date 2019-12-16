#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char* pega_Sobrenome(char *);
void adiciona_Sobrenome(char *, char *);

int main() {
	char **matriz_nomes = NULL;
	int numero_Nomes = 0;
  int tamanho_Nome = 0;

	// lendo o nome
	matriz_nomes = (char**) realloc(matriz_nomes, (numero_Nomes+1)*sizeof(char*));

	while  (1)  {
		char c;
		scanf("%c", &c);

		matriz_nomes[numero_Nomes] = (char*) realloc(matriz_nomes[numero_Nomes], (tamanho_Nome+1)*sizeof(char));

		if  (c == '$')  {

			matriz_nomes[numero_Nomes][tamanho_Nome++]='\0';
			tamanho_Nome = 0;
			numero_Nomes++;
			break;

    }
    else if  (c == '\n')  {

			matriz_nomes[numero_Nomes][tamanho_Nome++]='\0';
			tamanho_Nome = 0;
			numero_Nomes++;
			matriz_nomes = (char**) realloc(matriz_nomes, (numero_Nomes+1)*sizeof(char*));

    }
    else  {
			matriz_nomes[numero_Nomes][tamanho_Nome++] = c;
		}
	}
	//termina de ler o codigo

  // adiciona os sobrenomes
	for(int i = 1; i < numero_Nomes; i++)  {

		adiciona_Sobrenome(matriz_nomes[i], matriz_nomes[i-1]);

  }

  //printa o resultado
	for(int i = 0; i < numero_Nomes; i++)  {

		printf("%s\n", matriz_nomes[i]);

  }

	return 0;
}

char* pega_Sobrenome(char *nome) {
	int inicio = strlen(nome) - 1;
	for(; nome[inicio] != ' '; inicio--);

	char *sobrenome = NULL;
	int tamanho = 0;

	for(int i = inicio; i < strlen(nome); i++) {

		sobrenome = (char*) realloc(sobrenome, (tamanho+1)*sizeof(char));
		sobrenome[tamanho++] = nome[i];

	}

	sobrenome = (char*) realloc(sobrenome, (tamanho+1)*sizeof(char));
	sobrenome[tamanho] = '\0';

	nome = (char*) realloc(nome, (inicio+1)*sizeof(char));
	nome[inicio] = '\0';

	return sobrenome;
}

void adiciona_Sobrenome(char *nome_1, char *nome_2) {
	char *sobrenome_2 = pega_Sobrenome(nome_2);
	strcat(nome_1, sobrenome_2);
}
