#include <stdio.h>
#include <stdlib.h>

void search_parent(int position) {
	if (position > 0) {
		int elem = (position - 1) / 2;
		search_parent(elem);
		printf("%d\n", position);
	}
}

int main(int argc, char *argv[]) {
	search_parent(5);
	return 0;
}
