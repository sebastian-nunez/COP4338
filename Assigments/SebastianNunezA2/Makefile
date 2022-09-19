all: morgage

morgage: morgage.o
	cc morgage.o -o morgage

morgage.o: morgage.c
	cc -Wall -c morgage.c -o morgage.o

clean:
	rm -f *.o morgage
