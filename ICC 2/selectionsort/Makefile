all:	ordenador
biblio.o:
				gcc-9	-o	biblio.o	-c	biblio.c	-Wall	-I.
ordenadorselect.o:
				gcc-9	-o	ordenadorselect.o	-c	ordenadorselect.c	-Wall	-I.
ordenador:	biblio.o	ordenadorselect.o
				gcc-9	-o	executa	biblio.o	ordenadorselect.o	-lm	-Wall	-I.
run:
				./executa
delete:
				rm	-rf	biblio.o	ordenadorselect.o	executa
zip:
				zip selection biblio.h ordenadorselect.c biblio.c Makefile
