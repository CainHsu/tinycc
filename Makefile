out: main.o
	gcc -o out main.o

main.o: main.c
	gcc -o main.o -c main.c

test:
	sh test.sh

clean:
	rm out *.o tmp*
