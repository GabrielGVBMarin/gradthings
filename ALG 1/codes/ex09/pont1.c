#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned char i; // stack (1 byte)
	int a; // stack (4 bytes)
	double *d; // stack (8 bytes)
	short ***s; // stack (8 bytes)
	int *p; // stack (8 bytes)
	char *c; // stack (8 bytes)

	a = 97; // 4 bytes

	// Intel (little endian)
	// 01100001
	// 00000000
	// 00000000
	// 00000000

	p = &a;

	printf("End de p: %p\n", &p);
	printf("Para onde p aponta: %p\n", p);
	printf("Va para onde p aponta: %d\n\n\n", *p);

	c = (char *) &a;
	for (i = 0; i < 4; i++, c++) {
		printf("Endereco de c %p\n", &c);
		printf("Conteudo (para onde aponta) de c %p\n", c);
		printf("Vah para onde c aponta %c  %d\n", *c, *c);
	}

	return 0;
}
