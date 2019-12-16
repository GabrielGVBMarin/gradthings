#include <stdlib.h>
#include <stdio.h>

/*
struct Person {
	int code;
	char name[255];
	int age;
	char address[255];
};*/

struct Person {
	int code;
	char *name; // 8 b
	int age;
	char *address; // 8 b
};

struct Person *funcao() {
	// ...
}

int main(int argc, char *argv[]) {
	// 1.a declaracao
	struct Person p; // stack (4+255+4+255)

	// 2.a declaracao
	struct Person p; // stack (4+8+4+8)

	struct Person *p; // stack (8 bytes)

	int p[20]; // 20 * 4 bytes na Stack

	return 0;
}
