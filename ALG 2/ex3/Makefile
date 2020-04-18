all: run

run: compile
	./bin
compile:
	gcc -c queries.c main.c
	gcc -o bin queries.o main.o
delete:
	rm bin alunos.dat index_prim.dat index_sec.dat queries.o main.o queriesheaders.o lista_invertida.dat