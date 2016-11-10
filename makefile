GCC = gcc -g

all: signals.o
	$(GCC) -o signals.out signals.o

signals.o: signals.c
	$(GCC) -c signals.c

run: signals.out
	./signals.out

clean:
	rm -f *~ *.out *.o
