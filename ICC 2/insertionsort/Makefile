all:	ordenador
biblio.o:
				gcc-9	-o	biblio.o	-c	biblio.c	-Wall	-I.
insertion.o:
				gcc-9	-o	insertion.o	-c	insertion.c	-Wall	-I.
ordenador:	biblio.o	insertion.o
				gcc-9	-o	executa	biblio.o	insertion.o	-lm	-Wall	-I.
run:
				./executa
delete:
				rm	-rf	biblio.o	insertion.o	executa	zipado.zip
zip:
				zip	insertion	biblio.c	biblio.h	Makefile	insertion.c
