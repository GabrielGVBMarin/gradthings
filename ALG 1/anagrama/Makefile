# Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
all:	tudo
run:
			./final
tudo:	biblio.o	main.o
				gcc	-o	final	biblio.o	main.o -lm -Wall -I.
biblio.o:
				gcc	-o	biblio.o	-c	biblio.c -Wall -I.
main.o:
				gcc	-o	main.o	-c	main.c  -Wall -I.
clean:
				rm	-rf	*.o
delete:	clean
				rm	-rf	final
				rm -r *.zip
zip:
				zip	zipado	Makefile	main.c	biblio.c	biblio.h
