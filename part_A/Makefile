.PHONY: all
all: main1_1 main1_2 main1_3 lib

main1_1: hello_ariel.c hello_ariel.h main1_1.c
	gcc -o main1_1 hello_ariel.c main1_1.c

main1_2: hello_ariel.h main1_2.c lib
	gcc main1_2.c -L. -l Hello -o main1_2

main1_3: hello_ariel.h main1_2.c lib
	gcc main1_3.c -fPIC -ldl -o main1_3

lib:hello_ariel.h hello_ariel.c
	gcc -shared hello_ariel.c -fPIC -o libHello.so

.PHONY: clean
clean:
	-rm main1_1 main1_2 main1_3 libHello.so 2>/dev/null