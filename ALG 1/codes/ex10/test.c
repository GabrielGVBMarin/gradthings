/*
 	STACK
	|        |
	|        |
	|        |
	|        |
	|        |
	|        |
	----------
	|        | Endereço de retorno da função createUser
	|        |	--> printf("Hello World")
	|        |
	|        |
	|        |
	|        |
	|        |
	|        |
	----------
	|        | Copia USER *user para passar como parametro
	| 0xAABB |	para a função createUser
	|        |
	|        |
	|        |			heap
	|        |			----------
	|        |                      |        | 0xAABB
	|        |                      |        |
	----------                      |        |
	|        | User *user (8 bytes) | name   |
	| lixo   |                      |        |
	|        |                      | NULL   |
	|        |                      |        |
	|        |                      |        |
	|        |                      ----------
	|        |			|        |
	|        |                      |        |
	----------                      |        |
                                        | address|
                                        |        |
                                        | NULL   |
                                        |        |
                                        |        |
                                        ----------



*/
#include <stdlib.h>
#include <stdio.h>

struct user {
	char *name;
	char *address;
};

typedef struct user USER;

void createUser(USER *user) {
	user = (USER *) malloc(sizeof(USER));
	printf("%p\n", user);
	user->name = NULL;
	user->address = NULL;
}

int main(int argc, char *argv[]) {
	USER *user; // Stack (8 bytes)
	createUser(user);
	printf("Hello world %p\n", user);
	return 0;
}
