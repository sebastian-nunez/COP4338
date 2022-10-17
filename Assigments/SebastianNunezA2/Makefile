all: mortgagepmt

mortgagepmt: mortgagepmt.o
	cc -lm mortgagepmt.o -o mortgagepmt

mortgagepmt.o: mortgagepmt.c
	cc -c mortgagepmt.c -o mortgagepmt.o

clean:
	rm -f *.o mortgagepmt
