# Gabriel Guimarães Vilas Boas Marin 11218521
all:	tudo
tudo:	biblio.o	main.o
				gcc	-o	final	biblio.o	main.o -lm -Wall -I.
run:
				./final
biblio.o:
				gcc	-o	biblio.o	-c	biblio.c -Wall -I.
main.o:
				gcc	-o	main.o	-c	main.c  -Wall -I.
clean:
				rm	-rf	*.o
delete:	clean
				rm	-rf	final
				rm -r zipado.zip
zip:
				zip zipado main.c biblio.c biblio.h Makefile
