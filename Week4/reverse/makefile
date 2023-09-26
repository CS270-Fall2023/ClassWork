#Makros
CC= gcc
FLAGS = -Wall -g

# Pattern rule
%.o: %.c
	$(CC) $(FLAGS) -c $<

all: palindrome
clean:
	rm -f palindrome reverse *.o

palindrome: main2.o palindrome.o reverse.o 
	$(CC) $(FLAGS) $< palindrome.o reverse.o -o $@

main2.o: palindrome.h

palindrome.o: palindrome.h reverse.h

reverse: main.o reverse.o
	$(CC) $(FLAGS) $< reverse.o -o $@

main.o: reverse.h

reverse.o: reverse.h

