#	declaracao das regras, com seus requisitos e respectivamente seus codigos embaixo
all:	teste
run:
			./teste
teste:	teste.o	main.o
				gcc	-o	teste	teste.o	main.o -lm -Wall -I.
teste.o:	teste.c
				gcc	-o	teste.o	-c	teste.c -Wall -I.
main.o:
				gcc	-o	main.o	-c	main.c  -Wall -I.
clean:
				rm	-rf	*.o
delete:	clean
				rm	-rf	teste
				rm -r zipado.zip
zip:
	zip zipado Makefile main.c teste.c teste.h
