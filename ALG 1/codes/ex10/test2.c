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
	|        | Endereço de USER *user contido na main
	| 0xffbb |	
	|        |
	|        |
	|        |			heap
	|        |			----------
	|        |                      |        | 0xAABB
	|        |                      |        |
	----------                      |        |
0xffbb  |        | User *user (8 bytes) | name   |
	| 0xAABB |                      |        |
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

void createUser(USER **user) {
	*user = (USER *) malloc(sizeof(USER));
	printf("createUser\n");
	printf("**%p *%p\n", user, *user);
	(*user)->name = NULL;
	(*user)->address = NULL;
}

int main(int argc, char *argv[]) {
	USER *user; // Stack (8 bytes)
	createUser(&user);
	printf("Main\n");
	printf("User -> %p\n", user);
	printf("End User -> %p\n", &user);
	return 0;
}
