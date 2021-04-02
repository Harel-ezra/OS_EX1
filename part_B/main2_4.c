#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#define STACK_SIZE 10000
#define CYCLES 1000
char child_stack[STACK_SIZE + 1];

void print(const char *text)
{
    for (int i = 0; i < 20; i++)
    {
        printf("hello from %s\n", text);
        usleep(1000000);
    }
}

void run_main1()
{

    char *args1[2] = {"./main2_1", NULL};
    execvp(args1[0], args1);
}
void run_main2()
{

    char *args2[2] = {"./main2_2", NULL};
    execvp(args2[0], args2);
}
void run_main3()
{
    char *args3[2] = {"./main2_3", NULL};
    execvp(args3[0], args3);
}

int main()
{
    clone(run_main1, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    clone(run_main2, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    clone(run_main3, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    return 0;
}