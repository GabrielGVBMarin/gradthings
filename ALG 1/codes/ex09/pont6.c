#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	int (*f)(int, char *[]); // stack 8 bytes

	f = &main;

	printf("%p\n", &f);

	f(argc, argv);

	return 0;
}
