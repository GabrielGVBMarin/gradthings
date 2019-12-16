all:
	gcc -o test test.c -I../includes -L../bin -llists

run:
	export LD_LIBRARY_PATH=../bin
	cp ../bin/liblists.so /usr/lib/
	./test
