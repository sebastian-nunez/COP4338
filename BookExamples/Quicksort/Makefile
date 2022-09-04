EXECUTABLE = quicksort.exe
UNLINKED_FILES = quicksort.o constants.o

build: $(UNLINKED_FILES)
	gcc $(UNLINKED_FILES) -o $(EXECUTABLE)

run:
	make build; clear; $(EXECUTABLE); make clean

quicksort.o: quicksort.c constants.c
	gcc -Wall -c quicksort.c

constants.o: constants.c
	gcc -Wall -c constants.c

clean:
	rm *.o $(EXECUTABLE)
