#include <stdlib.h>
#include <stdio.h>

/*
 	|        |
 	|        |
 	|        |
 	|        |
 	|        |
 	|        |
 	|        |
	----------
 	|        | char *s2
 	|        |
 	|        |
 	| 0xaacc |
 	|        |
 	|        |
 	|        |			s2 = (char *) &s1
 	|        |			*((char *) *s2)
	----------
0xaacc 	|        | char *s1
 	|        |
 	| 0xffbb |
 	|        |
 	|        |
 	|        |
 	|        |
 	|        |
	----------
 */

int main(int argc, char *argv[]) {

	return 0;
}
