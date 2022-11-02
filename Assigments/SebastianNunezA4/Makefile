all: bitflip

bitflip: bitflip.o
	gcc bitflip.o -o bitflip

bitflip.o: bitflip.c
	gcc -c bitflip.c -o bitflip.o

clean:
	rm -f *.o bitflip
