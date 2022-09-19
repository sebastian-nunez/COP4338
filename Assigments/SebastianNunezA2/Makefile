all: mortgagepmt

mortgagepmt: mortgagepmt.o
	cc mortgagepmt.o -o mortgagepmt

mortgagepmt.o: mortgagepmt.c
	cc -Wall -c mortgagepmt.c -o mortgagepmt.o

clean:
	rm -f *.o mortgagepmt
