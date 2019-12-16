#include <stdlib.h>
#include <stdio.h>

int sum(int a, int b) {
	return a+b;
}

int main(int argc, char *argv[]) {
	int (*f) (int, int); // stack (8 bytes)

	f = &sum;

	printf("Endereco de f = %p\n", &f); // stack
	printf("Conteudo de f = %p\n", f);

	printf("Soma: %d", f(5,4));

	return 0;
}
