all: codesolve

codesolve: codesolve.o
	cc codesolve.o -o codesolve

codesolve.o: codesolve.c
	cc -c codesolve.c -o codesolve.o

clean:
	rm -f *.o codesolve
