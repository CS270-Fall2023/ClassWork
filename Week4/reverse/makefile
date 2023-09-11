reverse: main.o reverse.o
	gcc main.o reverse.o -o reverse

main.o: main.c reverse.h
	gcc -c main.c

reverse.o: reverse.c reverse.h
	gcc -c reverse.c

