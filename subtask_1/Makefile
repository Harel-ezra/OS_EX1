CC=gcc
AR=AR
FLAGS= -Wall

all: main1_1

main1_1: main1_1.o hello_ariel.o
	$(CC) $(FLAGS) -o main1_1 main1_1.o hello_ariel.o

main1_1.o: main1_1.c  hello_ariel.h
	$(CC) $(FLAGS) -c main1_1.c 

hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -c hello_ariel.c 

clean:
	rm -f *.o *.a *.so *.out main1_1

.PHONY: clean all