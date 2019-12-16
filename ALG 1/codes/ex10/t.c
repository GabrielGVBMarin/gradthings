#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int *p = (int *) malloc(sizeof(int));
	printf("Conteudo de p = %p\n", p);
	free(p);
	printf("Conteudo de p = %p\n", p);

	return 0;
}
