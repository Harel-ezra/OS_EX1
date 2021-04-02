#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 20

char child_stack[STACK_SIZE + 1];

void print(const char *text)
{
    for (int i = 0; i < CYCLES; i++)
    {
        printf("hello from %s\n", text);
        usleep(1000000);
    }
}

int prosecc3(void *params)
{
    print("prosecc3 thread");
}

int prosecc2(void *params)
{
    print("prosecc2 thread");
}

int prosecc1(void *params)
{
    print("prosecc1 thread");
}
int main()
{
    clone(prosecc1, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    clone(prosecc2, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    clone(prosecc3, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    return 0;
}