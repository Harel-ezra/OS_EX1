CC=gcc
AR=AR
FLAGS= -Wall

all: main1_2
	export LD_LIBRARY_PATH=.


main1_2: main1_2.o libHello.so
	$(CC) $(FLAGS) main1_2.o -L. -l Hello -o main1_2 

libHello.so: hello_ariel.c
	$(CC) -o libHello.so -shared -fPIC hello_ariel.c

main1_2.o: main1_2.c  hello_ariel.h
	$(CC) $(FLAGS) -c main1_2.c 

# hello_ariel.o: hello_ariel.c hello_ariel.h
# 	$(CC) $(FLAGS) -c hello_ariel.c 

clean:
	rm -f *.o *.a *.so *.out main1_2

.PHONY: clean all