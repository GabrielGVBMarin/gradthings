#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	void *p;
	int i;

	p = malloc(sizeof(void) * 20);

	printf("Endereco de p = %p\n", &p);
	for (i = 0; i < 20; i++) {
		printf("Endereco contido em p = %p\n", p++);
	}
	printf("Endereco de p = %p\n", &p);

	return 0;
}
