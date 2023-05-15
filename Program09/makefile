# Możliwe polecenia: make, make run, make clean, make tar
#
# Nazwa bieżącego katalogu: wynik wbudowanej funkcji notdir
KATBIEZ = $(notdir $(CURDIR))
# Nazwy rdzeniowe plików
GLOWNY = macierze
FUNKCJE = FunkcjeMacierzowe
# Nazwy plikow zrodlowych
GLOZRO = $(GLOWNY).c
FUNZRO = $(FUNKCJE).c
# Pliki skompilowane
GLOKOM = $(GLOWNY).o
FUNKOM = $(FUNKCJE).o
# Pliki naglówkowe
FUNNAG = $(FUNKCJE).h
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Plik danych
DANE = dane.txt
# Plik wynikow
WYNIKI = wyniki.txt

# Kompilator
KOMP = gcc
# Opcje kompilatora
KOMOP = -Wall –std=c99 –pedantic -c
# Linker
LINKER = gcc
# Opcje linkera
LINOP = -Wall –std=c99 -pedantic -o
# Regula all - będzie uruchamiana po wykonaniu make bez argumentów.
# Tu oznacza utworzenie pliku wykonawczego.
all: $(GLOWYK)
# Reguły dla kompilacji:
# 1. Plik z funkcjami
$(FUNKOM): $(FUNZRO)
	$(KOMP) $(KOMOP) $(FUNZRO)
# 2. Plik z programem glównym: zależy tez od pliku naglówkowego
$(GLOKOM): $(GLOZRO) $(FUNNAG)
	$(KOMP) $(KOMOP) $(GLOZRO)
# Reguła dla linkowania:
$(GLOWYK): $(GLOKOM) $(FUNKOM)
	$(LINKER) $(LINOP) $(GLOWYK) $(GLOKOM) $(FUNKOM)

# Reguła dla wykonania
run: $(GLOWYK)
	./$(GLOWYK) $(DANE) $(WYNIKI)
# Regula do czyszczenia katalogu
clean:
	rm -f a.out *~ *.o *.x
# Reguła do archiwizacji i kompresji:
# 1. Przejście do katalogu macierzystego (jeden poziom wstecz).
# 2. Archiwizacja z kompresją przy użyciu tar.
# 3. Wyświetlenie zawartości katalogu macierzystego.
# Zewnętrzne nawiasy ( ) sprawiaja wykonanie powyższych operacji
# w tymczasowo uruchomionej powłoce, po czym następuje powrót
# do pierwotnej powłoki.
tar: clean
	(cd ..; tar cvzf $(KATBIEZ).tar.gz $(KATBIEZ); ls -altr)