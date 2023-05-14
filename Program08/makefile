funWskTekst.o: funWskTekst.c
	gcc -Wall -std=c99 -pedantic -c funWskTekst.c

tekstwsk.o: tekstwsk.c
	gcc -Wall -std=c99 -pedantic -c tekstwsk.c

tekstwsk.x: tekstwsk.o funWskTekst.o
	gcc -Wall -std=c99 -pedantic -o tekstwsk.x tekstwsk.o funWskTekst.o

